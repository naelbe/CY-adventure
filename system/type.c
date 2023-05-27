#include <termios.h>
#include <time.h>
#include "type.h"
#include "sys.h"
#include <ncurses.h>

/*void type(char *input) { // fonction pour simuler lécriture du texte dans le terminal
  int size = strlen(input);
  struct timespec pause = {0, 100000000}; //structure de time.h avec un delais en micro secondes
  for (int i = 0; i < size; i++) {
    putchar(input[i]); //inscris le caractère en question
    fflush(stdout); //vide le buffer pour eviter les bugs
    nanosleep(&pause, NULL); //délai de pause en micro secondes
  }
}*/

void type(char *buffer) {
	
    //passer en mode "cooked" afin d'initaliser ncurses
    
    struct termios raw, cooked;
    tcgetattr(0, &raw);
    cooked = raw;
    cooked.c_lflag |= ICANON | ECHO;
    tcsetattr(0, TCSAFLUSH, &cooked);


    //init stdscr
    initscr();
    cbreak();
    noecho();

    //get stdscr dimension and box it
    int maxX, maxY;
    getmaxyx(stdscr, maxY, maxX);
    box(stdscr, 0, 0);
    refresh();

    //init book window, get dimension, box it and print titre
    WINDOW *book = newwin(32, 50, 5, 25);
    start_color();
    init_pair(8, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(7, COLOR_RED, COLOR_WHITE);
    init_pair(6, COLOR_GREEN, COLOR_WHITE);
    init_pair(2, COLOR_MAGENTA, COLOR_MAGENTA);
    int bx, by;
    wattron(book, COLOR_PAIR(2));
    getmaxyx(book, by, bx);                            // ajouter window secondaire autour de 'book' : x += 5; y += 10;
    box(book, 0, 0);
    wattroff(book, COLOR_PAIR(2));
    init_pair(4, COLOR_BLACK, COLOR_WHITE);
    bkgd(COLOR_PAIR(2));
    wrefresh(book);
    refresh();
    wbkgd(book, COLOR_PAIR(4));
    attron(COLOR_PAIR(8));
    mvwprintw(book, 2, (bx-12)/2, "CY ADVENTURE");
    attroff(COLOR_PAIR(8));
    wrefresh(book);

    //write buffer letter by letter
    int l = 4;
    int r = 4;
    for(int i = 0; i < strlen(buffer); i++) {
        if (r >= bx-4) {
            l++;
	    r = 4;
        }
        char d[5];
	d[0] = buffer[i];
	d[1] = '\0';
        struct timespec pause = {0, 100000000};
	attron(COLOR_PAIR(4));
	mvwprintw(book, l, r, d);
	attroff(COLOR_PAIR(4));
	r++;
        wrefresh(book); //inclure arg : book
        fflush(stdout);
        nanosleep(&pause, NULL);

    }

    attron(COLOR_PAIR(6));
    mvwprintw(book, 28, 5, "Appuyez sur ENTREE pour continuer !\n");
    attroff(COLOR_PAIR(6));
    char c = getch();							// ici clear l'ecran et les windows quand l'user appuye sur entree
    if (c == '\n') {		 
	echo();
	erase();
	werase(book);
	clear();
	refresh();
	wrefresh(book);
	endwin();
	delwin(book);
	clear();

					///ici passe du mode cooked au mode raw afin de pouvoir utiliser les interactiosion du terminal de base

    }
    else {
	sleep(10);
	type(buffer);
    }
}
