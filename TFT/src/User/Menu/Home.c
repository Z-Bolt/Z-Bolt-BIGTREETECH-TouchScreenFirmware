#include "Home.h"
#include "includes.h"

const MENUITEMS homeItems = {
  // title
  LABEL_HOME,
  // icon                          label
  {
    {ICON_HOME,                    LABEL_HOME},
    {ICON_X_HOME,                  LABEL_X},
    {ICON_Y_HOME,                  LABEL_Y},
    {ICON_Z_HOME,                  LABEL_Z},
    {ICON_BACKGROUND,              LABEL_BACKGROUND},
    {ICON_Z_DEC,                   LABEL_BED_UP},
    {ICON_Z_INC,                   LABEL_BED_DOWN},
    {ICON_BACK,                    LABEL_BACK},
  }
};

void menuHome(void)
{
  KEY_VALUES key_num = KEY_IDLE;

  menuDrawPage(&homeItems);

  while (MENU_IS(menuHome))
  {
    key_num = menuKeyGetValue();
    switch (key_num)
    {
      case KEY_ICON_0: storeCmd("G28\n");   break;
      case KEY_ICON_1: storeCmd("G28 X\n"); break;
      case KEY_ICON_2: storeCmd("G28 Y\n"); break;
      case KEY_ICON_3: storeCmd("G28 Z\n"); break;
      case KEY_ICON_5: storeCmd("G28 Z\n"); break;                  
      case KEY_ICON_6: storeCmd("G1 Z335 F1200\n"); break;
      case KEY_ICON_7: CLOSE_MENU();      break;
      default: break;
    }

    loopProcess();
  }
}
