# project_c
Projet c pour la formation C/C++ embarqué


compilation via le makefile : make

suppression des fichiers de lien et de l'exécutable : make mrproper

suppression des fichiers .o : make clean

génération d'un zip : make zip


exécution du projet : ./manage_cypher

Thème :

On souhaite à partir d’un fichier source, faire en sorte de le crypter en utilisant l’algorithme du « perroquet ».
Cet algorithme repose sur un mot (le perroquet) qui permet de crypter en calculant la différence ASCII caractère par caractère.
Illustration du principe du perroquet :

Mot source à crypter : Olivier

Perroquet : abcd

Résultat en calcul ascii

(‘O’-‘a’)(‘l’-‘b’)(‘i’-‘c’)(‘v’-‘d’)(‘i’-‘a’)(‘e’-‘b’)(‘r’-‘c’)

Résultat

Concaténation des codes ASCII


Contraintes : 

L’utilisateur devra lui-même définir son propre perroquet.

Celui qui crypte et qui décrypte doit donc connaître le mot (ou la phrase) du « perroquet ». 

On prévoira donc un fichier (« peroq.def ») contenant la chaine de caractères du perroquet.

On disposera de 2 fichiers :

Source (« source.txt ») : contenant le texte à crypter
Résultat (« dest.crt ») : contenant le texte crypté

Option :

De plus, on prévoira de supprimer la source après cryptage de telle manière à ne conserver que le fichier crypté.
