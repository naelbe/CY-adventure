#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"



int choiceSB1_1(struct ch target) {
  int i = 0;
  type("Vous etes maintenant equipe d'un nouvel objet, mais le chemin est encore long...\n");
  type("La femme et la fille que vous sauvez ont une histoire particuliere. En effet le mari de la femme est comme toi , c'est un guerrier qui cherche a tuer Rakai. Mais il est porte disparu avec une carte qu'il a sur lui. Vas-tu aider la famille a le retrouver ? Tape (1) si oui, (2) si non et (3) Sauvegarder\n");
  i = readint(1, 3);
  if (i == 1) {
      return 8111;
  }
  else if ( i== 2) {
    return 8112;
  }
   else if (i == 3) {
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 811, filename);
    return 999;
   }
}

int eventSB1_1(struct ch target, struct mt monster) {
  type("Tenez vous pret au combat...\n");
  int rez = fight(&target, &monster);
  if (rez) {
    type("Bravo, vous venez de vaincre");
    printf(" %s\n", monster.name);
    type("Pour vous recompenser de votre bravoure, la famille vous donne un objet qui vous sera utile :");
    type("Potion de transformation\n");
    updateStats(&target, 8);
    printStats(target);
    choiceSB1_1(target); 
  } else {
    endLose(16);
  }
}

int descSB1_1(struct ch target) {
  struct mt monster = constructMonsterSC1();
  type("Vous venez d'arriver sur les lieux, la famille qui est en danger t'indiques ou se trouve");
  printf(" %s", monster.name);
  type("\nAttention il est tout pres !!\n");
  type("il t'attaque ! Vite il faut riposter\n");
  sleep(1);
  type("...");
  printf("\n");
  return eventSB1_1(target, monster);
}
