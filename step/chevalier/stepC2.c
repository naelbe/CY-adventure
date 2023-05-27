//Combat avec le Dragon furieux qui bloque le passage
#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSC2(struct ch target)
{
  int i=0;
  
  type("Vous etes sur le point de sortir mais quelque chose vous fait revenir en arriere, un autre dragon dort tout proche de la sortie\n");
  type("En revanche votre discretion ne l'a pas reveillee, souhaitez vous en finir avec ce dernier pendant son sommeil?\n ");
  sleep(2);
  type("Ou preferez vous garder la sagesse comme Heuss vous l'a appris et terminer votre mission rapidement??\n ");
  sleep(3);
  type("Entrez [1] pour tenter de l'eliminer \n       [2] poursuivre l'aventure et pister Rakai\n      [3] pour sauvegarder\n");
  i=readint(1,3);
  if(i==1){
    endLose(5);
    return 72;
  }
  else if(i==2){
    return 73;
  }
  
  else if(i==3){
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 72, filename);
    return 999;
  }  
}


int eventSC2(struct ch target, struct mt monster2 )
{
  type("Tenez vous pret au combat...\n");
  type("Attention le Dragon arrive !! ");
  int rez= fight(&target, &monster2);
  if (rez){
    type("Bravo vous venez de vaincre\n");
    type("Votre bouclier a servi a vous protéger des flammes\n");
    printf(" %s\n", monster2.name);
    sleep(2);
    type("Vous venez de purifier le couloir sacre, l'esprit de maison vous offre une amelioration corporelle :");
    type("Potion d'amelioration corporelle !");
    updateStats(&target, 71); 
    printStats(target);
    choiceSC2(target); //choix vers la suite de l'aventure
  }
  else {
    type("Pas de chance, vous vous etes fait embroche par les griffes du Dragon...\n");
    sleep(2); 
    endLose(4);
    return(72);
  }
}


int descSC2(struct ch target)
{
  struct mt monster2 = constructMonsterSC2();
  type("Vous avancez dans le couloir et apercevez de la lumiere, serait-ce une sortie? \n");
  type("Mais plus vous etes proche de la sortie, plus une odeur est presente, celle de quelque chose qui brule !!");
  sleep(2);

  type("NON ENCORE UN MONSTRE !!\n");
  sleep(2);

  type("Cette fois vous la reconaissez c'est le Dragon du mont Gradur !!\n");
  return eventSC2(target, monster2);
}
