#include "../system/sys.h"

void saveGame(struct ch *player, int step, char *name) { //permet de sauvegarder la partie a chaque choix.
strcpy(name, prefixSave(name));				// prend en parametre la structure de joueur (pour les stats), l'etape a sauvegarder et enfin le nom de la sauvegarde
printf("%s", name);
FILE *fptr;
printf("\n%s\n", name);

fptr = fopen(name, "w");
if (fptr == NULL) {

printf("IMPOSSIBLE DACCEDER AU FICHIER"); //en cas de nom de fichier invalide, relance la fonction.
	saveGame(player, step, name);
}
perror("fopen");

//printf("START PRINTF/PTR NON NULL !!\n"); //incris a chaque ligne les statistiques du joueur dans un fichier .txt
fprintf(fptr, "STEP: %d\n", step);
//printf("STEP SUCCES\n");
fprintf(fptr, "NAME: %s\n", player->name);
//printf("NAME success");
//printf("PRINTING ARM : %d PV : %d", player->arm, player->pv);
fprintf(fptr, "arm: %d\n", player->arm);
fprintf(fptr, "PV: %d\n", player->pv);
fprintf(fptr, "AD: %d\n", player->ad);
fprintf(fptr, "CRIT: %d\n", player->crit);
fprintf(fptr, "SPD: %d\n", player->spd);
fprintf(fptr, "CLASS: %d\n", player->class);
fprintf(fptr, "CY ADVENTURE");
fclose(fptr);


}


int getSave(char *filename, struct ch *player) {
	strcpy(filename, prefixSave(filename));
	sleep(3);
	FILE *fptr;
	fptr = fopen(filename, "r");
	strcpy(filename, prefixSave(filename));
	
	if (fptr == NULL) {
	printf("IMPOOSSIBLE DACCEDER AU FICHIER"); //relance la fonction si nom de fichier invalide
	sleep(5);
	getSave(filename, player);
}
	perror("fopen");
	int step;

fscanf(fptr, "STEP: %d\n", &step);         	//recupere les stats du joueur dans le fichier .txt, et les associe directement a la structure passée en parametre.
fscanf(fptr, "NAME:  %[^\n]\n", player->name);
fscanf(fptr, "arm: %d\n", &player->arm);
fscanf(fptr, "PV: %d\n", &player->pv);
printf("PVPVPVPVPPVPVPVPVPVPVP : %d", player->pv);
fscanf(fptr, "AD: %d\n", &player->ad);
fscanf(fptr, "CRIT: %d\n", &player->crit);
fscanf(fptr, "SPD: %d\n", &player->spd);
fscanf(fptr, "CLASS: %d\n", &player->class);
fclose(fptr);

return step; 					//retourne l'etape en int pour le switch du main
}	                                       
