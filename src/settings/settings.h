#include <Arduino.h>

void getSettings();

void saveSettings();

#ifndef SETTINGS_H
#define SETTINGS_H

struct TimeSettings {
    uint8_t hour;
    uint8_t minute;
};


struct Settings {
    int version;
    bool isRelay1Enabled;
    bool isRelay2Enabled;
    TimeSettings time;
};

extern Settings settings;

#endif

