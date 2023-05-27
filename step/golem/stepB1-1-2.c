#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"


int choiceSB1_1_2(struct ch target) {
  int i = 0;
  type("Vous etes maintenant equipe d'une carte qui indique la position de Rakai\n");
  type("Souhaitez vous suivre la carte vers Rakai avec le guerrier afin de vous venger ? tapez (1) si vous suivez la carte et (2) si vous preferez continuer seul sans carte\n");
  i = readint(1, 3);
  char filename[30];
  switch (i) {
  case 1:
    type("tu as decide de suivre la carte avec le guerrier!\n");
    return 83;
    break;
  case 2:
    endLose(20);
    return 8112;
    break;
  case 3:
  
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 8112, filename);
    return 999;
    break;
  }


}

int eventSB1_1_2(struct ch target, struct mt monster) {
  type("Vous lui donnez un gros coup de bouclier afin de l'ecarter du guerrier a terre\n");
  int rez = fight(&target, &monster);
  if (rez) {
    type("Felicitation, vous avez vaincu le monstre !");
    type("\nLe guerrier que vous avez sauve est reconnaissant, il vous donne sa potion de PV. De plus, il sait ou se trouve Rakai. Vous partez donc avec lui.");
    updateStats(&target, 11);
    printStats(target);
    choiceSB1_1_2(target); // choix vers la suite de l'aventure
  } else {
    endLose(16);
  }
}


int descSB1_1_2(struct ch target) {
  struct mt monster = constructMonsterSA1();
  type("Vous decidez de laisser la famille, vous avance maintenant seul\n");
  type("Vous entendez dans cris au loin et vous apercevez un guerrier qui lutte contre un monstre. Vous allez bien evidemment l'aider\n ");
  type("Un monstre apparait ! Vous l'attaquez");
  return eventSB1_1_2(target, monster);
}
