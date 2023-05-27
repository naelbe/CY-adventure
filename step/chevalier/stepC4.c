// fight avec Gardien de la Porte
#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSC4(struct ch target)
{
  int i=0;
  struct ch *target12 = &target;
  
  type("Vous vous rerouvez face a un monstre qui n'a pas l'air de vous voir, mais vous avez a present deux lames a disposition, laquelle choisirez vous ?\n");
  sleep(2);

  type("Appuyez sur [1] pour combattre avec l'epee de votre maitre\n Appuyez sur [2] pour utlier la puissante epee du Gardien de la porte ou \nAppuyez sur [3] pour sauvegarder");
  i=readint(1,3);
  if(i==1){
    endLose(13);
    return 74;
  }
  else if(i==2){
    type("Votre attaque a donc augmenté de 20 ");
    target12->ad += 20;
    printStats(target);
    return 75;
  }
  
  else if(i==3 ){
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 74, filename);
    return 999;
  }  
}

int eventSC4(struct ch target){ // potion sur gardien de la porte pour annuler son sort de zombie
  
  type("Vous penetrez le chateau et vous voila face a un nouvel ennemi !!");
  sleep(2);
  type("'Je suis le gardien de la porte, et j'aneantirais tous ceux qui se trouvent sur mon passage hahahaha !! '\n");
 type("Il a l'air vraiment puissant... \n Mais soudain vous sentez quelque chose dur dans votre poche, la potion !!\n");
  type("Mais oui la potion de la villageoise \n");
  sleep(1);
  type("Voulez vous l'utiliser? \nEntrez [1] pour l'utiliser ou \n [2] pour l'envoyer en reserve\n");
  
  int n;
  n=readint(1,2);

  if(n==1)
  {
   type("Miracle, le gardien de la porte redevient humain!\n");
   type("'Merci infiniment de m'avoir rendu ma forme initiale jeune chevalier, en guise de remerciements je vous legue mon epee du monde des morts, elle vous sera plus utile qu'a moi'\n");
   type("Venez je vais vous guider vers ce cruel Rakai !");
   sleep(2);
   type("Vous arrivez devant une porte triangulaire , ayant les cles, le gardien vous ouvre\n 'Je vous en supplie battez ce monstre et liberez notre peuple !'");
   choiceSC4(target);
  }
    
  else if(n==2)
  {
    endLose(12);
    return 74;
  }
}


int descSC4(struct ch target)
{
  type("Vous arrivez alors à l'endroit puis ressentez une certaine panique en apercevant des traces de sang\n");
  type("Ces dernieres vous guide vers la seule forteresse de la ville \n ");
  sleep(2);

  type("Ce chateau semble terrifiant !! une sombre aura s'en degage...\n");
  type("Entrons a l'interieur, il faut absolument trouver Rakai");
  sleep(2);

  return eventSC4(target);
}