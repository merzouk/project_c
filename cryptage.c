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

/**
* \fn int get_rang_maj(char c)
* \brief Fonction permettant de donner le rang dans l'alphabet d'un caractère c
*
* \param[in] c : le caractère dont on cherche le rang dans l'alphabet en lettre majiscule
* \param[in] maj : l'alphabet en lettre majiscule
* \return int : le rang de la lettre majiscule dans l'alphabet
*/
int get_rang_maj(char c, const char *maj)
{
	for(int i = 0 ; i < 26 ; i++)
	{
		if(c == maj[i])
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
* \param[in] min : l'alphabet en lettre miniscule
* \return int : le rang de la lettre miniscule dans l'alphabet
*/
int get_rang_min(char c, const char *min)
{
	for(int i = 0 ; i < 26 ; i++)
	{
		if(c == min[i])
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

	target = alloc_memory(strlen(source) + 1);

	unsigned int i = 0;
	for(i = 0 ; source[i] != '\0' ; i++)
	{
		if(source[i] >= 'a' && source[i] <= 'z' )
		{
			target[i] = min[(get_rang_min(source[i], min) - get_rang_min(cypher_key[i%(size_key)], min) + 26)%26];
		}
		else if(source[i] >= 'A' && source[i] <= 'Z')
		{
			target[i] = maj[(get_rang_maj(source[i], maj) - get_rang_min(cypher_key[i%(size_key)], min) + 26)%26];
		}
		else
		{
			target[i] = source[i];
		}
	}
	target[strlen(source)] = '\0';
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
* \fn void cryptage_saisie_cle(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *cypher_key)
* \brief Fonction permettant l'entré dans le menu de decryptage le texte chiffré
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] cypher_key : la clé de chiffrement saisie manuellement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffré
* \return void : sortie sans retour.
*/
void cryptage_saisie_cle(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypher, const char *cypher_key)
{
    char * clair = NULL;
    clair = read_source_from_file(pathFileNameTexte);
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
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] cypher_key : la clé de chiffrement saisie manuellement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffré
* \return void - Arrêt normal du programme.
*/
void crypt_containt_file(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *pathFileNameCypher)
{
   cryptage(min, maj, pathFileNameTexte, pathFileNameCypherKey, pathFileNameCypher);
}

/**
* \fn void crypt_containt_file_key(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char * cypher_key)
* \brief Entrée de la fonction de cryptage avec saisie manuelle de la cle.
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] cypher_key : la clé de chiffrement saisie manuellement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffré
* \return void -
*/
void crypt_containt_file_key(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypher, const char * cypher_key)
{
   cryptage_saisie_cle(min, maj, pathFileNameTexte, pathFileNameCypher, cypher_key);
}

