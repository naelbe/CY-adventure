// Combat avec la sorcière qui annulera ses sorts sur les autres monstres
#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSC5_1(struct ch target)//tuer la soricere ou l'épargner?//elle cachait une entree dissimulee grace a une magie
{
  type("Bravo vous devenez de plus en plus fort, grace a la sorciere vous recuperez une potion\n");
  type("Soudain vous remarquez que les monstres a l'exterieur du chateau commencent peu a peu a reprendre leur forme humaine\n");
  sleep(2);
  type("D'un seul coup, en vous concentrant, vous remarquez que des fils tres fins menent vers un passage du chateau, et controlent ces prisonniers qui s'agitent dehors\n");
  sleep(2);
  type("Tapes sur [1] pour suivre les fils discretement\n Tapes sur [2] pour fuir ou\nTapes sur [3] pour sauvegarder"); 
  int i;
  i=readint(1,3);
  
  if(i==1){
    return 76;
  }

  else if(i==2){ 
   endLose(52);
   return 751;
  }
  else if(i==3){
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 751, filename);
    return 999;
  }
}


int eventSC5_1(struct ch target, struct mt monsterS)//combat avec elle, items?
{
 int a = fight(&target, &monsterS);

  if (a) {
    updateStats(&target,72); 
    printStats(target);
    return choiceSC5_1(target);
  }
    
  else {
    endLose(4);
    return 751;
  }
}

int descSC5_1(struct ch target)//description de la sorcière, elle augmente la rage et la puissance des zombies
{
  struct mt monsterS = constructMonsterSC3();
  type("Vous avancez dans l'escalier de gauche et se trouve en haut, une porte, que vous poussez.\n"); 
  type("Une aura pesante se degage de l'endroit ou vous etes...\n");
  sleep(2);
  type("Soudain, une Sorciere fait son apparition, et vous menace directement \n");
  type("(Decidemment ce chateau est rempli d'etres malefiques...)");
  sleep(2);
  type("'Bienvenue au repere du maitre Rakai, j'ai pu voir tes exploits a travers mes marionettes jeune chevalier'\n");
  type("'Tu ne dois pas etre comme tous ces faibles prisonniers si tu es parvenu jusque ici'\n");
  type("Cela veut dire qu'elle voit ces types, qui se sont fait ensorceles, comme des objets !!?\n");
  type("C'est une veritable ordure!");
  sleep(2);
  type("'Mais ta route s'acheve ici, epeiste !'\n");
  type("C'est ce que nous verrons !!!\n");
  sleep(1);
  type("Attention elle vous jette des sorts, esquivez du mieux que vous pouvez !!");
  sleep(1);
  return eventSC5_1(target, monsterS);
}
