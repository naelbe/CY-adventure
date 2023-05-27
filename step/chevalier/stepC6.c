//Fight final avec le boss
#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSC6(struct ch target) {
type("Vous l'avez battu. Vous l'avez terasse.\nVous etes maintenant un heros, et une gloire eternelle vous attend a la sortie du chateau.\n");
  type("Neanmoins, il reste un dernier detail a regler... que ferez-vous de lui ? Le grand Rakai, qui parait maintenant si petit, au sol et vaicu.\n");
  type("Le tuerez-vous ? Ou comptez-vous l'epargner ?\n");
  type("[1] Tuer Rakai\n[2] Epargner Rakai\n[3] Sauvegarder\n");
  int i;
  i = readint(1, 3);
  if (i == 1) {
    endWin();
    return 999;
  }
  else if (i == 2) {
    endLose(14);
    return 76;
  }
  else if (i == 3) {
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 76, filename);
    return 999;
  } 
}

int eventSC6(struct ch target, struct mt rakai)  {
  type("Tout d'un coup dans votre poche interieure, un objet sacre legue par votre maitre Heuss vous fait tout d'un coup remonter quelques des souvenirs:\n "); 
  type("Une liqueur sacre utilisee uniquement en cas de danger de mort\n");
    type("Heuss vous confere ainsi ses pouvoirs indirectement: vous recuperez l'objet 'Karma des dieux ' et le buvez d'un trait."); //item >7 dans updateStats
  updateStats(&target, 7);
  printStats(target); 
  type("Vous savez ou aller en entendant la voix de Heuss vous chuchoter le chemin... C'est comme si vous aviez grandi dans cet endroit.\n");
  type("Vous arriez devant la salle de trone, et vous le savez, le grand Rakai se trouve derriere cette porte. Sans aucune hesitation, vous foncez et vous retrouvez a une dizaine de metres de lui : \n");
  type("C'etait lui le maitre du jeu, celui qui tenait toutes les cartes en main depuis le debut !\n");
  type("Cela peut paraitre fou mais il degage une aura monstrueuse");
  type("Pas besoin d'echanger un mot, le combat sera sans merci, et il commence maintenant !");
  int x = fight(&target, &rakai);
  if (x) {
    return choiceSC6(target);
  }
  else {
    endLose(12);
    return 76;
  }
}

int descSC6(struct ch target) {
  struct mt rakai = constructMonsterSA1_4();
  type("Un long couloir se trace devant vous et au bout, une porte.\n");
  type("Pensant que rakai se trouve derriere vous verifiez votre armement : epee, bouclier, tout est pret.\n");
  type("Vous vous preparez au combat : epee, bouclier, tout est pret.\n");
  return eventSC6(target, rakai);
  
}

