#include <Arduino.h>
#include "setup/setup.h"
#include "relay/relay.h"
#include "encoder/encoder.h"
#include "menu/menu.h"


void setup() {
  setupBoard();
}

void loop() {
  encoder.tick();
  renderMenu();
  handleRelays();
}
