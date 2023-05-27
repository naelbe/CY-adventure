#ifndef SYS_H
#define SYS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../item/item.h"
#include "../profile/champ.h"
#include "../profile/monster.h"

extern int choixSA1_3_1_1(struct ch target); //pour tester
extern void updateStats(struct ch *target, int item);
extern void printStats(struct ch target);
extern void endLose(int reason);
extern void endWin();
extern int start();
extern struct it *constructItem1();
extern struct it *constructItem2();
extern char *prefixSave(char *input);
extern struct it *constructItem3();
extern struct it *constructItem5();
extern struct it *constructItem4();
extern struct it *constructItem6();
extern struct it *constructItem10();
extern struct it *constructItem11();
extern struct it *constructItem70();
extern struct it *constructItem71();
extern struct it *constructItem72();
extern struct it *constructItem7();
extern struct it *constructItem8();
extern struct it *constructItem9();

// mage desc's
extern int descS0(struct ch target);
extern int descSA1(struct ch target);
extern int descSA1_1(struct ch target);
extern int descSA1_2(struct ch target); 
extern int descSA1_2_1(struct ch target);
extern int descSA1_2_2(struct ch target);
extern int descSA1_2_1_1(struct ch target);
extern int descSA1_3(struct ch target);
extern int descSA1_3_1(struct ch target);
extern int descSA1_4(struct ch target); 
extern int descSA1_3_1_1(struct ch target); //
extern int descSA1_2_3(struct ch target); //
extern int descSA1_2_2_2(struct ch target); //
extern int descSA1_2_1_3(struct ch target); //

//chevalier desc's
extern int descSC1(struct ch target);
extern int descSC2(struct ch target);
extern int descSC3(struct ch target);
extern int descSC4(struct ch target);
extern int descSC5(struct ch target);
extern int descSC5_2(struct ch target);
extern int descSC5(struct ch target);
extern int descSC6(struct ch target);
extern int descSC5_1(struct ch target);
extern int descSC1_2(struct ch target);

//golem desc's 
extern int descSB(struct ch target);
extern int descSB1_1_1(struct ch target);
extern int descSB1_1_2(struct ch target);
extern int descSB1_1(struct ch target);
extern int descSB1(struct ch target);
extern int descSB2_1_1(struct ch target);
extern int descSB2_1(struct ch target);
extern int descSB2_2(struct ch target);
extern int descSB2(struct ch target);
extern int descSB3(struct ch target);

extern int testFunction();
extern int fight(struct ch *target, struct mt *monster);
extern int getSave(char *filename, struct ch *player);
extern void saveGame(struct ch *player, int step, char *name);
extern void book3(char *buffer);

#endif
