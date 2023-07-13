#include "../header/header.h"

/**
* \fn int length(char * str)
* \brief Fonction permettant de calculer la logueur de la chaine de caracteres
*
* \param[in] str : chaine de caracteres
* \return int : longueur de la chaine
*/
int length(char * str)
{
    if(!str) return 0;
    int length = 0;
    while(*(str + length) != '\0') length++;
    return length;
}


/**
* \fn void string_copy(char *src, char * dest)
* \brief Fonction permettant de copier le contenu de la chaine src vers la chaine dest
*
* \param[in] src : chaine de caracteres a copier
* \param[in] dest : chaine de caracteres ver laquelle on copie le contenu de la chaine src
* \return void : sans retour
*/
char * str_copy(char * src, char * dest)
{
	if(!src && dest) return dest;
	if(!dest && src) return src;
	if(!src && !dest) return NULL;
	char *target = (char*) calloc((length(src) + length(dest) + 1), sizeof(char));
	int i = 0;
	while(*(dest + i) != '\0')
    {
		*(target + i) = *(dest + i);
		i++;
	}
	int j = 0;
	while(*(src + j) != '\0')
	{
		*(target +i) = *(src +j);
		i++;
		j++;
	}
	*(target + i) = '\0';
	return target;
}

/**
* \fn void string_copy(char *src, char * dest)
* \brief Fonction permettant de copier le contenu de la chaine src vers la chaine dest
*
* \param[in] src : chaine de caracteres a copier
* \param[in] dest : chaine de caracteres ver laquelle on copie le contenu de la chaine src
* \return void : sans retour
*/
void string_copy(char *src, char * dest)
{
    int length_dst = length(dest);
    if(length_dst == 0)
    {
        int i = 0;
		int j = length_dst;
        while (*(src + i))
	{
            *(dest + j) = *(src + i);
			i++;
			j++;
        }
        *(dest + j) = '\0';
    }
    else
    {
        int i = 0;
        int j = length_dst;
        while (*(src + i )) 
	{
            *(dest + j) = *(src + i);
            i++;
            j++;
        }
        *(dest + j) = '\0';
    }
}
