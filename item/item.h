#ifndef ITEM_H
#define ITEM_H
// BESOIN DE 9 ITEM, 3 COMBATS PAR 3 CLASS
// 1-> livre de sorcier
// 2-> épee de chevalier
// 3 -> bouclier de golem 

#include <stdlib.h>

struct it {
  char itemName[60];
  char itemDesc[200];
  int pv;
  int ad;
  int ap;
  int crit;
  int arm;
  int spd;
};

extern struct it *constructItemT();
extern struct it *constructItem1();
extern struct it *constructItem4();
extern struct it *constructItem2();
extern struct it *constructItem3();
extern struct it *constructItem5();

#endif
