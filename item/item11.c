#include "item.h"
#include "../system/sys.h"
#include <string.h>
struct it *constructItem11() {
  
  struct it *item11 = malloc(sizeof(struct it));
  strcpy(item11->itemName, "Potion de PV");
  strcpy(item11->itemDesc, "cette potion te fait gagner de la vie");
  item11->pv = 40;
  item11->ad = 0;
  item11->crit = 0;
  item11->arm = 0;
  item11->spd = 0;
  return item11;
}