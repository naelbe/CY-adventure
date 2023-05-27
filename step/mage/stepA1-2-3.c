#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSA1_2_3(struct ch target) {
  int i = 0;
  type("Apres avoir remporte le combat, vous fouillez vos ennemis, et sur ce qui semble etre un officier, vopus recuperez deux choses : une potion, qui augmente vos PV, ainsi qu'une carte.\nQue choisissez-vous ?\n");
  type("(1) La potion\n(2) La carte\n(3) Sauvegarder\n");
  i = readint(1, 3);
  if (i == 1) {
    return 9121;
  }
  else if (i == 2) {
      return 9122;
  }
  else if (i == 3) {
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 9123, filename);
    return 999;
  }
  return i;
}

int eventSA1_2_3(struct ch target) {
  type("Un de vos compagons, plus age et l'air serein vu la situation vous donne une petite epee, il dit : <<Les mages sont tres puissants, mais peine a se debrouiller dans des combats mal organise. Cet epee pourra peut etre t'aider un peu>>\n");
  type("Vos stats on ete ameliore !\n");
  updateStats(&target, 5);
  printStats(target);
  type("Le combat est sans merci, mais grace a votre epee, vous etes redoutable au corps a corps. De plus,  vous etes largement en sur nombre!\n");
  return choiceSA1_2_3(target);
}

int descSA1_2_3(struct ch target) {
  type("Vous retournez aupres de vos compagnons aussi vite que possible, vous pouvez vous estimer chanceux d'etre encore vivant !\n");
  type("Vous reflechissez a votre prochaine action quand soudain...\n");
  type("Une horde de monstres se precipite sur vous !\nVous avez bien fait de rester avec vos compagnons, autrement, cela aurait pu etre fatal\n");
  return eventSA1_2_3(target);
}