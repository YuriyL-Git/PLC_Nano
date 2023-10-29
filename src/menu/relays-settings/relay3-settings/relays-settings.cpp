#include "lcd/lcd.h"
#include "menu/menu.h"
#include "settings/settings.h"
#include "encoder/encoder.h"

unsigned int MILLIS_IN_MINUTES = 60000;

void rl2OnIntervalHandler() {
  lcd.setCursor(0, 0);
  lcd.print("RL2 on int (min)");
  lcd.setCursor(1, 1);

  unsigned long onMinutesInterval = settings.rl2OnInterval/MILLIS_IN_MINUTES;
  lcd.print(onMinutesInterval);

  if (menuSettings.isSubMenuEdit) {
    if (encoder.left() && onMinutesInterval > 0) {
      onMinutesInterval--;
      settings.rl2OnInterval = onMinutesInterval * MILLIS_IN_MINUTES;
    }

    if (encoder.right() && onMinutesInterval < 200) {
      onMinutesInterval++;
      settings.rl2OnInterval = onMinutesInterval * MILLIS_IN_MINUTES;
    }
  }
}

void rl2offIntervalHandler() {
  lcd.setCursor(0, 0);
  lcd.print("RL2 off int (min)");
  lcd.setCursor(1, 1);


  unsigned long offMinutesInterval = settings.rl2OffInterval/MILLIS_IN_MINUTES;
  lcd.print(offMinutesInterval);

  if (menuSettings.isSubMenuEdit) {
    if (encoder.left() && offMinutesInterval > 0) {
      offMinutesInterval--;
      settings.rl2OffInterval = offMinutesInterval * MILLIS_IN_MINUTES;
    }

    if (encoder.right() && offMinutesInterval < 200) {
      offMinutesInterval++;
      settings.rl2OffInterval = offMinutesInterval * MILLIS_IN_MINUTES;
    }
  }
}

void saveAndExitRelaySettingsHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Save and Exit");
  if(encoder.click()) {
    saveSettings();
    exitSubMenu();
  }
}

void exitRelaySettingsHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Exit");
  if(encoder.click()) {
    getSettings();
    exitSubMenu();
  }
}