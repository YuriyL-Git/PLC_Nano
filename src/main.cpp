#include <Arduino.h>
#include "setup/setup.h"
#include <LiquidCrystal_I2C.h>
#include <Ds1302.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Ds1302 rtc(12, 13, 11);


const static char* WeekDays[] =
        {
                "Monday",
                "Tuesday",
                "Wednesday",
                "Thursday",
                "Friday",
                "Saturday",
                "Sunday"
        };

void setup() {
  rtc.init();
  setupBoard();
  lcd.init();

 // lcd.print("iarduino.ru");
  pinMode(LED_BUILTIN, OUTPUT);


  if (false)
  {
    Serial.println("RTC is halted. Setting time...");

    Ds1302::DateTime dt = {
            .year = 12,
            .month = Ds1302::MONTH_SET,
            .day = 14,
            .hour = 19,
            .minute = 10,
            .second = 00,
            .dow = Ds1302::DOW_SAT
    };

    rtc.setDateTime(&dt);
  }
}

void loop() {
  //digitalWrite(LED_BUILTIN, HIGH);  // set the LED on

  Ds1302::DateTime now;
  rtc.getDateTime(&now);

  static uint8_t last_second = 0;
  if (last_second != now.second)
  {
    last_second = now.second;

    Serial.print("20");
    Serial.print(now.year);    // 00-99
    Serial.print('-');
    if (now.month < 10) Serial.print('0');
    Serial.print(now.month);   // 01-12
    Serial.print('-');
    if (now.day < 10) Serial.print('0');
    Serial.print(now.day);     // 01-31
    Serial.print(' ');
    Serial.print(WeekDays[now.dow - 1]); // 1-7
    Serial.print(' ');
    if (now.hour < 10) Serial.print('0');
    Serial.print(now.hour);    // 00-23
    Serial.print(':');
    if (now.minute < 10) Serial.print('0');
    Serial.print(now.minute);  // 00-59
    Serial.print(':');
    if (now.second < 10) Serial.print('0');
    Serial.print(now.second);  // 00-59
    Serial.println();


    lcd.clear();
    lcd.print( now.hour);
    lcd.print( ":");
    lcd.print( now.minute);
    lcd.print( ":");
    lcd.print( now.second);
  }


 // digitalWrite(LED_BUILTIN, LOW);  // set the LED off
 // delay(1000);
}
