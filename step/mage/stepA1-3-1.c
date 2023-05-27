#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSA1_3_1(struct ch target) {
  int i = 0;
    type("Vous enlevez son masque a votre adversaire battu, au sol, essoufle.\nC'est un jeune homme, la vingtaine, il parait appeure;\n");
  type("Il vous dit : Je pensais que c'etait un ennemi, je cherche Rakai, toi aussi ? j'ai quelque chose a te montrer\n");
  type("il met sa main dans sa poche, que va il sortir une arme ?\n ");
  type("Vous devez agir rapidement, ou votre aventure risque de se terminer ici, que decidez-vous ?\n(1) Abattre le jeune homme\n(2) Le laisser faire\n(3) Sauvegarder\n");
  i = readint(1, 3);
  if (i == 1) {
    endLose(17);
    return 9131;
  }
  else if (i == 2) {
    return 91311;
  }
    else if (i == 3) {
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 9131, filename);
    return 999;
  }
}


int eventSA1_3_1(struct ch target, struct mt monsterT) {
  type("Vous decelez plein d'erreurs dans la posture de votre adversaire, est-ce vraiment un allie de Rakai, il semble bien trop faible. Vous hesitez a l'epargner mais il ne vous laisse pas le choxi: il s'elance, sur vous, alors que le combat commence !");
  int x = fight(&target, &monsterT);
  if (x) {
    return choiceSA1_3_1(target);
  }
  else  {
    endLose(10);
    return 9131;
  }
}





int descSA1_3_1(struct ch target) {
  struct mt monsterT = constructMonsterSA1_31();
  type("Vous vous rendez sur le lieu des cris, mais a peine avez vous le temps de regarder autour de vous que vous prennez un violent coup a l'arriere de votre tete\n");
  type("Vous vous remettez aussi vite que vous le pouvez et vous elancez vers votre opposant...\n");
  type("A votre grande surprise, ce dernier ne ressemble pas a un monstre, mais bien a un humain...\nNeanmoins, son masque vous empeche d'en etre sur.\n");
  printf("\033[2J\033[1;1H");
  type("dans tout les cas c'est vous contre lui, humain ou pas, vous ne retiendrez pas vos coups !\n");
  return eventSA1_3_1(target, monsterT);
}
