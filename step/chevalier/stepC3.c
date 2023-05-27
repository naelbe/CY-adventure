//rencontre avce la villageoise
#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSC3(struct ch target)
{
  int i=0;
  
  type("Au moment ou vous la remerciez, des cris stridents se font entendre a quelques maisons d'ici\n");
  sleep(2);
  type("Appuyez sur [1] pour vous dirigez vers les cris\n Appuyez sur [2] pour rebrousser chemin\n Appuyez sur [3] pour sauvegarder");
  i=readint(1,3);

  if(i==1){
    type("Tu es courageux d'y aller, en avant chevlier !\n");
    return 74;
  }
    
  else if(i==2){
    type("Tu rebrousses chemin?\n Comme tu le sais cet endroit est malsaint et tu n'arretes pas de tourner en boucle pour retrouver ton chemin.");
    type("Vous venez malheureusement d'entrer dans un sortilege et vous allez mourir de faim et d'epuisement...\n");
    sleep(2);
    endLose(4);
    return 73;
  }
  else if(i==3){
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 73, filename);
    return 999;
  }
}


int eventSC3(struct ch target)
{
  struct ch *target2 = &target;
  
  type("'Vous etes bienveillant jeune homme'\n");
  type("Je vais vous recompenser comme il se doit : ");
  sleep(2);
  type("Vous venez de de recevoir pommade de soin et vos points de vie ont augmentes !!");
  target2->pv += 70;
  type("'J'ai une derniere chose pour vous, tenez : '\n");
  sleep(1);
  type("Vous recevez [Potion d'annulation de sorts] x 1\n");
  type("Restez sur vos gardes, ici notre village est sous la menace de monstres terrifiants !");
  sleep(1);
  printStats(target);
  choiceSC3(target); //choix vers la suite de l'aventure
}


int descSC3(struct ch target)
{
  type("Vous respirez enfin l'air exterieur !\n");
  type("Mais soudain vous apercevez une vieille dame qui boite et s'ecroule au sol\n ");
  sleep(2);
  type("Comme vous etes un homme sage vous decidez de l'aider a se relever\n");
  sleep(2);
  return eventSC3(target);
}