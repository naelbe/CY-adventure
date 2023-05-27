#ifndef CHAMP_H
#define CHAMP_H


extern struct ch constructPlayer(char nameIn[20]);
extern int  testFunction();

struct ch { //champion incarné par le joueur
  char name[30];

  //stats 
  int lvl;
  int pv; // health bar
  int ad; // attack damage
  int ap; // magic damage
  int arm; // armor
  int gld; // gold
  int crit;
  int itm[5]; // item register
  int abt[5]; // ability register 
  int spd; // speed -> utile pour fightMech.c/dodge (+ rapide = + de dodge)
  int class; // type de champion, (créer un registre avec sorts/stats de base ??
  
};

#endif
