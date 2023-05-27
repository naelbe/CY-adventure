#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"


int choiceSA1_1(struct ch target) {
  int i = 0;
  type("Deux choix s'offre alors a vous, vous pouvez fuir, ou vous battre coute que coute.\n");
  type("(1) Fuire et retourner aupres de vos precedents compagnons\n(2) Combattre, et peut etre vous attirer une gloire eternelle !\n(3) Sauvegarder\n");
  i = readint(1, 3);
  if (i == 1) {
      return 91222;
  }
  else if ( i== 2) {
    return 913;
  }
   else if (i == 3) {
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 911, filename);
    return 999;
  }
}

int eventSA1_1(struct ch target) {
  type("Le combat commence : vos pouvoirs magique sont inegale, et cela se voit !\nVous prenez l'avantage, la victoire est proche...\n");
 type("Soudain, votre ennemi est rejoint par 5 autre compagnons.\n");
  type("Votre vitesse est de 12");
  type(" , celle de vos ennemis n'est que de 6");
  return choiceSA1_1(target);
}

int descSA1_1(struct ch target) {
  type("vous vous raprochez des cris quand soudain...\n");
  type("un monstre sort d'un buisson !\nVous etes effraye au premier abord, mais cela ne dure qu'un instant. Votre maitre vous a appris a garder votre calme en toute situation.\n");
  return eventSA1_1(target);
}