// fight avec le serviteur de Rakai
#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSC5(struct ch target)
{
  int i;
  
  type("Vous excellez au combat j'ai l'impression, vous venez de vaincre le serviteur le plus fidèle de Rakai\n");
  type("Ce monstre bloquait en fait un passage secret ou l'on peut emprunter deux escaliers differents\n");
  type("L'un mene a gauche l'autre a droite...\n");
  type("Faites votre choix");
  sleep(2);
  type("Appuyez sur [1] pour prendre l'escalier de gauche\n Appuyez sur [2] pour utiliser celui de droite ou \n Appuyez[3] pour sauvegarder");
  i=readint(1,3);
  if(i==1){
    return 751; //next step witch fight 
  }

  else if(i==2){ 
   return 752; // rencontre porte blindée 
  }

  else if(i==3){
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 75, filename);
    return 999;
  }
}


int eventSC5(struct ch target, struct mt monster7)
{
  type("Grace au Gardien de la Porte vous devenez plus fort et cela se ressent.\n Confiant, vous vous elancez a votre tour");
  sleep(2);
 int x = fight(&target, &monster7);
  if (x) {
    return choiceSC5(target);
  } 
  else { 
    endLose(4); 
    return 75; 
  }
}


int descSC5(struct ch target)
{
  struct mt monster7 = constructMonsterSC4();
  type("Vous venez de prendre la nouvelle epee et vous ressentez une energie similaire a celle rakai, et en pure en meme temps\n");
  type("Votre corps s'habitue et vous parvenez a manier votre nouvelle lame\n");
  sleep(2);
  type("L'energie degagee attire l'attention du monstre, attention !!\n");
  type("Il vous foudroire du regard avec ses yeux rouges et s'elance vers vous !");
  sleep(2);
  return eventSC5(target, monster7);
}
