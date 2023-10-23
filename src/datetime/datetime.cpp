#include <Ds1302.h>
#include <Arduino.h>
#include "lcd/lcd.h"

Ds1302 rtc(12, 13, 11);

void setDateTime(uint8_t year, Ds1302::MONTH month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second, Ds1302::DOW dow) {
  Ds1302::DateTime dt = {
          year,
          month,
          day,
          hour,
          minute,
          second,
          dow
  };
  rtc.setDateTime(&dt);
}

//returns only last two numbers of year!
Ds1302::DateTime getCurrentDateTime() {
  Ds1302::DateTime now;
  rtc.getDateTime(&now);

  return now;
};

String getFormattedTime() {
  Ds1302::DateTime now = getCurrentDateTime();
  String result = "";

  String stringHour = String(now.hour);
  String stringMinute = String(now.minute);
  String stringSecond = String(now.second);

  result = result + (now.hour > 9 ? stringHour: "0" + stringHour) + ":";
  result = result + (now.minute > 9 ? stringMinute: "0"  + stringMinute) + ":";
  result = result + (now.second > 9 ? stringSecond: "0"  + stringSecond);

  return result;
};

String getFormattedDate() {
  Ds1302::DateTime now = getCurrentDateTime();
  String result = "";

  String stringYear = String(now.year);
  String stringMonth = String(now.month);
  String stringDay = String(now.day);

  result = result + (now.day > 10 ? stringDay: "0"  + stringDay)+ ".";
  result = result + (now.month > 10 ? stringMonth: "0"  + stringMonth) + ".";
  result = result + "20" + stringYear;

  return result;
};

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


String getDay() {
  Ds1302::DateTime now = getCurrentDateTime();
  return  WeekDays[now.dow - 1];
}



bool isTimePassed(unsigned long time, unsigned long *startTime) {
  unsigned long currentTime = millis();
  bool result;


  if (startTime == 0) {
    *startTime = millis();
    result = false;
  } else if (currentTime - *startTime >= time) {
    result = true;
    *startTime = currentTime;
  } else {
    result = false;
  }

  return result;
}

unsigned long startClockTime = 0;

void printDateTime(){
  if (isTimePassed(1000, &startClockTime)) {
    lcd.clear();
    String time = getFormattedTime();
    String date = getFormattedDate();
    String day = getDay();
    lcd.print(time);
    lcd.print(" ");

    lcd.setCursor(0, 1);
    lcd.print(date);
    lcd.print(" ");
    lcd.print(day);
  }
}
