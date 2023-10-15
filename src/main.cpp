#include <Arduino.h>
#include "setup/setup.h"
#include "relay/relay.h"
#include "lcd/lcd.h"
#include "datetime/datetime.h"
#include "definitions/definitions.h"


/*const uint8_t ENCODER_PIN_A = 8;  // D8
const uint8_t ENCODER_PIN_B = 9;  // D9
const uint8_t ENCODER_PIN_BTN = 10;   // D10*/

int encoderPos = 0;
int lastEncoderPinB = LOW;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


void setup() {
  setupBoard();

  pinMode(ENCODER_PIN_A, INPUT_PULLUP);
  pinMode(ENCODER_PIN_B, INPUT_PULLUP);
  pinMode(ENCODER_PIN_BTN, INPUT_PULLUP);

}

void loop() {
  printDateTime();

  setRelay(1, true);
  setRelay(2, false);


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
