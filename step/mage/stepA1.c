#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"					//type est la fonction permettant l'affichage du livre grace a ncurses
							
int choiceSA1(struct ch target) { 
  int i = 0;
  //choix region desertique artique ect --> choix vers defaite early ou recompense (ou pas)
  type("vous rencontrez un groupe de combatants, ils vous proposent de vous joindre a eux.\n");
  type("vous etes mefiants, mais decidez de faire un bout de chemin avec eux.\n Neanmoins, vous les questionnez et ils disent ne rien savoir a propos d'un certain Rakai. Disent-ils la verite ? vous n'avez pas le temps d'y penser que quelque chose vous sort de vos pensees.\n");
  type("vous entendez des cris au loin, vos 'nouveaux compagnons' vous conseille de ne pas y aller,  que faites vous ?\n");
  type("(1) vous aller voir sur le lieu des cris.\n(2) vous continuez avec le groupe de combatant.\n(3) vous continuez seul\n(4) sauvegarder\n");
  i = readint(1, 4); //fonction de recupération de l'input sécurisée
  if (i == 1) {
    return 911; 			//retourne le int de l'etape suivante  en fonction de l'input
  }
  else if (i == 2) {
    return 912;
  }
  else if (i == 3) {
    return 913;
  }
    else if (i == 4) {  		//demande le nom de la sauvegarde et enregistre la partie
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 91, filename);
    return 999;
  }
}

int eventSA1(struct ch target, struct mt monster1) {   //fonction d'evenement 
  type("preparez-vous pour le combat...\n");
  int rez = fight(&target, &monster1); // combat entre 
  if (rez) {
    type("Bravo !\n Vous avez vaincu ");
    printf(" %s\n", monster1.name);
    type("vous le fouillez, et parvenez a recuperer un objet :  ");
      type("relique de feu !");
    updateStats(&target, 4); // 4 -> DEUXIEME ITEM DE MAGE		//mise a jour des stats en fonction de l'item si victoire
    printStats(target);							//print des stats améliorées
    choiceSA1(target); 							//retourne la fonction de choix
  }
  else {
    endLose(16); //ecran de defaite si le combat est perdu, retourne l'etape actuelle pour recommencer
    return 91;
  }
}

int descSA1(struct ch target) { 			// fonction de description, prend en argument la structure du joueur et retourne la fonction d'evenement
  struct mt monster1 = constructMonsterSA1();   //envoi la structure du monstre correspondant a l'etape a la fonction d'évenemment
  type("Vous demarrez votre adventure !\n Neanmoins, ne vous attendez pas a une petite balade de sante... a peine sortis de votre repaire, vous tombez nez a nez avec un monstre, il n'a pas l'air particulierement puissant, mais l'air peu malin...\n");
  return eventSA1(target, monster1);
}
