#include <string.h>
#include "monster.h"


struct mt constructMonsterSC1() 
{
  struct mt monsterSC1;
  strcpy(monsterSC1.name, "Machoire d'acier");
  strcpy(monsterSC1.desc, "Attention ce monstre n'a pas l'air très resistant, mais ses dents ne sont pas rassurantes du tout !!");
  monsterSC1.pv = 200;
 monsterSC1.arm = 10;  
monsterSC1.ad = 28;
  monsterSC1.crit = 10; 
  monsterSC1.spd = 27;

  return monsterSC1;
}
