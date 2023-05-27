#include "item.h"
#include "../system/sys.h"
#include <string.h>
struct it *constructItem5() {
  struct it *item5 = malloc(sizeof(struct it));
  strcpy(item5->itemName, "epee du soleil levant");
  strcpy(item5->itemDesc, "'Cet item vous confere des degats d'attaque, precieux en cas de combat desorganises.");
  item5->pv = 15;
  item5->ad = 12;
  item5->crit = 0;
  item5->arm = 0;
  item5->spd = 5;
  return item5;
}