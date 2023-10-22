#include "relay.h"
#include "definitions/definitions.h"
#include "datetime/datetime.h"
#include "settings/settings.h"


void setRelay(uint8_t relayNumber, bool isEnabled) {
  uint8_t relay = 0;

  if (relayNumber == 1) {
    relay = RL1_PIN;
  } else if (relayNumber == 2) {
    relay = RL2_PIN;
  }

  if (relay > 0) {
    digitalWrite(relay, isEnabled? LOW : HIGH);
  }
}

void handleRelays () {
  Ds1302::DateTime dateTime = getCurrentDateTime();
  uint8_t hour = dateTime.hour;

  if (hour >= 19 && hour <= 21) {
    settings.isRelay1Enabled = true;
    settings.isRelay2Enabled = true;

  } else if ((hour >= 1 && hour <= 3) || (hour >= 7 && hour <= 10) || (hour >= 14 && hour <= 17) ||
             (hour >= 21 && hour <= 23)) {


    settings.isRelay1Enabled = true;
    settings.isRelay2Enabled = false;
  } else {
    settings.isRelay1Enabled = false;
    settings.isRelay2Enabled = true;
  }


  setRelay(1, settings.isRelay1Enabled);
  setRelay(2, settings.isRelay2Enabled);
}

