#include "item.h"
#include "../system/sys.h"
#include <string.h>
struct it *constructItem72() {
  
  struct it *item72 = malloc(sizeof(struct it));
  strcpy(item72->itemName, "Sort de chance puissance");
  strcpy(item72->itemDesc, "Cette potion augmentes tes chances ");
  item72->pv = 0;
  item72->ad = 0;
  item72->crit = 20;
  item72->arm = 0;
  item72->spd = 0;
  return item72;
}