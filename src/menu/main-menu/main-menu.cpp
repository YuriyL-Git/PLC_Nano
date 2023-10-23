#include "lcd/lcd.h"
#include "relay/relay.h"
#include "lcd/lcd.h"
#include "datetime/datetime.h"
#include "encoder/encoder.h"
#include "menu/menu.h"
#include "settings/settings.h"

unsigned long relayPrintStartTime = 0;

void mainScreenHandler() {

  if (isTimePassed(300, &relayPrintStartTime)) {
    String time = getFormattedTime();

    lcd.setCursor(0, 0);
    lcd.print(time);
    lcd.print("     ");

    lcd.setCursor(0, 1);
    for (int i = 0; i < settings.relaysQuantity; ++i) {
      RelaySettings relaySettings = settings.relaySettings[i];
      String relayState = relaySettings.isEnabled? "ON": "OFF";
      lcd.print(relaySettings.relayName + ":" + relayState);
      lcd.print("  ");
    }
  }
}

void timeSettingsHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Time Settings");
}

void relay1SettingsHandler() {
  lcd.setCursor(1, 0);
  lcd.print("Relay 1 Settings");
};

void relay2SettingsHandler(){
  lcd.setCursor(1, 0);
  lcd.print("Relay 2 Settings");
}