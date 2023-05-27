#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"


int choiceSB2_1(struct ch target) {
  int i = 0;
  type("Vous etes toujours dans la grotte ou vous avez vaincu le monstre.\nVous vous demandez pourquoi le monstre a t-il pointe cette statue.");
  type("Vous vous approchez de la statue et vous voyez une enigme a resoudre qui ouvre une porte. SOuhaitez vous resoudre l'enigme (1), passer votre chemin (2) ou (3) Sauvegarder\n");
  i = readint(1, 3);
  char filename[30];
  switch (i) {
  case 1:
    type("tu as decide de resoudre l'enigme! \n");
    return 8211;
    break;
  case 2:
    endLose(22);
    return 821;
    break;
  case 3:
  
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 821, filename);
    return 999;
    break;
  }
}


int eventSB2_1(struct ch target, struct mt monster) {
  type("Tenez vous pret au combat...\n");
  int rez = fight(&target, &monster);
  if (rez) {
    type("Bravo, vous venez de vaincre ce monstre feroce");
    printf(" %s\n", monster.name);
    type("Avant de mourir le monstre pointe du doigt une statue en pierre");
    choiceSB2_1(target); // choix vers la suite de l'aventure
  } else {
    endLose(16);
  }
}

int descSB2_1(struct ch target) {
  struct mt monster = constructMonsterSB2();
  type("Vous venez d'arriver sur les lieux que l'enfant vous a indique, et c'est a ce moment que tu realises que tu es tombe dans un traquenard, l'enfant est en fait un monstre\n");
  type("Il montre son vrai visage ! Attention!\n");
  type("il est tres rapide\n");
  return eventSB2_1(target, monster);
}

