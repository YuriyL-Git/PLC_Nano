#include "lcd/lcd.h"
#include "menu/menu.h"

void hourSettingHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Hour setting");
}

void minuteSettingHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Minute setting");
}

void saveAndExitTimeSettingsHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Save and Exit");
}

void exitTimeSettingsHandler(){
  lcd.setCursor(1, 0);
  menuSettings.isSubMenu = false;
  lcd.print("Exit");
}

