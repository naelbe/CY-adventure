#include "../system/sys.h"
#include "../system/type.h"

void endLose(int reason) {
  
  type("Vous etes mort...\nParfois, la prudence est plus importante que la gloire...\n");
  switch (reason) {
    
    case 1 :
    type("-> La confiance est importante, mais connaitre vos limites l'est aussi.\n");
    sleep(2);
    break;
    
    case 3 : // etape 1, mort gaby
      type("Vous etes tombes un piege qui etait surement inevitable...");
      sleep(2);
      type("Vous venez d'etre libere de ce bas monde...");
      sleep(2);
    break;
    
    case 4 : // etape 1, mort gaby
      type("Vous venez d'etre libere de ce bas monde...");
      sleep(2);
    break;

    case 5 : 
    type("Votre appetit pour le combat etait sans doute demesure\n");
    sleep(1);
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;
    
    case 2 :
    type("");
    sleep(2);
    break;

    case 6:
    type("Vous avez choisis de combattre avec l'arme de votre maitre, malheureusement vous vous faites dechiqueter");
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;

    case 7: 
    type("mauvaise reponse\n");
    sleep(2);
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;

    case 8 :
    type("Mauvaise reponse vous allez mourir ! ");
    type("AAAAHHHHH !");
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;

    case 12 :
    type("Vous n'avez pas utilise la le sort d'annulation?\n Cela aurait pourtant pu etre utile");
    type("La legende disait qu'un Gardien de la Porte, etait invincible...");
    sleep(2);
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;
    
    case 13 :  
      type("Parfois il est sage d'oublier le passe et d'avancer pour devenir meilleur\n");
    type("Votre epee s'est brisee face a ce terrible monstre\n Vous vous etes fait abattre...\n");
    type("AAAAHHHHH !\n");
    type(". . . ");
    sleep(2);
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;

    case 14 :
    type("Nous vous avions dit de faire preuve de bonte, mais aussi de discernement et de courage ! Epargner votre pire ennemi n'est clairement pas la meilleure des idees...\n");
      type("Vous venez d'etre libere de ce bas monde...");
      sleep(2);
    break;
    
    case 15:
    type("Vous vous etes laisse depasse par les evenements, restez calme la prochaine fois...\n");
    type("Vous venez d'etre libere de ce bas monde...");
      sleep(2);
    break;

    case 16 :
    type("Vous avez perdu le combat, mais vous vous etes battu avec courage ! Re-tentez votre chance et terassez votre adversaire\n");
    type("Vous venez d'etre libere de ce bas monde...");
      sleep(2);
    break;

    case 17 :
    type("il etait bien trop innocent pour faire partie du camp de Rakai, vous avez manque de discernement...\n");
      type("Vous venez d'etre libere de ce bas monde...");
      sleep(2);
    break;

    case 18 :
    type("Ce choix n'etait pas evident, mais akashi regrette sincerement d'avoir servis Rakai, et il sera pret a vous aider a le battre...\n");
    type("Vous venez d'etre libere de ce bas monde...");
      sleep(2);
    break;

    case 19 :
    type("Vous avez ete aveugle par votre quete de puissance, cette relique etait un piege !\n");
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;

    case 20 :
    type("tu n'as pas suivi le guerrier. Malheureusement, apres des heures de marches tu te perds et tu meurs de soif");
      type("Vous venez d'etre libere de ce bas monde...");
      sleep(2);
    break;

    case 21 :
    type("tu n'as pas fait preuve d'honneur, Ton guerrier s'est suicide par culpabilite");
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;

    case 22 :
    type("Tu cherches maintenant la sorti de ce labyrinthe. Malheureusement apres des heures de marche tu remarques que tu tournes en boucle. Vous mourrez !");
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;

    case 30 :
    type("C'est malheuresement la mauvaise reponse la statue se bloque a jamais, vous vous retrouvez coince dans cette grotte !");
    sleep(2);
    break;

    case 99 :  
    type("Vous venez de vous faire ecraser par la porte\n");
    type("Votre maitre vous a toujours eleve avec la notion de respect\n");
    sleep(2);
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;

    case 52 :
    type("Vous n'etes qu'un trouillard, vous fuyez !\n");
    type("Vous etes indigne d'etre chevalier\n");
    type("De plus en descendez les escaliers vous y trouvez des singes enrages qui vous tueent sur le champ...");
    sleep(2);
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;

    case 53 :
    type("Vous etes mort !");
    sleep(2);
    type("Vous venez d'etre libere de ce bas monde...");
    sleep(2);
    break;
  }
}
