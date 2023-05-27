#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int eventSA1_3(struct ch target, int i) {
  struct ch *target1 = &target;// mort // rejoins la step after bataille avec les chevaliers
  if (i == 1) {

    type("Votre decision est prise en un eclair : Vous courrez aussi vite que vous le pouvez vers le pont et sautez sans reflechir.\nVous le savez, ces betes sont rapides, et elles le prouvent en s'accrochant a vous.");
    type("Vous faites ce que vous pouvez pour vous en debarasser, mais la situation est delicate :  le pont est en tres mauvaise etat et menace de ceder a chaque instant...\n");
    type("Les betes s'accrochent a votre sac, une seul possibilite s'offre a vous : l'abandonner...\n");
    type("Vous survivez, mais perdez 9 degats d'attaque !\n");
    target1->ad -= 9;
    type("Il s'en est fallu de peu cette fois, retenez la lecon, vous etes plus efficace accompagne que seul.\n");
    type("vous retenez la lecon, et sans perdre de temps, vous tentez de rattraper vos compagnons de route.\n");
    return 9123;
  }
  else if(i == 2) {
    type("Votre decision est prise en un eclair : vous vous ruez vers la foret, et feintez de continuer a courrir pendant que vous vous cachez derriere un arbre.\nVous retenez votre souffle autant que possible, et vous entendez enfin l'essaim vous depasser.\n");
    type("Heureusement, vous vous etes souvenus de ce qu'Harry vous a dit a propos des [NOM DU MONSTRE], leur vision est leur plus grande faiblesse.\n");
    type("Il s'en est fallu de peu cette fois, retenez la lecon, vous etes plus efficace accompagne que seul.\n");
    type("Neanmoins, vous vous etes maintenant trop eloinge pour rejoindre vos anciens compagnons, vous devrez continuer l'aventure seul...\n");
    return 91213;
  }
  else if (i == 3) {

    type("Vous faitez demi-tour, et vous vous ruez le plus vite possible vers la d'ou vous venez.\n");
    type("Neanmoins, vous auriez du etre plus attentif aux indications de votre maitre...\n");
    type("Les gargouilles sauvages ont des defauts, mais la vitesse n'en est pas un...\n... Vous avez a peine le temps de faire 20 metres que vous vous retrouvez plaque a terre par une horde de gargouilles sauvages...");

    endLose(15);
    return 913;
  }
}

int choiceSA1_3(struct ch target) {
  int i = 0;
  type("La première chose que vous a appris votre maitre, c'est d'analyser la situation peu importe a quel point elle semble critique.\n");
  type("Vous reperez 3 possibles 'issues', un pont en liane mal en point, la foret en flanc de la prairie. Votre derniere option est de les semer en faisant demi-tour, vous conaissez le chemin mieux qu'eux, enfin peut etre... ");
  type("Que choisissez-vous ?\n(1) Le pont en liane\n(2) La foret (3) Faire demi-tour\n(4) Sauvegarder\n");
 i = readint(1, 4);
     if (i == 4) {
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 913, filename);
    return 999;
  }
  return eventSA1_3(target, i);
}

int descSA1_3(struct ch target) {
  type("Vous avez decide de continuer seul, a votre guise...\n");
  type("Vous traversez une plaine, les environs paraissent calme, mais...\n");
  type("Vous n'avez pas le temps de finir votre pensee que vous vous retrouvez face a une dizaine de monstre, des [NOM?], petits, mais rapides et coriaces et se deplacent toujours en meute.\n");
  return choiceSA1_3(target);
}