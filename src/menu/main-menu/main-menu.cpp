#include "lcd/lcd.h"

void mainScreenHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Main Screen");
}

void timeSettingsHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Time Settings");
}