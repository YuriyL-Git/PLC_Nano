void getSettings();

void saveSettings();

#ifndef SETTINGS_H
#define SETTINGS_H


struct Settings {
    int version;
    float temperature;
};

extern Settings settings;

#endif

