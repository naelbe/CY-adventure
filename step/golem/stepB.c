#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"


int choiceSB(struct ch target) {
  int i = 0;

  type("Vous vous retrouvez en face de 2 chemins qui menent vers 2 donjons...\n");
  type("Entrez 1 pour empreinter le chemin 1\n 2 pour le chemin numero 2\n");
  i = readint(1, 3);
  if (i == 1) {
      return 81;
  }
  else if ( i== 2) {
    return 82;
  }
   else if (i == 3) {
	    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 8, filename);
    return 999;
   }
}


int eventSB(struct ch target) {
  type("Vous recontrez un vieux Monsieur qui a perdu tout ce qu'il avait : sa famille, sa force, son envie de vivre... Tout ce qu'il veut c'est que Rakai paie pour ses crimes, il vous donne bouclier familial qui vous rendra fort");
    updateStats(&target, 3);
    printStats(target);
    choiceSB(target); // choix vers la suite de l'aventure
}


int descSB(struct ch target) {
  type("Vous venez d'entrer dans la zone de danger, de nombreux monstres feroces sous le commandement de Rakai rodent.\n");
  type("...");
  printf("\n");
  type("Un petit conseil ; fais tres attention a ou tu mets les pieds\n");
  type("Un monstre peut surgir a tout moment !\n");
  return eventSB(target);
}
