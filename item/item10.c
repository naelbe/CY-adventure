#include "item.h"
#include "../system/sys.h"
#include <string.h>

struct it *constructItem10() {
  
  struct it *item10 = malloc(sizeof(struct it));
  strcpy(item10->itemName, "carte de l'emplacement de Rakai");
  strcpy(item10->itemDesc, "cette carte est un chemin vers la vengence");
  item10->pv = 0;
  item10->ad = 0;
  item10->crit = 0;
  item10->arm = 0;
  item10->spd = 5;
  return item10;
}