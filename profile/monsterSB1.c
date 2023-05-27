#include "monster.h"
#include <string.h>

struct mt constructMonsterSB1() {
  struct mt monsterSB1;
  strcpy(monsterSB1.name, "Molosse de Lave");
  strcpy(monsterSB1.desc,"Ce monstre ne fait pas beaucoup de degat mais il est tres resistant !");
  monsterSB1.pv = 400;
  monsterSB1.ad = 5;
 monsterSB1.arm = 25;
  monsterSB1.crit = 0;
  monsterSB1.spd = 10;
  return monsterSB1;
}
