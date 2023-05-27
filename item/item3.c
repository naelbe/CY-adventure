#include "item.h"
#include "../system/sys.h"
#include <string.h>

struct it *constructItem3() {
  struct it *item3 = malloc(sizeof(struct it));
  strcpy(item3->itemName, "Bouclier de tank");
  strcpy(item3->itemDesc, "Objet de defense vous octroyant beaucoup d'armure !");
  item3->pv = 20;
  item3->ad = 10;
  item3->crit = 7;
  item3->arm = 5;
  item3->spd = 7;
  return item3;
}