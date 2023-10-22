#include "lcd/lcd.h"
#include "relay/relay.h"
#include "lcd/lcd.h"
#include "datetime/datetime.h"
#include "encoder/encoder.h"
#include "menu/menu.h"
#include "settings/settings.h"

unsigned long relayPrintStartTime = 0;

void mainScreenHandler() {

  if (isTimePassed(1000, &relayPrintStartTime)) {
    String time = getFormattedTime();

    lcd.setCursor(0, 0);
    lcd.print(time);
    lcd.print("     ");

    String relay1State = settings.isRelay1Enabled? "ON": "OFF";
    String relay2State = settings.isRelay2Enabled? "ON": "OFF";

    lcd.setCursor(0, 1);
    lcd.print("RL1:" + relay1State);
    lcd.print("  ");
    lcd.print("RL2:" + relay2State);
  }
}

void timeSettingsHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Time Settings");
}