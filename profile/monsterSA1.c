#include <string.h>
#include "monster.h"

struct mt constructMonsterSA1() {
  struct mt monsterSA1;
  strcpy(monsterSA1.name, "Monstre inconnu...");
  strcpy(monsterSA1.desc, "le premier monstre que vous rencontrez, une grande mais abordable epreuve");
  // CES STATS SONT POUR TEST !!!!!A EQUILIBRER !!!!!!
  // au minimum 3-4 tour chacun de combat (fight();)
  monsterSA1.pv = 210;
  monsterSA1.ad = 25  ;                                      //initialise les stats du monstre selon son role dans l'aventure.
  monsterSA1.crit = 12;
  monsterSA1.arm = 10;
  monsterSA1.spd = 7;
  return monsterSA1;                                                     //retourne le monstre (sa structure)
}
