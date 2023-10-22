#include "settings/settings.h"
#include "encoder/encoder.h"
#include "lcd/lcd.h"
#include "time-settings/time-settings.h"
#include "main-menu/main-menu.h"
#include "menu.h"


void (*mainMenuItems[])() = {mainScreenHandler, timeSettingsHandler};


void (*timeSettingsSubItems[])() = {hourSettingHandler, minuteSettingHandler, saveAndExitTimeSettingsHandler, exitTimeSettingsHandler };

void (*menuSubItems[][10])() = {{}, {hourSettingHandler, minuteSettingHandler, saveAndExitTimeSettingsHandler, exitTimeSettingsHandler }};

// menuItemsLength and menuSubItemsLength should be updated manually!!
MenuSettings menuSettings = {
        2,
        false,
        false,
        0,
        1,
        {0,4}
};

void mainMenuEncoderHandler() {
  if (encoder.left()) {
    if (menuSettings.mainMenuIndex > 0) {
      menuSettings.mainMenuIndex--;
    }
  }

  if (encoder.right()) {
    if (menuSettings.mainMenuIndex < menuSettings.menuItemsLength - 1) {
      menuSettings.mainMenuIndex++;
    }
  }

  if (encoder.click() && menuSettings.menuSubItemsLength[menuSettings.mainMenuIndex] > 0) {
    menuSettings.isSubMenu = true;
  }
}

void subMenuEncoderHandler() {
  if (encoder.left()) {
    if (menuSettings.subMenuIndex > 0) {
      menuSettings.subMenuIndex--;
    }
  }

  if (encoder.right()) {
    if (menuSettings.subMenuIndex < menuSettings.menuSubItemsLength[menuSettings.mainMenuIndex] - 1) {
      menuSettings.subMenuIndex++;
    }
  }

/*  if (encoder.click() && menuSettings.menuSubItemsLength[menuSettings.mainMenuIndex] > 0) {
    menuSettings.isSubMenu = true;
  }*/
}


void renderMenu() {
  if (menuSettings.isSubMenu ) {
    subMenuEncoderHandler();
    menuSubItems[menuSettings.mainMenuIndex][menuSettings.subMenuIndex]();
  } else {
    mainMenuEncoderHandler();
    mainMenuItems[menuSettings.mainMenuIndex]();
  }

  if (encoder.turn() || encoder.click()) {
    lcd.clear();
  }
}

