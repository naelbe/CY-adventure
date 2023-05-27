#include "item.h"
#include "../system/sys.h"
#include <string.h>
struct it *constructItem71() {
  
  struct it *item71 = malloc(sizeof(struct it));
  strcpy(item71->itemName, "Amelioration corporelle ");
  strcpy(item71->itemDesc, "La benediction de la maison t'offre de la vie supplementaire ");
  item71->pv = 45;
  item71->ad = 0;
  item71->crit = 0;
  item71->arm = 0;
  item71->spd = 6;
  return item71;
}