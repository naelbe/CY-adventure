#include <string.h>
#include "monster.h"

struct mt constructMonsterSA1_5() {
  struct mt monsterSA1_2;
  strcpy(monsterSA1_2.name, "Akashi");
  strcpy(monsterSA1_2.desc, "Grand general de l'armee de Rakai");
  // CES STATS SONT POUR TEST !!!!!A EQUILIBRER !!!!!!
  // au minimum 3-4 tour chacun de combat (fight();)
  monsterSA1_2.pv = 450;
  monsterSA1_2.ad = 15;
  monsterSA1_2.arm = 12;
  monsterSA1_2.crit = 40;
  monsterSA1_2.spd = 14;
  return monsterSA1_2;
}
