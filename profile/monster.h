#ifndef MONSTER_H
#define MONSTER_H

extern struct mt constructMonsterSA1();
extern struct mt constructMonsterSA1_5();
extern struct mt constructMonsterSC1();
extern struct mt constructMonsterSB1(); 
extern struct mt constructMonsterSB2(); 
extern struct mt constructMonsterSC1();
extern struct mt constructMonsterSC3(); 
extern struct mt constructMonsterSC4(); 
extern struct mt constructMonsterSA1_4();
extern struct mt constructMonsterSA1_31();
extern struct mt constructMonsterSA1_6();
extern struct mt constructMonsterSC2();




struct mt {
  char name[75];
  char desc[150]; //description du monstre (pour l'histoire, plus simple a afficher directement dans fight();)

//stats
  int pv;
  int ad;
  int ap;
  int abilityReward;
  int itemReward;
  int arm;
  int crit;
  int spd;
};

#endif
