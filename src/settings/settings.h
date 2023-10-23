#include <Arduino.h>

void getSettings();

void saveSettings();

#ifndef SETTINGS_H
#define SETTINGS_H

struct TimeSettings {
    uint8_t hour;
    uint8_t minute;
};

struct RelaySettings {
    String relayName;
    uint8_t relayPin;
    bool isEnabled;
};


struct Settings {
    int version;
    bool isRelay1Enabled;
    bool isRelay2Enabled;
    uint8_t relaysQuantity;
    TimeSettings time;
    RelaySettings* relaySettings;
};

extern Settings settings;

#endif

