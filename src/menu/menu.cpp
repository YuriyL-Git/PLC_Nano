#include "settings/settings.h"
#include "encoder/encoder.h"
#include "lcd/lcd.h"
#include "time-settings/time-settings.h"
#include "menu/relays-settings/relay3-settings/relays-settings.h"
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

int mainMenuLength = sizeof(mainMenuItems) / sizeof(mainMenuItems[0]);

void renderMenu() {
  if (menuSettings.isSubMenu) {
    subMenuHandler();
  } else {
    mainMenuHandler();
  }

  if (encoder.turn() || encoder.click()) {
    lcd.clear();
    lcd.backlight();
    lcdBacklightTimePassed = millis();
    printDebugData();
  }

  if (isTimePassed(LCD_BACKLIGHT_TIMEOUT, &lcdBacklightTimePassed)) {
    lcd.noBacklight();
  }
}


void mainMenuHandler() {
  uint8_t subMenuLength = getMenuSubItems(menuSettings.mainMenuIndex).menuSubItemsLength;

  if (encoder.click() && subMenuLength > 0) {
    menuSettings.isSubMenu = true;
    initialTimeHandler();
  }

  if (encoder.left() && menuSettings.mainMenuIndex > 0) {
      menuSettings.mainMenuIndex--;
  }

  if (encoder.right() && menuSettings.mainMenuIndex < mainMenuLength - 1) {
      menuSettings.mainMenuIndex++;
  }

  mainMenuItems[menuSettings.mainMenuIndex].handlerFunc();
}

void subMenuHandler() {
  uint8_t subMenuLength = getMenuSubItems(menuSettings.mainMenuIndex).menuSubItemsLength;

  if (encoder.click()) {
    menuSettings.isSubMenuEdit = !menuSettings.isSubMenuEdit;
  }

  if (!menuSettings.isSubMenuEdit) {
    if (encoder.left() && menuSettings.subMenuIndex > 0) {
      menuSettings.subMenuIndex--;
    }

    if (encoder.right() && menuSettings.subMenuIndex < subMenuLength - 1) {
      menuSettings.subMenuIndex++;
    }
  }

  getMenuSubItems(menuSettings.mainMenuIndex).menuSubItems[menuSettings.subMenuIndex].handlerFunc();
}

MenuSubItem getMenuSubItems(int index) {
  MenuSubItem emptySubItem = {
          {},
          0
  };

  if (index == 0) {
    return emptySubItem;
  } else if (index == 1) {
    return {
            timeSettingsSubItems,
            sizeof(timeSettingsSubItems) / sizeof(timeSettingsSubItems[0])
    };
  }else if (index == 2) {
    return {
            relaySettingsSubItems,
            sizeof(relaySettingsSubItems) / sizeof(relaySettingsSubItems[0])
    };
  } else {
    return emptySubItem;
  }
}

void initialTimeHandler() {
  if (menuSettings.mainMenuIndex == 1) {
    Ds1302::DateTime now = getCurrentDateTime();
    settings.time.hour = now.hour;
    settings.time.minute = now.minute;
  }
}


void printDebugData() {
  Serial.println("menuSettings.mainMenuIndex: " + String(menuSettings.mainMenuIndex));
  Serial.println("menuSettings.subMenuIndex: " + String(menuSettings.subMenuIndex));
  Serial.println("menuSettings.isSubMenuEdit: " + String(menuSettings.isSubMenuEdit));
  Serial.println("menuSettings.isSubMenu: " + String(menuSettings.isSubMenu));
}



void exitSubMenu() {
  menuSettings.isSubMenuEdit = false;
  menuSettings.isSubMenu = false;
  menuSettings.mainMenuIndex = 0;
  menuSettings.subMenuIndex = 0;
}


