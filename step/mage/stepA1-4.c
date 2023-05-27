#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSA1_4(struct ch target) {
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
    return 914;
  }
  else if (i == 3) {
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 914, filename);
    return 999;
  }
  
}








int eventSA1_4(struct ch target, struct mt rakai)  {
    type("Akashi vous confere ses pouvoirs : vous recuperez l'objet 'Karma des dieux '"); //item >7 dans updateStats
  updateStats(&target, 7);
  printStats(target); 
  type("Vous savez ou aller : vous entendez la voix d'Akashi vous chuchoter le chemin... C'est comme si vous aviez grandis dans cet endroit.\n");
  type("Vous arriez devant la salle de trone, et vous le savez, le grand Rakai se trouve derriere cette porte. Sans aucune hesitation, vous foncez et vous retrouvez a une dizaine de metres de lui : il est grand, un visage banal, mais vous ressentez sa puissance de la ou vous vous trouvez.\n");
  type("Pas besoin d'echanger un mot, le combat sera sans merci, et il commence maintenant !");
  int x = fight(&target, &rakai);
  if (x) {
    return choiceSA1_4(target);
  }
  else {
    endLose(12);
    return 914;
  }
}




int descSA1_4(struct ch target) {
    struct mt rakai = constructMonsterSA1_4();
    type("Bravo !\n Vous avez reussi !\n Vous avez reussi a  vaincre votre haine et epargner votre adversaire. Akashi vous en est eternellement reconaissant, et, a decide dans un dernier elan de vous aider a battre Rakai en vous conferant sa puissance : il a transfere son ame et ses pouvoirs en vous. Fort comme vous etes, vous ne pouvez plus perdre... Ou pouve-vous ?\n");
type("Vous vous preparez au combat : epee, bouclier, relique de mage, tout est pret, et vous sentez les pouvoirs d'Akashi se concentrer en vous.\n");
  return eventSA1_4(target, rakai);
  
}
