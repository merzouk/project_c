/**
* \file main.c
* \brief Point d'entree.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* Programme permettant a partir d'une cle, crypter et décrypter un texte :
    - Le texte source est lu dans un fichier source.txt
	- Le texte crypte est depose dans le fichier dest.crt
	- Le programme est gere par un menu par lequel l'utilisateur choisi ce qu'il fait.
	- 1 cas L'utilisateur doit indiquer le chemin vers le dossier contenant le fichier source.
	-       L'utilisateur doit indiquer le chemin vers le dossier dans lequel le fichier du texte crypter doit etre depose
	-       L'utilisateur doit indiquer le chemin vers le dossier dans lequel se trouve le fichier contenant la cle de cryptage
	- 2 cas L'utilisateur doit indiquer le chemin vers le dossier contenant le fichier crypte.
	-       L'utilisateur doit indiquer le chemin vers le dossier dans lequel le fichier du texte clair doit etre depose
	-       L'utilisateur doit indiquer le chemin vers le dossier dans lequel se trouve le fichier contenant la cle de cryptage
	- 3 cas L'utilisateur doit indiquer le chemin vers le dossier contenant le fichier crypte par saisie manuelle
	-       L'utilisateur doit indiquer le chemin vers le dossier dans lequel le fichier du texte clair doit etre depose par saisie manuelle
	-       L'utilisateur doit indiquer le chemin vers le dossier dans lequel se trouve le fichier contenant la cle de cryptage par saisie manuelle

*
*/

#include "header.h"
#include "ressources.h"

/**
* \fn int main (void)
* \brief Entree du programme.
* \param[in] min : alphabet au format miniscule
* \param[in] maj : alphabet au format majiscule
* \return 0 - Arret normal du programme.
* \return 1 - Arret anormal du programme.
*/

int main(int argc, char **argv)
{
    launch_menu(min, maj, argc, argv);
    return 0;
}
