#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSB1_1_1(struct ch target) {
  int i = 0;
  type("Vous etes maintenant equipe d'une carte qui indique la position de Rakai\n");
  type("Souhaitez vous suivre la carte vers racaille afin de vous venger ? tapez (1) si vous suivez la carte et (2) si vous preferez continuer seul sans carte\n");
  i = readint(1, 3);
   char filename[30];
  switch (i) {
  case 1:
    type("tu as decide de suivre la carte!\n");
    return 83;
    break;
  case 2:
    endLose(20);
    return 8111;
    break;
  case 3:
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 8111, filename);
    return 999;
    break;
  }
}
  

int eventSB1_1_1(struct ch target, struct mt monster) {
  type("Vous decide d'utiliser votre force pour detruire la cage. Tenez vous pret au combat...\n");
  int rez = fight(&target, &monster);
  if (rez) {
    type("Felicitation, ce combat n'etait pas facile : beaucoup de guerrier comme toi sont mort ici\n ");
    type(" Vous ramassez la cle que le mosntre a sur lui, et vous accedez dans une salle ou tous les guerriers sont mort. \n La famille remarque la corps du guerrier, il a malheureusement ete vaincu par le monstre. Vous remarquez qu'il tient en main une carte, vous decidez de la ramassez. La famille veut rester ici vous continuez donc seul");
    updateStats(&target, 10);
    printStats(target);
    choiceSB1_1_1(target); // choix vers la suite de l'aventure
  } else {
    endLose(16);
  }
}

int descSB1_1_1(struct ch target) {
  struct mt monster = constructMonsterSC2();
  type("Vous ne savez pas par ou aller pour chercher ce guerrier. Et, a ce moment la fille apercoit le bandana de son pere au sol, suivit d'une trace de sang.\n");
  type("Vous decidez de suivre le sang et ! Attention vous vous retrouvez coince dans une cage ! \n");
  type("le monstre arrive sur les lieux et decide de vous combattre\n");
  return eventSB1_1_1(target, monster);
}


