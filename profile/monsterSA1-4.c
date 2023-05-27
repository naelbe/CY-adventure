#include <string.h>
#include "monster.h"

struct mt constructMonsterSA1_31() {
  struct mt monsterSA1_2_2;
  strcpy(monsterSA1_2_2.name, "jeune homme inconnu");
  strcpy(monsterSA1_2_2.desc, "ce jeune homme a l'air peu experimente, mais mefiez-vous des apparences.");
  // CES STATS SONT POUR TEST !!!!!A EQUILIBRER !!!!!!
  // au minimum 3-4 tour chacun de combat (fight();)
  monsterSA1_2_2.pv = 250;
  monsterSA1_2_2.ad = 18;
 monsterSA1_2_2.arm = 15;
  monsterSA1_2_2.crit = 15;
  monsterSA1_2_2.spd = 7;
  return monsterSA1_2_2;
}
