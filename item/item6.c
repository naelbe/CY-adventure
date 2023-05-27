#include "item.h"
#include "../system/sys.h"
#include <string.h>
struct it *constructItem6() {
  struct it *item6 = malloc(sizeof(struct it));
  strcpy(item6->itemName, " Bouclier defensif ");
  strcpy(item6->itemDesc, "'Ce don augment votre bouclier fortement.'");
  item6->pv = 50;
  item6->ad = 0;
  item6->crit = 0;
  item6->arm = 20;
  item6->spd = 0;
  return item6;
}