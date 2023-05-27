#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

// arrive au repere avec carte
// combat le monstre 2_2 pour acceder au repere


int choiceSA1_2_2(struct ch target) {
  int i = 0;
  type("Bravo.\n");
  type("Vous avez surpasse meme l'un des plus feroces adversaires.\n");
  type("Le combat fut intense, vous avez perdu de la vie pour de l'attaque, mais vous etes maintenant epuise, et vous n'avez aucune chance de battre Rakai dans cet etat.\n");
  type("vous etes pris d'une elan de rage, et vous jetez vos foudres sur votre adversaire a terre.\n");
  type("Que choisissez-vous ?\nlaissez libre cours a votre rage ou epargner le monstre a vos pieds ?\n");
  type("(1) Tuer Akashi\n(2) Epargner Akashi\n(3) Sauvegarder");
  i = readint(1, 3);
  if (i == 1) {
    endLose(18);
    return 9122;
  }
  else if (i == 2) {
    return 914;
  }
   else if (i == 3) {
    char filename[30];
  printf("\033[2J\033[1;1H");
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 9122, filename);
    return 999;
  }
}



int eventSA1_2_2(struct ch target, struct mt monsterT) {
  struct ch *target1 = &target;
  type("Vous le reconaissez maintenant, c'est Akashi le general de Rakai. Il est beaucoup plus fort que vous...\n");
  type("Il ne vous reste qu'une chose a faire : la transformation. Votre maitre vous avez bien indique de l'utilise qu'en dernier recours, mais quel autre situation que celle-ci ?");
  type("Vous decidez de l'utiliser, et gagnez l'effet suivant : Potion de transformation\n");
  updateStats(&target, 9);
  printStats(target);
  type("Vous gagnez beaucoup d'attaque, en echange de votre vie...\n");
  printf("Mais cela suffira-il ?\n");
  int x = fight(&target, &monsterT);
  if (x) {
    return choiceSA1_2_2(target);
  }
  else {
    endLose(9);
    return 9122;
  }
}





int descSA1_2_2(struct ch target) {
  struct mt monsterT = constructMonsterSA1_5();
  type("Cette carte est peut etre le meilleur choix que vous ayez fait de toute l'aventure : elle vous a epargner de nombreux detours, et vous a permis d'arriver en pleine forme devant le chateau que vous croyez etre le repere de Rakai.\n");

  type("Neanmoins, comme dans le reste de votre aventure, rien ne vous sera donne gratuitement, et surtout pas le privilege d'affronter le grand rakai !\n");
  type("Vous arrivez devant cette porte massive, et a peine avez vous le temps de la contempler, qu'un homme, encore plus massif que la porte, debarque sur vos cotes.\n");
  type("C'est donc toi ");
  printf("%s ?\n", target.name);
  type("C'est donc un simple gamin qui met a terre nos troupes ? j'avais pourtant dit a Rakai de ne pas engager ces amateurs !\n");
  type("Cela n'a plus d'importance, ton aventure s'arrete ici et maintenant.\n");
  return eventSA1_2_2(target, monsterT);
}
