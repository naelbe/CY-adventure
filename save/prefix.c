#include "../system/sys.h"



char *prefixSave(char *input) { //permet d'ajouter "save/" devant chaque nom de fichier afin de placer toutes les auvegardes dans le dossier save

	char *dest = malloc(strlen("save/") + strlen(input) + 1);
	strcpy(dest, "save/");
	strcat(dest, input);
	return dest;

}
