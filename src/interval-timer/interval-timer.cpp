#include "interval-timer.h"
#include "datetime/datetime.h"


void intervalTimer(unsigned long *startTime, unsigned long onInterval, unsigned long offInterval, bool *switchVariable) {
  if (onInterval > 0 && offInterval > 0) {
    if (*switchVariable) {
      if (isTimePassed(onInterval, startTime)) {
        *switchVariable = false;
      }
    } else {
      if (isTimePassed(offInterval, startTime)) {
        *switchVariable = true;
      }
    }
  }
}
