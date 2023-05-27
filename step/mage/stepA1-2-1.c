#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSA1_2_1(struct ch target) {
  type("Vous avez vaincu votre adversaire, et pas des moindre !\nEn regardant de plus pres, vous observez une sorte de distinction, le monstre que vous ave vaincu devait etre haut grade.\n");
  type("Vous le fouillez, et trouvez deux choses :\n(1) Un tissu, marque d'un blason\n(2) Un relique magique, potentielement tres puissante.\n Que choisissez-vous ?\n(3) Sauvegarder\n");
  int i = 0;
  i = readint(1, 3);
  if (i == 1) {
    return 91211;
  }
  else if (i == 2) {
    endLose(19);
    return 9121; // code de fin
  }
   else if (i == 3) {
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 9121, filename);
    return 999;
  }
}

int eventA1_2_1(struct ch target, struct mt monster4) {
    struct ch *target1 = &target;
    type("Vous vous preparez au combat, mais vous le savez : vous etes affaiblis par ces jours de marche, et votre adversaire a l'air plus feroce que jamais.\n");
  type("Vous etes diminue : votre lame s'est erode, vous perdez donc 12 degat d'attaque, ainsi que 5 de vitesse et 200 pv !\n");
  type("Vous vous rappelez de la potion que vous avez ramassé sur votre adversaire, vous ne savez pas vraiment ce qu'elle contient, mais vous n'avez plus grand chose a perdre : Vous l'avalez d'une traite, et gagnez l'effet suivant : Potion de malveillance.\n");
  updateStats(&target, 9);
  printStats(target);
  type("Assez discute, au combat !");
  int rez = fight(&target, &monster4);
  if (rez == 1) {
    type("bravo, vous avez remporte le combat !\n");
  }
  else {
    endLose(3);
    return 9121;
  }
  return choiceSA1_2_1(target);
}


int descSA1_2_1(struct ch target) {
  struct mt monster4 = constructMonsterSA1_6();

  type("Vous avez choisis la potion, peut etre n'etiez-vous pas confiant a propos de l'issus de votre prochain combat ?\n");
  type("L'hiver tombe, et vous n'avez toujours aucune trace de Rakai. Vous trouvez un village a proximite, ou vous comptiez vous reposer.\nEn effet, apres plus d'un mois a marche dans la neige et le froid, seul votre determination vous permet encore de tenir debout.\n");
  type("Vous arrivez sur la place du village, ou un cris vous glace le sang : vous ne trouverez pas de repos aujourd'hui.\n");
  return eventA1_2_1(target, monster4);
}
