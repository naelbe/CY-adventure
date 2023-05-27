#include <string.h>
#include "monster.h"


struct mt constructMonsterSC2() 
{
  struct mt monsterSC2;
  strcpy(monsterSC2.name, "Dragon Furieux");
  strcpy(monsterSC2.desc, "Cet animal feroce est redoutable, son feu ardent et ses griffes font de lui un un vrai monstre, prenez garde ! ");

  monsterSC2.pv = 300;
  monsterSC2.ad = 15;
 monsterSC2.arm = 15;
  monsterSC2.crit = 10; 
  monsterSC2.spd = 7;

  return monsterSC2;
}
