#include "readint.h"
#include <termios.h>
#define MAX_INPUT_LENGTH 32
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void clearCall () {
    // Clear terminal
    printf("\033[2J\033[H");
    fflush(stdout);

    // Wait for 2 seconds
    sleep(2);

    // Restore terminal settings to enable getch()
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}




// Lis un entier entre minValue et maxValue et retourne la saisie
int readint(const int minValue, const int maxValue) {
 clearCall();
  char *end, input[MAX_INPUT_LENGTH];
  long inputAsLong;

  // On entre dans une boucle qui se répète tant que la saisie est invalide (pas
  // un entier / pas entre min et max)
  printf("> ");
  while (fgets(input, MAX_INPUT_LENGTH, stdin)) { // On récupère la saisie
    // On convertit la saisie en entier avec strtol (string to long)
 
	  inputAsLong = strtol(input, &end, 10);
    // Si la fin est égale à l'entrée originale / la fin n'est pas une nouvelle
    // ligne (dernier caractère avec fgets) cela veut dire qu'il y a eu un
    // problème (très probablement que la saisie est invalide) On vérifie aussi
    // que l'entrée est bien entre min et max
    if (end == input || *end != '\n' || inputAsLong < minValue || inputAsLong > maxValue) {
      printf("Saisie invalide - entrez une valeur appropriée, input : %ld\n> ", inputAsLong);
    } else
      break; // Sinon la saisie est valide
  }

     
  return (int)inputAsLong;
}


int readint1(const int minValue, const int maxValue) {// variante de readint sans le clearCall
  char *end, input[MAX_INPUT_LENGTH];
  long inputAsLong;

  // On entre dans une boucle qui se répète tant que la saisie est invalide (pas
  // un entier / pas entre min et max)
  printf("> ");
  while (fgets(input, MAX_INPUT_LENGTH, stdin)) { // On récupère la saisie
    // On convertit la saisie en entier avec strtol (string to long)
    inputAsLong = strtol(input, &end, 10);
    // Si la fin est égale à l'entrée originale / la fin n'est pas une nouvelle
    // ligne (dernier caractère avec fgets) cela veut dire qu'il y a eu un
    // problème (très probablement que la saisie est invalide) On vérifie aussi
    // que l'entrée est bien entre min et max
    if (end == input || *end != '\n' || inputAsLong < minValue || inputAsLong > maxValue) {
      printf("Saisie invalide - entrez une valeur appropriée\n> ");
    } else
      break; // Sinon la saisie est valide
  }


  return (int)inputAsLong;
}
