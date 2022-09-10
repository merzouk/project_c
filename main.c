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
	- L'utilisateur doit indiquer le chemin vers le dossier contenant le fichier source.
	- L'utilisateur doit indiquer le chemin vers le dossier dans lequel le fichier crypter doit etre depose
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
    menu(min, maj, argc, argv);
    return 0;
}
