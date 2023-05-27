#include "sys.h"
#include <time.h>
#include "../readint.h"
//MDOIF LES SRAND
//MODIF X DANS ATT EGINE

int attEngine1(struct ch *target) { //permet d'obtenir une valeure de retour d'atttaque pour le joueur

	int x = target->ad;
	srand(time(NULL));
	int rand1 = rand() % 101;
	if (rand1 <= target->crit) { // test l'existence d'un coup critique sur ce tour
	printf("\nVous assenez un coup critique !\n");
	x = 2*x;
	}
	return x;

}

int attEngine2(struct mt *monster) { //permet d'obtenir une valeure de retour d'atttaque pour le monstre
        
	int x = monster->ad;
        int rand1 = rand() % 101;
        if (rand1 <= monster->crit) { // test l'existence d'un coup critique sur ce tour
        printf("\nVotre ennemi vous assene un coup critique !\n");
        x = 2*x;
        }
        return x;

}

int defEngine1(struct ch *target, int att, int *pD) { //permet d'obtenir une valeure de retoure correspondant à l'attaque réduite par l'armure de l'adversaire
 	int x = att - (*pD/3);
       	int rand1 = rand() % 101;
        if (rand1 <= target->spd) { // meme systeme que coup critique,c ette fois avec l'esquive
        printf("\nVous venez d'eviter une attaque !\n");
        x = 0;
        }
        return x;
}

int defEngine2(struct mt *monster, int att, int *mD) { //permet d'obtenir une valeure de retoure correspondant à l'attaque réduite par l'armure de l'adversaire
	int x = att - (*mD/3);
	int rand1 = rand() % 101;
        if (rand1 <= monster->spd) {  // meme systeme que coup critique,c ette fois avec l'esquive
        printf("\nVotre ennemi viens d'eviter votre attaque !\n");
        x = 0;
        }
        return x;

}

void  monsterTurn(struct ch *target, struct mt *monster, int *mH, int *pH, int *pD, int *mD) { //lance le tour du monstre qui decide aleatoirement entre attaque et defense
	 int gState = 60;
	 sleep(3);
	 if (*mH < 30) {
		gState = 40;
	 }
	 if(*pH < 30) {
		gState = 70;
	 }
	 srand(time(NULL));
	 int rand1 = rand() % 101;
	 if (rand1 <= gState) {
		 int att = attEngine2(monster);
		 int fatt = defEngine1(target, att, pD);
		 printf("%s vous inlige %d dégats !\nVos PV : %d\n", monster->name, fatt, *pH-fatt);
		 *pH -= fatt;
	 }
	 else {
		 *mD += 6;
		 printf("L'armure de %s à été augmenté de 6 points !\n", monster->name);
	 }






}

void playerTurn(struct ch *target, struct mt *monster, int *mH, int *pH, int *pD, int *mD) { //tour du joueur, lui propose de chosiir entre atatque defense ou abilité speciale
	int choice;
	printf("Choisissez une action :\n(1) Attaquer\n(2) Defendre\n");
	choice = readint1(1, 2);
	if (choice == 1) {
	int att = attEngine1(target);
	int fatt = defEngine2(monster, att, mD);
	*mH -= fatt;
	printf("\nVous infligez : %d degats !\nPV de votre adversaire : %d\n", fatt, *mH);
	}
	else if (choice == 2) {
	*pD += 6;
	printf("Votre armure augmente de 6 points !\n");
	}
	


}



int fight(struct ch *target, struct mt *monster) { //fonction de combat qui initialise stats des deux joueurs, et poursuis le fight jusqu'a la mort de l'un d'eux
	int mHealth = monster->pv;
	int pHealth = target->pv;
	int mDef = 0;
	int pDef = 0;
	int roundC = 0;
	int roundP = 0;
	printf("Bienvenue dans votre épique combat contre %s !\n\n", monster->name);
	printf("\n%s\n\n", monster->desc);
	printf("appuyez sur entree pour commencer.\n");
	char d;
	scanf("%c", &d);
	if (d == '\n') {
	if (target->spd > monster->spd) {
		roundP = 1;
	}
	

	while(mHealth > 0 && pHealth > 0) {
	if (roundP) {
		printf("ROUND : %d\n\n", roundC);
		playerTurn(target, monster, &mHealth, &pHealth, &pDef, &mDef);

		roundP -= 1;
	}
	else {
		printf("ROUND : %d\n\n", roundC);
		monsterTurn(target, monster, &mHealth, &pHealth, &pDef, &mDef);
		
		roundP += 1;
	}

	if (mHealth <= 0) {
		printf("Victoire !\n");
		return 1;
	}
	else if (pHealth <= 0) {
		printf("Defaite !\n");
		return 0;
	}
	else {
	roundC++;
	}

	}
	}
}

