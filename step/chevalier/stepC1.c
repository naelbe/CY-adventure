//Combat avec Machoire d'acier
#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSC1(struct ch target)
{
  int i=0;
  
  type("Vous vous retrouvez face a trois portes blindees, malheureusement, par manque de force vous pouvez en enfoncer qu'une seule");
  type("Mais les trois passages revelent l'odeur de Rakai, ce qui est assez etrange");
  sleep(3);
  type("a vous de choisir laquelle enfoncer...\n");
  sleep(3);
  
  type("Entrez [1] pour la porte numero 1\n       [2] pour la porte numero 2\n      [3] pour la porte numero 3\n       et [4] pour sauvegarder ");
  i=readint(1,4);
  if(i==1){
    return 72;
  }
  else if(i==2){
    return 712;
  }

  else if(i==3){
    endLose(3);
    return 71;
  }
  else if(i==4){
	char filename[50];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 71, filename);
    return 999;
  }
}


int eventSC1(struct ch target, struct mt monster1 )
{
  type("Tenez vous pret au combat...\n");
  int rez=fight(&target, &monster1);
  if (rez){
    type("Bravo vous venez de vaincre");
    printf(" %s\n", monster1.name);
    type("Vous le fouillez, et parvenez a recuperer un objet :");
    type("sort de chance puissance !");
    updateStats(&target, 70); 
    printStats(target);
    choiceSC1(target); //choix vers la suite de l'aventure
  }
  else {
    type("Zut, Machoire d'Acier vous a vaincu, revenez plus fort... [retour debut ou step precedent ?]\n");
    sleep(2);
    endLose(4);
    return 71;
  }
}


int descSC1(struct ch target)
{
  struct mt monster1 = constructMonsterSC1();
  type("Vous venez d'arriver sur les lieux, vous levez la tete et  ...\n");
  type("...");
  printf("\n");
  type("NON UN MONSTRE !!\n");
  type("Il refuse de vous laisser acceder au couloir\n");
  return eventSC1(target, monster1);
}
