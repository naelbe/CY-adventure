#include "system/sys.h"
#include "system/type.h"
#include "readint.h"

int main() {
int st = start();
int step = 1;
char filename[70];
char name[70];

struct ch player;

if (st == 2) {
	//si choix de recuperer une sauvegarde, lance le processus de getSave et lance les etape a partir du return
	player = constructPlayer("rand");
	printf("Entrez le nom de la sauvegarde\n");
	scanf("%s", filename);
	printf("before getsave\n");
	step = getSave(filename, &player);
//	step = testFunction();
//	step = 1;
}

else {							// sinon commence l'aventure simplement en créeant le joueur
	printf("Quel est votre nom ?\n");
	scanf("%s", name);
	player = constructPlayer(name);
}


int run = 1;

			
			

while (run) { // code d'etape : 9 -> mage 8-> chevalier 7-> golem 
									//tant que run actif, donc que la partie pas terminée, lance le switch
	

	switch(step) { 			//switch avec step qui lance le premier bloc de chaque etape
	
		case 1 :
		step = descS0(player);
		break;

		case 999 : // cas de fin de partie, en cas de sauvegarde ou de endWin()
		run = 0;
		break;

		case 91 :
		step = descSA1(player);
		break;

		case 911 :
		step = descSA1_1(player);
		break;

		case 913 :
		step = descSA1_3(player);
		break;

		case 912 :
		step = descSA1_2(player);
		break;

		case 91222 :
		step = descSA1_2_2_2(player);
		break;

		case 9121 :
		step = descSA1_2_1(player);
		break;

		case 9122 :
		step = descSA1_2_2(player);
		break;

		case 91211 : 
		step = descSA1_2_1_1(player);
		break;

		case 914 :
		step = descSA1_4(player);
		break;

		case 9123 :
		step = descSA1_2_3(player);
		break;

		case 91213 :
		step = descSA1_2_1_3(player);
		break;

		case 91311 :
		step = descSA1_3_1_1(player);
		break;

		 case 8 :
    		step = descSB(player);
    		break;

    		case 8111 :
    		step = descSB1_1_1(player);
    		break;

    		case 8112 :
   		step = descSB1_1_2(player);
   		break;

    		case 811 :
    		step = descSB1_1(player);
    		break;

    		case 81 :
    		step = descSB1(player);
    		break;

    		case 8211 :
    		step = descSB2_1_1(player);
    		break;

    		case 821 :
    		step = descSB2_1(player);
    		break;

    		case 822 :
    		step = descSB2_2(player);
    		break;

    		case 82 :
    		step = descSB2(player);
    		break;

    		case 83 :
    		step = descSB3(player);
    		break;

    		case 71 :
    		step = descSC1(player);
    		break;

    		case 712 :
    		step = descSC1_2(player);
    		break;

    		case 72 :
    		step = descSC2(player);
    		break;
    
    		case 73 :
    		step = descSC3(player);
    		break;

    		case 74 :
    		step = descSC4(player);
    		break;

    		case 75 :
    		step = descSC5(player);
    		break;

    		case 751 :
    		step = descSC5_1(player);
    		break;

    		case 752 :
    		step = descSC5_2(player);
    		break;

    		case 76 :
    		step = descSC6(player);
    		break;

		default :
		printf("\nETAPE INVALIDE, FERMETURE DU PROGRAMME\n");
		exit(1);
		break;

}
	}

















}
