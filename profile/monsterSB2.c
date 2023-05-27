#include "monster.h"
#include <string.h>

struct mt constructMonsterSB2() {
  struct mt monsterSB2;
  strcpy(monsterSB2.name, "Ra's al ghul");
  strcpy(monsterSB2.desc,"Ce monstre manipule ses victimes afin de les amener ou il veut, il peut prendre l'apparence de n'importe quel etre humain");
  monsterSB2.pv = 200;
  monsterSB2.ad = 12;
 monsterSB2.arm = 15;
  monsterSB2.crit = 8;
  monsterSB2.spd = 50;
  return monsterSB2;
}
