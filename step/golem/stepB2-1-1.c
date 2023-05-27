#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"


int choiceSB2_1_1(struct ch target) {
  int i = 0;
  type("Vous etes maintenant equipe d'une carte qui indique la position de Rakai\n");
  type("Souhaitez vous suivre la carte vers Rakai afin de vous venger ? tapez (1) si vous suivez la carte et (2) si vous preferez continuer seul sans carte\n");
  i = readint(1, 3);
   char filename[30];
  switch (i) {
  case 1:
    type("tu as decide de suivre la carte!\n");
    return 83;
    break;
  case 2:
    endLose(20);
    return 8211;
    break;
  case 3:;
    
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 8211, filename);
    return 999;
    break;
  }

  
}
  

int eventSB2_1_1(struct ch target) {
  int i;
  type("Tapez [1] pour : filet\n Tapez [2] pour : balle \n [3] pour : poisson et [4] pour sauvegarder");
  i=readint(1,3);
  
  if(i==1){
    type("Bravo c'est la bonne reponse ! Une porte s'ouvre vous etes libre et vous repartez avec une carte de la position de Rakai et une potion  utile en combat");
    updateStats(&target, 11);
    printStats(target);
    return choiceSB2_1_1(target);
  }
  else if(i==2){ 
   endLose(30);
    return 8211;
  }
  else if(i==3){ 
   endLose(30);
    return 8211;
  }
  else if(i==4){ 
   char filename[50];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 8211, filename);
    return 999;
  }
}


int descSB2_1_1(struct ch target) {
  type("La question est la suivante : on peut me retrouver au fond d'un bateau de peche ou au milieu d'un court de tennis. Qui suis-je donc?\n");
  return eventSB2_1_1(target);
}
