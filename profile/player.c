#include <string.h> 
#include "champ.h"
#include "../system/sys.h"

struct ch constructPlayer(char nameIn[20]) { 
struct ch player;
strcpy(player.name, nameIn);
player.pv = 400;
player.ad = 30;
player.ap = 0;        //initialise les stats du joueur avec un nom en parametre
player.crit = 10;
player.arm = 20;
player.spd = 7;
player.class = 0;  
  return player;  //retourne la structure du joueur
}
