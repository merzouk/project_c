/**
* \file cryptage.c
* \brief Point d'entrée du cryptage du contenu du fichier clair.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gère cryptage du contenu du fichier clair :
    - Lire le fichier source contenant le texte clair
	- Ecrire le texte chiffré dans le fichier destintation
*
*/

#include "header.h"


const char min_tt [26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y','z'};

const char maj_tt [26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y','Z'};

/**
* \fn int get_rang_maj(char c)
* \brief Fonction permettant de donner le rang dans l'alphabet d'un caractère c
*
* \param[in] c : le caractère dont on cherche le rang dans l'alphabet en lettre majiscule
* \return int : le rang de la lettre majiscule dans l'alphabet
*/
int get_rang_maj(char c)
{
	for(int i = 0 ; i < 26 ; i++)
	{
		if(c == maj_tt[i])
		{
			return i;
		}
	}
	return -1;
}

/**
* \fn int get_rang_min(char c)
* \brief Fonction permettant de donner le rang dans l'alphabet d'un caractère c
*
* \param[in] c : le caractère dont on cherche le rang dans l'alphabet en lettre miniscule
* \return int : le rang de la lettre miniscule dans l'alphabet
*/
int get_rang_min(char c)
{
	for(int i = 0 ; i < 26 ; i++)
	{
		if(c == min_tt[i])
		{
			return i;
		}
	}
	return -1;
}

/**
* \fn char * encrypt_source(const char *source, const char *cypher_key, const char *min, const char *maj)
* \brief Fonction permettant de crypter le texte clair source avec la clé de cryptage cypher_key
*
* \param[in] source : le texte clair à chiffrer
* \param[in] cypher_key : clé de chiffrement
* \param[in] min : lettre miniscule de l'alaphabet
* \param[in] maj : lettre majiscule de l'alaphabet
* \return char : contenu du texte crypté.
*/
char * encrypt_source(const char *source, const char *cypher_key, const char *min, const char *maj)
{
    char *target = NULL;
    if(check_datas(cypher_key, source) == -1)
    {
        target = alloc_memory(1);
		target[0] = '\0';
		return NULL;
    }
	unsigned size_key = strlen(cypher_key);
	char * src = NULL;
	char * key = NULL;

	src = alloc_memory(strlen(source) + 1);
	key = alloc_memory(strlen(cypher_key) + 1);
	target = alloc_memory(strlen(source) + 1);

	unsigned int i = 0;
	while(i < strlen(source))
	{
		src[i] = *(source +i);
		i++;
	}
	src[strlen(source)] = '\0';
	i = 0;
	while(i < strlen(cypher_key))
	{
		key[i] = *(cypher_key +i);
		i++;
	}
	key[strlen(cypher_key)] = '\0';
	for(i = 0 ; src[i] != '\0' ; i++)
	{
		if(src[i] >= 'a' && src[i] <= 'z' )
		{
			target[i] = min[(get_rang_min(src[i]) - get_rang_min(key[i%(size_key)]) + 26)%26];
		}
		else if(src[i] >= 'A' && src[i] <= 'Z')
		{
			target[i] = maj[(get_rang_maj(src[i]) - get_rang_min(key[i%(size_key)]) + 26)%26];
		}
		else
		{
			target[i] = src[i];
		}
	}
	target[strlen(src)] = '\0';
	return target;
}

/**
* \fn cryptage(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *pathFileNameCypher)
* \brief Fonction permettant l'entré dans le menu de decryptage le texte chiffré
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] pathFileNameCypherKey : chemin vers le fichier contenant la clé de chiffrement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffré
* \return void : sortie sans retour.
*/
void cryptage(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *pathFileNameCypher)
{
   char * clair = NULL;
   char * cypher_key = NULL;

   clair = read_source_from_file(pathFileNameTexte);

   cypher_key = read_source_from_file(pathFileNameCypherKey);

    printf("\n\nLa Cle de chiffremment = %s \ntexte clair = %s\n", cypher_key, clair);
	char * cypher = encrypt_source(clair, cypher_key, min, maj);
	printf("\nLe chiffre = %s   \n", cypher);

    write_cypher_in_file(cypher, pathFileNameCypher);
}

/**
* \fn void crypt_containt_file(const char *min, const char *maj)
* \brief Entrée de la fonction de cryptage.
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \return EXIT_SUCCESS - Arrêt normal du programme.
* \return EXIT_FAILURE - Arrêt anormal du programme.
*/
void crypt_containt_file(const char *min, const char *maj)
{

   const char *pathFileNameTexte = "F:/SECURITE/source.txt";
   const char *pathFileNameCypherKey = "F:/SECURITE/peroq.def";
   const char *pathFileNameCypher = "F:/SECURITE/dest.crt";
   cryptage(min, maj, pathFileNameTexte, pathFileNameCypherKey, pathFileNameCypher);
}
