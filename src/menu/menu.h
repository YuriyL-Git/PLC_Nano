#ifndef MENU_H
#define MENU_H


struct MenuSettings {
    bool isSubMenu;
    bool isSubMenuEdit;
    uint8_t mainMenuIndex;
    uint8_t subMenuIndex;
};


typedef void (*FunctionPointer)();

struct MenuItem {
    FunctionPointer handlerFunc;
};

struct MenuSubItem  {
    MenuItem*  menuSubItems;
    int menuSubItemsLength;
};


extern MenuSettings menuSettings;
#endif




void renderMenu();
void subMenuHandler();
void mainMenuHandler();
void printDebugData();
void initialTimeHandler();
void exitSubMenu();

MenuSubItem getMenuSubItems(int index);