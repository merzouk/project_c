/**
* \file alloc_memory.c
* \brief Point d'entrée de l'allocation dynamique de mémoire.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gère l'allocation dynamique de mémoire :

*
*/

#include "header.h"

/**
* \fn char *alloc_memory(int size)
* \brief Fonction permettant d'allouer un tableau de char de taille size
*
* \param[in] size : taille du tableau de caractères
*
* \return char * : tableau de caractère de taille size.
*/

char *alloc_memory(int size)
{
	if(size <= 0)
		return NULL;
	char *tab;
	tab = (char*) calloc(size, sizeof(char));
	if(tab == NULL)
	{
		printf("Allocation dynamique est terminée par un échèc \n");
		return NULL;
	}
	return tab;
}
