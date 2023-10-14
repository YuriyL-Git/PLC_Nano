#include <Arduino.h>
#include "setup/setup.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  setupBoard();
  lcd.init();

  lcd.print("iarduino.ru");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // set the LED on
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);  // set the LED off
  delay(1000);
}
