#include "menu/menu.h"

void hourSettingHandler();

void minuteSettingHandler();

void saveAndExitTimeSettingsHandler();

void exitTimeSettingsHandler();

MenuItem timeSettingsSubItems[] = {
        {
                hourSettingHandler
        },
        {
                minuteSettingHandler
        },
        {
                saveAndExitTimeSettingsHandler
        },
        {
                exitTimeSettingsHandler
        }

};