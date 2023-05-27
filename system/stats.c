#include "sys.h"

void printStats(struct ch target) { // print que les stats ont bien ete ameliores + print les stats a l'utilisateur
  printf("\033[2J\033[1;1H");
  printf("\t\tVos stats ont bien été améliorées ! \n\n");
  printf("\t\t%s STATS :\n\n", target.name);
  printf("\t\tPV : %d\n", target.pv);
  printf("\t\tAD : %d\n", target.ad);
  printf("\t\tAP : %d\n", target.ap);
  printf("\t\tARMOR : %d\n", target.arm);
  printf("\t\tCRIT : %d\n", target.crit);
  printf("\t\tSPEED : %d\n", target.spd);
  sleep(5);
}

void printItemStats(struct it *printItem) { //print les stats de l'item a l'utilisateur
  printf("\033[2J\033[1;1H");
  printf("\t\tVous venez d'obtenir : %s !\n", printItem->itemName);
  printf("\n");
  printf("\t\t%s\n", printItem->itemDesc);
  printf("\n");
  printf("\t\tPV : %d\n", printItem->pv);
  printf("\t\tAD : %d\n", printItem->ad);
  printf("\t\tAP : %d\n", printItem->ap);
  printf("\t\tARMOR : %d\n", printItem->arm);
  printf("\t\tCRIT : %d\n", printItem->crit);
  printf("\t\tSPEED : %d\n", printItem->spd);
  sleep(5);
}

void updateStats(struct ch *target, int item) {
  
struct it *statItem; // associe la structure d'item locale a l'item choisis.
switch (item) {

    case 1 :
    statItem = constructItem1();
    break;
    
    case 2 :
    statItem = constructItem2();
    break;
    
    case 3 :
    statItem = constructItem3();
    break;
    
    case 4 :
    statItem = constructItem4();
    break;
    
    case 5 :
    statItem = constructItem5();
    break;
	
    case 7 :
    statItem = constructItem7();
    break;
	
    case 8 :
    statItem = constructItem8();
    break;
    
    case 6:
    statItem = constructItem6();
    break;

    case 10 :
    statItem = constructItem10();
    break;
    
    case 11 :
    statItem = constructItem11();
    break;
   
    case 71 :
    statItem = constructItem71();
    break;

    case 72 :
    statItem = constructItem72();
    break;
    
    case 70 :
    statItem = constructItem70();
    break;
    
  }
  if (statItem == NULL) {
	printf("ITEM IS NULL ITEM IS NULL %d\n", item);
	printf("switch case is : %d\n", item);
  }
  printItemStats(statItem); // permet d'afficher les stats rajoutées par l'item
  target->pv += statItem->pv; // ajoute chaque stat une a une 
  target->ad += statItem->ad;
  target->ap += statItem->ap;
  target->crit += statItem->crit;
  target->arm += statItem->pv;
  target->spd += statItem->spd;

}

