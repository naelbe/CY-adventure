#include <string.h>
#include "monster.h"


struct mt constructMonsterSC3() 
{
  struct mt monsterSC3;
  strcpy(monsterSC3.name, "Sorciere");
  strcpy(monsterSC3.desc, "Cette vilaine sorciere enrage ses sbirs !");
  monsterSC3.pv = 250;
  monsterSC3.ad = 16;
 monsterSC3.arm = 10;
  monsterSC3.crit = 30; 
  monsterSC3.spd = 15;
  return monsterSC3;
}
