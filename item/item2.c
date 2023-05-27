#include "item.h"
#include "../system/sys.h"
#include <string.h>

struct it *constructItem2() {
  struct it *item2 = malloc(sizeof(struct it));
  strcpy(item2->itemName, "Epee de chevalier");
  strcpy(item2->itemDesc, "Epee vous donnant un fort avantage au combat rapproche !");
  item2->pv = 20;
  item2->ad = 10;
  item2->crit = 7;
  item2->arm = 5;
  item2->spd = 7;
  return item2;
}
       