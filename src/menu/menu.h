#ifndef MENU_H
#define MENU_H


struct MenuSettings {
    uint8_t menuItemsLength;
    bool isSubMenu;
    bool isSubMenuEdit;
    uint8_t mainMenuIndex;
    uint8_t subMenuIndex;
    uint8_t menuSubItemsLength[];
};

extern MenuSettings menuSettings;
#endif

void renderMenu();