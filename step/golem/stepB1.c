#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"


int choiceSB1(struct ch target) {
  int i = 0;
  type("Vous etes maintenant equipe d'un nouvel objet, mais le chemin est encore long...\n");
  type("Sur le chemin vous rencontrez une famille en danger car un monstre est sur le point de les attaquer, appuyer sur (1) si vous decidez de la sauver, (2) si vous passez votre chemin ou (3) Sauvegarder\n");
  i = readint(1, 3);
 char filename[30];
  switch (i) {
  case 1:
    type("tu as decide de sauver la famille, tu es un guerrier courageux! Maintenant tu dois combattre un nouveau monstre\n");
    return 811;
    break;
  case 2:
    endLose(21);
    return 81;
    break;
  case 3:
    
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 81, filename);
    return 999;
    break;
  }
}


int eventSB1(struct ch target, struct mt monster) {
  type("Tenez vous pret au combat...\n");
  int rez = fight(&target, &monster);
  if (rez) {
    type("Bravo, vous venez de vaincre");
    printf(" %s\n", monster.name);
    type("Vous le fouillez, et parvenez a recuperer un objet :  ");
    type("Potion de soin ");
    updateStats(&target, 11);
    printStats(target);
    choiceSB1(target); // choix vers la suite de l'aventure
  } 
  else {
    endLose(16);
  }
}



int descSB1(struct ch target) {
  struct mt monster = constructMonsterSB1();
  type("Vous êtes dans le donjon 1\nVous venez d'arriver sur les lieux, vous levez la tete et   ...\n");
  type("...");
  printf("\n");
  type("Attention au monstre !!\n");
  type("il t'attaque\n");
  return eventSB1(target, monster);
}
