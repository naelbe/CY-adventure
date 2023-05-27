#include "item.h"
#include "../system/sys.h"
#include <string.h>
struct it *constructItem70() {
  
  struct it *item70 = malloc(sizeof(struct it));
  strcpy(item70->itemName, "Sort de chance puissance");
  strcpy(item70->itemDesc, "Cette potion augmentes tes chances de coup critique");
  item70->pv = 12;
  item70->ad = 4;
  item70->crit = 15;
  item70->arm = 3;
  item70->spd = 2;
  return item70;
}