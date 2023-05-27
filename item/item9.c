#include "item.h"
#include "../system/sys.h"
#include <string.h>

struct it *constructItem9() {
  
  struct it *item9 = malloc(sizeof(struct it));
  strcpy(item9->itemName, "Potion de malveillance");
  strcpy(item9->itemDesc, "'Potion cree par des mages pas tres adroits... peu de stats, mais c'est mieux que rien !'");
  item9->pv = 6;
  item9->ad = 3;
  item9->crit = 5;
  item9->arm = 0;
  item9->spd = 3;
  return item9;
}