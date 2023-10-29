#include "menu/menu.h"

void rl2OnIntervalHandler();

void rl2offIntervalHandler();

void saveAndExitRelaySettingsHandler();

void exitRelaySettingsHandler();

MenuItem relaySettingsSubItems[] = {
        {
                rl2OnIntervalHandler
        },
        {
                rl2offIntervalHandler
        },
        {
                saveAndExitRelaySettingsHandler
        },
        {
                exitRelaySettingsHandler
        }

};