#include <Arduino.h>
#include "settings/settings.h"
#include "definitions/definitions.h"

void setupBoard() {
  Serial.begin(9600);

  pinMode(RL1_PIN, OUTPUT);
  pinMode(RL2_PIN, OUTPUT);
  getSettings();
};