Bienvenue sur notre projet CY-ADVENTURE !


FONCTIONALITES :

Ce projet est une histoire, contée depuis notre fichier main, qui charge lui même des fichiers d'étapes, contenant l'histoire.
Nous avons implementé le système de sauvegarde, qui inscrit les informations du joueur dans un fichier .txt.
Notre programme contient un système d'objet qui améliore les statistiques du joueur.
Notre programme contient un système de combat (très simple) avec les différents antagonistes de l'histoire.
Notre programme contient une représentation visuelle du livre de l'histoire.


COMMENT COMPILER :

Notre projet utilise ncurses, qui est contenu dans le dossier ncurses de notre projet, néanmoins il faut l'implementer dans le terminal avant de compiler en utilisant la commande suivante :
sudo apt-get install libncurses5-dev libncursesw5-dev

La makefile est fonctionelle, après avoir installé ncurses il suffit d'écrire la commande "make", puis d'éxécuter notre fichier "adventure".


COMMENT JOUER :

Le fonctionnement de notre projet est relativement simple : vous avez le choix entre créer une nouvelle partie ou récuperer une partie depuis une sauvegarde.
Lors de l'affichage de l'histoire, attendez que la phrase ai fini de s'inscrire, puis appuez sur entrée pour charger la phrase suivante. Si vous appuyez sur une autre touche,
le programme se figera une dizaine de secondes, avant de recharger la phrase actuelle par sécurité !

Quand vous etes amené a faire des choix, appuyez sur entrée pour fermer la page de texte, puis entrez votre choix.

Les combats se déroulent au tour a tour, vous avez le choix entre ajouter des stats à votre armure, ou attaquer.
Le combat possède des fonctionallités de coup critique et d'esquive afin de le rendre plus vivant.


LIMITES FONCTIONELLES :

Nous avons utilisé ncurses afin d'ajouter un petit plus visuel, mais il est possible d'avoir des problèmes d'affichage à certains moments :
il se peut que l'écran devienne gris lors de certaines étapes, même si cela est vraiment rare, à cause des intéractions entre la version modifiée du terminal par ncurses
et les fonctions utilisant les fonctionalités de base du terminal.

Enfin, le dernier bug possible est lors de l'ouverture d'un fichier de sauvegarde : 
si le fichier entré n'éxiste pas, le programe crashera. Nous n'avons pas pu résoudre ce problème 
par manque de temps et du fait que nous ne pouvons pas vraiment garder une trâce des fichiers présent dans un répértoire en c.