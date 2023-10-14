#include <Arduino.h>
#include "settings/settings.h"

void setupBoard() {
  Serial.begin(9600);
  getSettings();
};