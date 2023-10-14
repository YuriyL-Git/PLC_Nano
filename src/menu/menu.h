struct MenuItem {
    char title[17];

    void (*callback)();
};

void renderMenu();