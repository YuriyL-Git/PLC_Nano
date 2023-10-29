#include <Arduino.h>
#include "settings.h"
#include <EEPROM.h>
#include "definitions/definitions.h"

RelaySettings relaySettings[] = {
        {
          "1",
          RL1_PIN,
          false
        },
        {
                "2",
                RL2_PIN,
                false
        },
        {
          "3",
                  RL3_PIN,
                  false
        }
};

uint8_t relaysQuantity = sizeof(relaySettings)/sizeof(relaySettings[0]);

unsigned int millisInMinute = 60000;

Settings settings = {
        // to update settings in eeprom, increase version number
        // for first initialization call saveSettings() in setup
        18,
        relaysQuantity,
        {
          1,
          1
        },
        1,
        6,
        relaySettings,

};

void saveSettings() {
  Serial.println("Settings saved to EEPROM");
  EEPROM.put(1, settings);
}

void getSettings() {
  Settings savedSettings;
  EEPROM.get(1, savedSettings);



  if (( isnan(savedSettings.version)  || savedSettings.version < settings.version  )) {
    Serial.println("Settings updated");
    saveSettings();
  } else {
    Serial.println("Settings received from EEPROM");
    settings = savedSettings;
  }
}

