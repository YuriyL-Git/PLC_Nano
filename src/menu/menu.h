#ifndef MENU_H
#define MENU_H


struct MenuSettings {
    bool isSubMenu;
    bool isSubMenuEdit;
    uint8_t mainMenuIndex;
    uint8_t subMenuIndex;
};



extern MenuSettings menuSettings;
#endif


typedef void (*FunctionPointer)();

struct MenuItem {
    FunctionPointer handlerFunc;
};

struct MenuSubItem  {
    MenuItem*  menuSubItems;
    int menuSubItemsLength;
};

void renderMenu();
void exitSubMenu();

MenuSubItem getMenuSubItems(int index);