#include "settings/settings.h"
#include "menu.h"

void testItemCallback() {
  settings.temperature = 11;
}


MenuItem menuItems[1] = {
        {
                "test",
                testItemCallback
        }
};

int menuItemIndex = 0;
int menuItemsLength = sizeof(menuItems) / sizeof(MenuItem);


void renderMenu() {
/*  ButtonsResult buttonsResult = readButtons();

  switch (buttonsResult.result) {
    case BtnRight: {
      if (menuItemIndex < menuItemsLength) {
        menuItemIndex++;
      };
      break;
    }
    case BtnLeft: {
      if (menuItemIndex > 0) {
        menuItemIndex--;
      }
      break;
    }
  }*/

  menuItems[menuItemIndex].callback();
}

