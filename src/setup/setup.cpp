#include <Arduino.h>
#include "settings/settings.h"
#include "definitions/definitions.h"
#include "lcd/lcd.h"
#include "datetime/datetime.h"

void setupBoard() {
  Serial.begin(9600);
  lcd.init();
  rtc.init();

  pinMode(RL1_PIN, OUTPUT);
  pinMode(RL2_PIN, OUTPUT);

  pinMode(ENCODER_PIN_A, INPUT_PULLUP);
  pinMode(ENCODER_PIN_B, INPUT_PULLUP);
  pinMode(ENCODER_PIN_BTN, INPUT_PULLUP);

  getSettings();
  // setDateTime(23, Ds1302::MONTH_SET, 15 , 17, 31, 0, Ds1302::DOW_SUN);
};