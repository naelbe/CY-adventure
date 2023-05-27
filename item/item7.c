#include "item.h"
#include "../system/sys.h"
#include <string.h>
struct it *constructItem7() {
  

  struct it *item7 = malloc(sizeof(struct it));
  strcpy(item7->itemName, "Karma des dieux");
  strcpy(item7->itemDesc, "'Objet conéféré uniquement aux plus courageux des guerries, pour vaincre le plus dangereux des adversaires'");
  item7->pv = 200;
  item7->ad = 20;
  item7->crit = 25;
  item7->arm = 4;
  item7->spd = 0;
  return item7;
}
