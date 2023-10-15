#include <Arduino.h>
#include "setup/setup.h"
#include "relay/relay.h"
#include "lcd/lcd.h"
#include "datetime/datetime.h"
#include "definitions/definitions.h"


int encoderPos = 0;
int lastEncoderPinB = LOW;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
unsigned long relayPrintStartTime = 0;


void setup() {
  setupBoard();
}

void loop() {
 // printDateTime();



  Ds1302::DateTime dateTime = getCurrentDateTime();
  uint8_t hour = dateTime.hour;

  uint8_t relayEnabled = 0;


  if ((hour >= 1 && hour <= 3) || (hour >= 7 && hour <= 10) || (hour >= 14 && hour <= 17)|| (hour >= 21 && hour <= 23)) {
    setRelay(1, true);
    setRelay(2, false);
    relayEnabled = 1;

  } else {
    setRelay(1, false);
    setRelay(2, true);
    relayEnabled = 2;
  }

  if (isTimePassed(1000, &relayPrintStartTime)) {
    lcd.clear();
    lcd.print("Relay " + String(relayEnabled) + " enabled" );
  }




  /// encoder code
  int readingA = digitalRead(ENCODER_PIN_A);
  int readingB = digitalRead(ENCODER_PIN_B);
  int buttonState = digitalRead(ENCODER_PIN_BTN);

  if (readingA != lastEncoderPinB) {
    if (readingB != readingA) {
      encoderPos++;
    } else {
      encoderPos--;
    }
  }

  if (buttonState != lastButtonState) {
    if ((millis() - lastDebounceTime) > debounceDelay) {
      if (buttonState == LOW) {
        Serial.println("Button pressed");
      }
      lastDebounceTime = millis();
    }
  }

  lastEncoderPinB = readingA;
  lastButtonState = buttonState;

  // You can use 'encoderPos' for your desired action
  Serial.println("Encoder position: " + String(encoderPos));
}
