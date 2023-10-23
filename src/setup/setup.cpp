#include <Arduino.h>
#include "settings/settings.h"
#include "lcd/lcd.h"
#include "datetime/datetime.h"
#include "encoder/encoder.h"
#include "relay/relay.h"
#include "GyverWDT.h"

void setupBoard() {
  Serial.begin(9600);

  lcd.init();
  rtc.init();

  setupRelays();
  setupEncoder();
  getSettings();
};