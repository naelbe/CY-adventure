#include "../system/type.h"
#include "../system/sys.h"
#include "../readint.h"

int eventS0(struct ch player2, int i) { //event type : shop
  // elipse entrainement, resort avec de meilleurs stats et du gold 
  char trainer[10];
  char object[20];
  int itemChoix = 0;
  player2.class = i;
  if (i == 1) {
    strcpy(trainer, "Ragnar");
    strcpy(object, "Bouclier de tank");
    itemChoix = 3;
    i = 8;
  }
  else if(i == 2) {
    strcpy(trainer, "Heuss");
    strcpy(object, "Epee de chevalier");
    itemChoix = 2;
    i = 71;
  }
  else if (i == 3) {
    strcpy(trainer, "Harry");
    strcpy(object, "Livre de sorcier");
      itemChoix = 1;
      i = 91;
  }
  else {
    printf("error : input invalid ! exiting...\n\n");
    exit(1);
  }
  type("Votre entrainement est enfin termine !\n");
  type("Vous etes pret a partir au combat, mais avant cela, vous allez recevoir un cadeau de la part de ");
  printf(" %s\n", trainer);
  sleep(2);
  type("Felicitation, vous venez de recevoir ");
  printf(" %s\n", object);
  updateStats(&player2, itemChoix);
  printStats(player2);
  type("Assez discute, vous avez un monde a sauver !\n\n");
  sleep(1);
  return i;
}

int choixS0(struct ch player2) { // NE PAS METTRE D4ACCENT DANS TYPE SINON BUG
  int i = 0;
  type("Neanmoins, votre peuple est sous l'assault de monstres cruels, et vous n'aurez le temps de vous former qu'une fois\n");
  type("N'oubliez pas que chaque specialisation de votre personage vous apportera une experience de jeu differente !\n");
  type("(1) choisir Ragnar le golem (2) choisir Heuss le chevalier (3) choisir Harry le sorcier");
  clear();
  i = readint(1, 3);
  player2.class = i;
  return eventS0(player2, i);
}
// rouge :  \033[31mTEXT\033[0m
// clear l'ecran printf("\033[2J\033[1;1H");


int descS0(struct ch player2) {
  type("Tout commence lorsque vous vous retrouvez prisonnier de guerre apres un affrontement avec un camp ennemi...\n");
  type("Cependant, vous remarquez que vos semblables de la prison, que cela soit vos alies ou vos ennemis, sont tues un a un, et sont changes en monstres grace a une puissante magie !\n");
  type("Ils deviennent alors serviteurs d'un certain Rakai, le chef du camp ennemi\n");
  type("Mais alors que vous parvenez a vous echapper grace au chao cree par toute cette agitation, vous rencontrez par la suite trois maitres d'armes epuise, avec la fatigue de quelqun qui auarait combattu des semaines durant. Vous voyez dans leur yeux votre reflet, une lueur d'espoir peut etre...\n");
  printf("\n\n");  
  type("Vous avez l'opportunite d'etre entraine par 3 des meilleurs dans leur domaine : Heuss le chevalier, Ragnar le mgolem et Harry le sorcier !\n");
  type("En revanche, un seul d'entre eux pourra vous prendre sous son aile, lequel des trois choisirez vous?");
  return choixS0(player2);
} 
