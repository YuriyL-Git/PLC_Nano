#include <Arduino.h>
#include "setup/setup.h"
#include "relay/relay.h"
#include "lcd/lcd.h"
#include "datetime/datetime.h"
#include "encoder/encoder.h"

unsigned long relayPrintStartTime = 0;

void setup() {
  setupBoard();
}

void loop() {
  encoder.tick();

 // printDateTime();
  if (encoder.turn()) {
    Serial.print("turn: dir ");
    Serial.print(encoder.dir());
    Serial.print(", fast ");
    Serial.print(encoder.fast());
    Serial.print(", hold ");
    Serial.print(encoder.pressing());
    Serial.print(", counter ");
    Serial.print(encoder.counter);
    Serial.print(", clicks ");
    Serial.println(encoder.getClicks());
  }

  if (encoder.left()) Serial.println("left");
  if (encoder.right()) Serial.println("right");
  if (encoder.leftH()) Serial.println("leftHold");
  if (encoder.rightH()) Serial.println("rightHold");

  if (encoder.press()) Serial.println("press");
  if (encoder.click()) Serial.println("click");


  Ds1302::DateTime dateTime = getCurrentDateTime();
  uint8_t hour = dateTime.hour;

  String relay1State = "";
  String relay2State = "";

  if (hour >= 19 && hour <= 21) {
    setRelay(1, true);
    setRelay(2, true);
    relay1State = "ON";
    relay2State = "ON";
  } else if ((hour >= 1 && hour <= 3) || (hour >= 7 && hour <= 10) || (hour >= 14 && hour <= 17) ||
             (hour >= 21 && hour <= 23)) {
    setRelay(1, true);
    setRelay(2, false);
    relay1State = "ON";
    relay2State = "OFF";
  } else {
    setRelay(1, false);
    setRelay(2, true);
    relay1State = "OFF";
    relay2State = "ON";
  }

  if (isTimePassed(1000, &relayPrintStartTime)) {
    String time = getFormattedTime();

    lcd.setCursor(0, 0);
    lcd.print(time);
    lcd.print("     ");

    lcd.setCursor(0, 1);
    lcd.print("RL1:" + relay1State);
    lcd.print("  ");
    lcd.print("RL2:" + relay2State);
  }
}
