#include "item.h"
#include "../system/sys.h"
#include <string.h>

struct it *constructItem1() {
  struct it *item1 = malloc(sizeof(struct it)); //initialize dynamiquement les items
  strcpy(item1->itemName, "livre de mage");
  strcpy(item1->itemDesc, "livre vous octroyant les connaissances d'un mage puissant");
  item1->pv = 20;
  item1->ad = 10; //initialisation des stats diverses
  item1->crit = 7;
  item1->arm = 5;
  item1->spd = 7;
  return item1; //retourne un pointeur sur l'item
}
