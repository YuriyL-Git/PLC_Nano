#include "relay.h"
#include "definitions/definitions.h"
#include "datetime/datetime.h"
#include "settings/settings.h"

void setupRelays() {
  pinMode(RL1_PIN, OUTPUT);
  pinMode(RL2_PIN, OUTPUT);
}


void setRelay(uint8_t relayPin, bool isEnabled) {
  digitalWrite(relayPin, isEnabled? LOW : HIGH);
}

void handleRelays () {
  Ds1302::DateTime dateTime = getCurrentDateTime();
  uint8_t hour = dateTime.hour;

  if (hour >= 19 && hour <= 21) {
    settings.relaySettings[0].isEnabled = true;
    settings.relaySettings[1].isEnabled = true;

  } else if ((hour >= 1 && hour <= 3) || (hour >= 7 && hour <= 10) || (hour >= 14 && hour <= 17) ||
             (hour >= 21 && hour <= 23)) {


    settings.relaySettings[0].isEnabled = true;
    settings.relaySettings[1].isEnabled = false;
  } else {
    settings.relaySettings[0].isEnabled = false;
    settings.relaySettings[1].isEnabled = true;
  }

  for (int i = 0; i < settings.relaysQuantity; ++i) {
    RelaySettings relaySettings = settings.relaySettings[i];
    setRelay(relaySettings.relayPin, relaySettings.isEnabled);
  }
}

