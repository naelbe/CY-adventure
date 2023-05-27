#include <string.h>
#include "monster.h"


struct mt constructMonsterSC4() 
{
  struct mt monsterSC4;
  strcpy(monsterSC4.name, "Serviteur de Rakai");
  strcpy(monsterSC4.desc, "Ce monstre est robuste et impregne fortement l'odeur de son manipulateur");
  monsterSC4.pv = 280;
  monsterSC4.ad = 28;
 monsterSC4.arm = 20;
  monsterSC4.crit = 20; 
  monsterSC4.spd = 5;
  return monsterSC4;
}
