#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"


int choiceSB3(struct ch target) {
type("Vous l'avez battu. Vous l'avez terasse.\nVous etes maintenant un hero, et une gloire eternelle vous attend a la sortie du chateau.\n");
  type("Neanmoins, il reste un dernier detail a regler... que ferez-vous de lui ? Le grand Rakai, qui parait maintenant si petit, au sol et battu.\n");
  type("Le tuerez-vous ? Ou comptez-vous l'epargner ?\n");
  type("(1) Tuer Rakai\n(2) Epargner Rakai\n(3) Sauvegarder\n");
  int i;
  i = readint(1, 3);
  if (i == 1) {
    endWin();
    return 999;
  }
  else if (i == 2) {
    endLose(14);
    return 83;
  }
  else if (i == 3) {
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 83, filename);
    return 999;
  }
  
}


int eventSB3(struct ch target, struct mt rakai)  {
  type("Vous entendez du bruit dans le chateau, vous n'avez jamais mis les pieds ici mais vous vous sente guide vers Rakai.\n");
  type("Vous arriez devant la salle de trone, et vous le savez, le grand Rakai se trouve derriere cette porte. Sans aucune hesitation, vous foncez et vous retrouvez a une dizaine de metres de lui : il est grand, un visage banal, mais vous ressentez sa puissance de la ou vous vous trouvez.\n");
  type("Pas besoin d'echanger un mot, le combat sera sans merci, et il commence maintenant !");
  int x = fight(&target, &rakai);
  if (x) {
    return choiceSB3(target);
  }
  else {
    endLose(12);
    return 83;
  }
}




int descSB3(struct ch target) {
    struct mt rakai = constructMonsterSA1_4();
    type("Bravo !\n Vous avez reussi !\n Vous avez trouve le chateau de Rakai, il est maintenant temps de se battre\n");
type("Vous vous preparez au combat : epee, bouclier, tout est pret, et vous sentez votre rage grandir en vous.\n");
  return eventSB3(target, rakai);
  
}
