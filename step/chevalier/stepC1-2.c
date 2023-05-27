//rencontre avec le Genie
#include "../../system/sys.h"
#include "../../readint.h"
#include "../../system/type.h"

int choiceSC1_2(struct ch target){
  
  int i=0;
  type("Si tu réponds correctement a ma question, alors je te laisserai passer\n");
  type("Ma question est simple, quel etait le nom de ton entraineur?");
  sleep(2);
  type("Entrez [1] pour Golem\n Entrez [2] pour Mage\n Entrez [3] pour Heuss\n Entrez et [4] pour sauvegarder");
  
  i = readint(1,4);
  
  if(i==1){
    endLose(7);
    return 712;
  }
  else if(i==2){
    endLose(7);
    return 712;
  }

  else if(i==3){
    return 72;
  }
  
  else if(i==4){
    char filename[30];
    printf("Nom de la sauvegarde :");
    scanf("%s", filename);
    saveGame(&target, 712, filename);
    return 999;
  }
}

int eventSC1_2(struct ch target )
{
 struct ch * target1=&target;
  
 type("Tes points de vie sont actuellement de : ");
 printf("%d", target1->pv);
 printf("\n");
 type("Mais ils pourraient augmenter de +110");
 return choiceSC1_2(target); 
}

int descSC1_2(struct ch target)
{
  type("La deuxieme porte s'ouvre et ...\n");
  sleep(1);
  type("... UN GENIE !!\n");
  sleep(2);
  type("Oui, je suis en effet ici pour te guider, ou pour te tuer...\n");
  sleep(4);
  return eventSC1_2(target);
}
