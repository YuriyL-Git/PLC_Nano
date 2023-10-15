#include <Ds1302.h>
#include <Arduino.h>

#ifndef DATETIME
#define DATETIME


extern Ds1302 rtc;

#endif

void setDateTime(uint8_t year, Ds1302::MONTH month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second,
                 Ds1302::DOW dow);

Ds1302::DateTime getCurrentDateTime();

String getFormattedTime();

String getFormattedDate();

String getDay();

void printDateTime();

bool isTimePassed(unsigned long time, unsigned long *startTime);