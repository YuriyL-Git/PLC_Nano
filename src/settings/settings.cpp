#include <Arduino.h>
#include "settings.h"
#include <EEPROM.h>



Settings settings = {
        // to update settings in eeprom, increase version number
        // for first initialization call saveSettings() in setup
        3,
        false,
        false,
        {
          1,
          1
        }
};

void saveSettings() {
  Serial.println("Settings saved to EEPROM");
  EEPROM.put(1, settings);
}

void getSettings() {
  Settings savedSettings;
  EEPROM.get(1, savedSettings);

  if ((savedSettings.version < settings.version)) {
    Serial.println("Settings updated");
    saveSettings();
  } else {
    Serial.println("Settings received from EEPROM");
    settings = savedSettings;
  }
}

