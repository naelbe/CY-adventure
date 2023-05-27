#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"


int choiceSB2_2(struct ch target) {
  int i = 0;
  type("Vous etes maintenant equipe d'une carte qui indique la position de Rakai\n");
  type("Souhaitez vous suivre la carte vers Rakai afin de vous venger ? tapez (1) si vous suivez la carte ou (2) si vous preferez continuer seul sans carte ou (3) Sauvegarder\n");
  i = readint(1, 3);
  char filename[30];
  switch (i) {
  case 1:
    type("tu as decide de suivre la carte!\n");
    return 83;
    break;
  case 2:
    endLose(20);
    return 822;
    break;
  case 3:
      printf("Nom de la sauvegarde :");
      scanf("%s", filename);
      saveGame(&target, 822, filename);
      return 999;
    break;
  }
}
  

int eventSB2_2(struct ch target, struct mt monster) {
  type("Vous decide d'utiliser votre force pour detruire la cage. Tenez vous pret au combat...\n");
  int rez = fight(&target, &monster);
  if (rez) {
    type("Felicitation, ce combat n'etait pas facile : beaucoup de guerrier comme toi sont mort ici\n Vous ramassez la cle que ");
    printf(" %s\n", monster.name);
    type("a sur lui, et vous accedez dans une salle ou tous les guerriers sont mort. \n Vous remarquez que l'un des cadavres a une carte a la main, vous decidez de la ramassez");
    updateStats(&target, 10);
    printStats(target);
    choiceSB2_2(target); // choix vers la suite de l'aventure
  } else {
    endLose(16);
  }
}

int descSB2_2(struct ch target) {
  struct mt monster = constructMonsterSC2();
  type("\n");
  type("...");
  printf("\n");
  type("Attention! \n");
  type("le monstre arrive sur les lieux et decide de vous combattre\n");
  return eventSB2_2(target, monster);
}

