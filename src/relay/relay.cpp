#include "relay.h"
#include "definitions/definitions.h"


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

