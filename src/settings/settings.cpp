#include <Arduino.h>
#include "settings.h"
#include <EEPROM.h>
#include "definitions/definitions.h"

RelaySettings relaySettings[] = {
        {
          "RL1",
          RL1_PIN,
          false
        },
        {
                "RL2",
                RL2_PIN,
                false
        }
};

uint8_t relaysQuantity = sizeof(relaySettings)/sizeof(relaySettings[0]);



Settings settings = {
        // to update settings in eeprom, increase version number
        // for first initialization call saveSettings() in setup
        5,
        false,
        false,
        relaysQuantity,
        {
          1,
          1
        },
        relaySettings
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

