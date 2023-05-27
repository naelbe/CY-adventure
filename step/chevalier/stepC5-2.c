//Rencontre d'une Porte sacrée apres l'escalier de droite
#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSC5_2(struct ch target)
{
  int i=0;
  type("Appuyez sur [1] pour avancer \nAppuyez sur [2] pour aller voir dans l'autre escalier et\nAppuyez sur [3] pour sauvegarder");
  
  i=readint(1,3);
  if(i==1){
    return 76;
  }
  else if(i==2){ 
   return 751;
  }
  else if(i==3){
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 752, filename);
    return 999;
  }
}

int eventSC5_2(struct ch target)//don de bouclier, defense augmente
{
  int n;
  type("Tapez [1] pour s'incliner et saluer\n Tapez [2] pour crevez les yeux de la Porte sacree \n");
  sleep(2);
  n=readint(1,2);
  
  if(n==1){
    
    type("Incroyable la legende disait vrai, les portes sacrees s'ouvrent avce une marque de respect uniquement ...\n");
    type("Super elle vient de vous offrir un bouclier !");
    
    updateStats(&target, 6); 
    printStats(target);
    
    return choiceSC5_2(target);
  }

  else if(n==2){ 
   endLose(99);
   return 752;
  }
}


int descSC5_2(struct ch target)//description de porte, avant il fallait saluer les portes et s'incliner pour qu'elles nous ouvrent le passage
{
  type("Vous avancez dans l'escalier de gauche et se trouve en haut, une porte, une enorme porte meme");
  type("Elle possede des yeux !!??");
  type("Vous pensez a lui planter l'epee dans les yeux, mais vous vous souvenez des dires de votre maitre:\n");
  sleep(2);
  type("Lorsqu'une porte sacre vous barre le passage, alors suffit simplement de s'incliner et de la saluer");
  sleep(2);
  return eventSC5_2(target);
}
