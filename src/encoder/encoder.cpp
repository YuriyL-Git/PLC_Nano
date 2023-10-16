#include <EncButton.h>
#include "definitions/definitions.h"

EncButton encoder(ENCODER_PIN_A, ENCODER_PIN_B, ENCODER_PIN_BTN);

void setupEncoder() {
  encoder.setBtnLevel(LOW);
  encoder.setClickTimeout(500);
  encoder.setDebTimeout(50);
  encoder.setHoldTimeout(600);
  encoder.setStepTimeout(200);

  encoder.setEncReverse(0);
  encoder.setEncType(EB_STEP4_LOW);
  encoder.setFastTimeout(30);

  // сбросить счётчик энкодера
  encoder.counter = 0;
};
