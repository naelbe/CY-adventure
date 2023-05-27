#include <stdio.h>
#include "sys.h"
#include "type.h"
#include "../readint.h"

int start() { //fonction de choix de départ
  int i = 0;
  printf("\n\n");
  printf("\t\t\t\t\t\t\t\t WELCOME TO :");
  printf("\n\n");
  printf("  \t\t\t\t\t\t \t   \033[31mCY ADVENTURE !\033[0m\n\n\n");
  printf("\n\n");
  printf("PLEASE CHOSE AN OPTION TO START FROM :\n");
  printf("(1) CHARGE NEW GAME\n");
  printf("(2) LOAD FROM SAVED GAME\n\n");
  i = readint1(1, 2);   // demande d'une valeure a l'utilisateur securisée
  printf("\033[2J\033[1;1H");
  return i;
}
