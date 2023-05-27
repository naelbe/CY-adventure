#include "item.h"
#include "../system/sys.h"
#include <string.h>
struct it *constructItem4() {
  struct it *item4 = malloc(sizeof(struct it));
  strcpy(item4->itemName, "Relique de feu");
  strcpy(item4->itemDesc, "une puissante relique qui vous donnera de la puissance ainsi que de la resistance");
  item4->pv = 40;
  item4->ad = 12;
  item4->crit = 0;
  item4->arm = 3;
  item4->spd = 2;
  return item4;
}
//GAB