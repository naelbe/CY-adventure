#include <string.h>
#include "monster.h"

struct mt constructMonsterSA1_6() {
  struct mt monsterSA1_2_1;
  strcpy(monsterSA1_2_1.name, "Haut grade de l'armee de Rakai");
  strcpy(monsterSA1_2_1.desc, "Les grades de l'armee sont tres puissants prend garde !");
  // CES STATS SONT POUR TEST !!!!!A EQUILIBRER !!!!!!
  // au minimum 3-4 tour chacun de combat (fight();)
  monsterSA1_2_1.pv = 250;
  monsterSA1_2_1.ad = 14;
 monsterSA1_2_1.arm = 10;
  monsterSA1_2_1.crit = 15;
  monsterSA1_2_1.spd = 5;
  return monsterSA1_2_1;
}
