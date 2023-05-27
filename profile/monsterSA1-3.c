#include <string.h>
#include "monster.h"

struct mt constructMonsterSA1_4() {
  struct mt monsterSA1_3_1;
  strcpy(monsterSA1_3_1.name, "Rakai");
  strcpy(monsterSA1_3_1.desc, "Votre grand ennemi, le plus puissant !");
  // CES STATS SONT POUR TEST !!!!!A EQUILIBRER !!!!!!
  // au minimum 3-4 tour chacun de combat (fight();)
  monsterSA1_3_1.pv = 500;
  monsterSA1_3_1.ad = 20;
  monsterSA1_3_1.crit = 45;
  monsterSA1_3_1.spd = 6;
  return monsterSA1_3_1;
}
