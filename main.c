/**
* \file main.c
* \brief Point d'entrée.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* Programme permettant à partir d'une clé, crypter et décrypter un texte :
    - Le texte source est lu dans un fichier source.txt
	- Le texte crypté est déposé dans le fichier dest.crt
	- Le programme est géré par un menu par lequel l'utilisateur choisi ce qu'il fait.
	- L'utilisateur doit indiquer le chemin vers le dossier contenant le fichier source.
	- L'utilisateur doit indiquer le chemin vers le dossier dans lequel le fichier crypter doit être déposé
*
*/

#include "header.h"

/**
* \fn int main (void)
* \brief Entrée du programme.
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \return EXIT_SUCCESS - Arrêt normal du programme.
* \return EXIT_FAILURE - Arrêt anormal du programme.
*/

const char min [26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y','z'};

const char maj [26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y','Z'};

int main()
{
    menu(min, maj);
    printf("\n\n");
    return 0;
}
