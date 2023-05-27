#include "item.h"
#include "../system/sys.h"
#include <string.h>

struct it *constructItem8() {
  
  struct it *item8 = malloc(sizeof(struct it));
  strcpy(item8->itemName, "Potion de transformation");
  strcpy(item8->itemDesc, "'Objet destine aux combattants determines et pret a tout : vous enleve des pv en echange d'attaque'");
  item8->pv = -60;
  item8->ad = 30;
  item8->crit = 0;
  item8->arm = 0;
  item8->spd = 0;
  return item8;
}
