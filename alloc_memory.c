/**
* \file alloc_memory.c
* \brief Point d'entree de l'allocation dynamique de memoire.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gere l'allocation dynamique de memoire :

*
*/

#include "header.h"

/**
* \fn char *alloc_memory(int size)
* \brief Fonction permettant d'allouer un tableau de char de taille size
*
* \param[in] size : taille du tableau de caracteres
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
		printf("Allocation dynamique est terminee par un echec \n");
		return NULL;
	}
	return tab;
}
