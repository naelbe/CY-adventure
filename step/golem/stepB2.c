#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"


int choiceSB2(struct ch target) {
  int i = 0;
  type("Vous etes maintenant equipe d'un nouvel objet, mais le chemin est encore long...\n");
  type("Sur le chemin vous croisez un jeune enfant, tout seul, il s'avance vers vous et vous fait un signe de la main pour que vous le suiviez\n Tapez (1) si vous decidez de le suivre ou tapez (2) si vous preferez suivre votre chemin ou (3) Sauvegarder\n");
    i = readint(1, 3);
  if (i == 1) {
      return 821;
  }
  else if ( i== 2) {
    return 822;
  }
   else if (i == 3) {
     char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 82, filename);
    return 999;
   }
}



int eventSB2(struct ch target, struct mt monster) {
  type("Tenez vous pret au combat...\n");
  int rez = fight(&target, &monster);
  if (rez) {
    type("Bravo, vous venez de vaincre");
    printf(" %s\n", monster.name);
    type("Vous le fouillez, et parvenez a recuperer un objet :  ");
    type("Potion de soin");
    updateStats(&target, 11);
    printStats(target);
    choiceSB2(target); // choix vers la suite de l'aventure
  } 
  else {
    endLose(16);
  }
}

int descSB2(struct ch target) {
  struct mt monster = constructMonsterSC2();
  type("Vous êtes dans le donjon 2\nVous venez d'arriver sur les lieux, vous levez la tete et   ...\n");
  type("...");
  printf("\n");

  type("Attention au monstre !!\n");
  type("il t'attaque\n");
  return eventSB2(target, monster);
}





