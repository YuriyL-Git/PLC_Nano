#include "settings/settings.h"
#include "encoder/encoder.h"
#include "lcd/lcd.h"
#include "time-settings/time-settings.h"
#include "main-menu/main-menu.h"
#include "menu.h"
#include "datetime/datetime.h"

int LCD_BACKLIGHT_TIMEOUT = 5000;
unsigned long lcdBacklightTimePassed = 0;

MenuSettings menuSettings = {
        false,
        false,
        0,
        0,
};


MenuItem mainMenuItems[] = {
        {
                mainScreenHandler
        },
        {
                timeSettingsHandler
        },
        {
                relay1SettingsHandler
        },
        {
                relay2SettingsHandler
        },

};

MenuItem mainScreenSubItems[] = {};


MenuItem timeSettingsSubItems[] = {
        {
                hourSettingHandler
        },
        {
                minuteSettingHandler
        },
        {
                saveAndExitTimeSettingsHandler
        },
        {
                exitTimeSettingsHandler
        }

};


MenuSubItem getMenuSubItems(int index) {
  if (index == 0) {
    return {
            mainScreenSubItems,
            sizeof(mainScreenSubItems) / sizeof(mainScreenSubItems[0])
    };
  } else {
    return {
            timeSettingsSubItems,
            sizeof(timeSettingsSubItems) / sizeof(timeSettingsSubItems[0])
    };
  }
}


void mainMenuEncoderHandler() {
  int mainMenuLength = sizeof(mainMenuItems) / sizeof(mainMenuItems[0]);

  if (encoder.left()) {
    if (menuSettings.mainMenuIndex > 0) {
      menuSettings.mainMenuIndex--;
    }

  }

  if (encoder.right()) {
    if (menuSettings.mainMenuIndex < mainMenuLength - 1) {
      menuSettings.mainMenuIndex++;
    }
  }

  uint8_t subMenuLength = getMenuSubItems(menuSettings.mainMenuIndex).menuSubItemsLength;

  if (encoder.click() && subMenuLength > 0) {
    menuSettings.isSubMenu = true;
  }
}

void subMenuEncoderHandler() {
  if (encoder.left() && menuSettings.subMenuIndex > 0) {
      menuSettings.subMenuIndex--;
  }

  uint8_t subMenuLength = getMenuSubItems(menuSettings.mainMenuIndex).menuSubItemsLength;


  if (encoder.right() && menuSettings.subMenuIndex < subMenuLength - 1) {
      menuSettings.subMenuIndex++;
  }
}

void renderMenu() {
  if (menuSettings.isSubMenu) {
    if (encoder.click()) {
      menuSettings.isSubMenuEdit = !menuSettings.isSubMenuEdit;
    }

    getMenuSubItems(menuSettings.mainMenuIndex).menuSubItems[menuSettings.subMenuIndex].handlerFunc();
    if (!menuSettings.isSubMenuEdit) {
      subMenuEncoderHandler();
    }

  } else {
    mainMenuEncoderHandler();
    mainMenuItems[menuSettings.mainMenuIndex].handlerFunc();
  }



  if (encoder.turn() || encoder.click()) {
    lcd.clear();
    lcd.backlight();
    lcdBacklightTimePassed = millis();

    Serial.println("menuSettings.mainMenuIndex: " + String(menuSettings.mainMenuIndex));
    Serial.println("menuSettings.subMenuIndex: " + String(menuSettings.subMenuIndex));
    Serial.println("menuSettings.isSubMenuEdit: " + String(menuSettings.isSubMenuEdit));
    Serial.println("menuSettings.isSubMenu: " + String(menuSettings.isSubMenu));

  }

  if (isTimePassed(LCD_BACKLIGHT_TIMEOUT, &lcdBacklightTimePassed)) {
    lcd.noBacklight();
  }
}


void exitSubMenu() {
  menuSettings.isSubMenuEdit = false;
  menuSettings.isSubMenu = false;
  menuSettings.mainMenuIndex = 0;
  menuSettings.subMenuIndex = 0;
}


