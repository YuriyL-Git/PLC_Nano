#include "lcd/lcd.h"
#include "menu/menu.h"
#include "settings/settings.h"
#include "encoder/encoder.h"
#include "datetime/datetime.h"

void hourSettingHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Hour setting");
  lcd.setCursor(1, 1);
  lcd.print(settings.time.hour);

  if (menuSettings.isSubMenuEdit) {
    if (encoder.left() && settings.time.hour > 0) {
      settings.time.hour--;
    }

    if (encoder.right() && settings.time.hour < 24) {
      settings.time.hour++;
    }
  }
}

void minuteSettingHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Minute setting");
  lcd.setCursor(1, 1);
  lcd.print(settings.time.minute);

  if (menuSettings.isSubMenuEdit) {
    if (encoder.left() && settings.time.minute > 0) {
      settings.time.minute--;
    }

    if (encoder.right() && settings.time.minute < 60) {
      settings.time.minute++;
    }
  }
}

void saveAndExitTimeSettingsHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Save and Exit");
  if(encoder.click()) {
    setDateTime(23, Ds1302::MONTH_SET, 15 , settings.time.hour, settings.time.minute, 0, Ds1302::DOW_SUN);
    exitSubMenu();
  }
}

void exitTimeSettingsHandler(){
  lcd.setCursor(1, 0);
  lcd.print("Exit");
  if(encoder.click()) {
    exitSubMenu();
  }
}





