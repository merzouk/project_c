/**
* \file cryptage.c
* \brief Point d'entree du cryptage du contenu du fichier clair.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gere cryptage du contenu du fichier clair :
    - Lire le fichier source contenant le texte clair
	- Ecrire le texte chiffré dans le fichier destintation
*
*/

#include "header.h"

/**
* \fn int get_rang_maj(char c)
* \brief Fonction permettant de donner le rang dans l'alphabet d'un caractere c
*
* \param[in] c : le caractere dont on cherche le rang dans l'alphabet en lettre majiscule
* \param[in] maj : l'alphabet en lettre au format majiscule
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
* \brief Fonction permettant de donner le rang dans l'alphabet d'un caractere c
*
* \param[in] c : le caractere dont on cherche le rang dans l'alphabet en lettre miniscule
* \param[in] min : l'alphabet en lettre au format miniscule
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
* \brief Fonction permettant de crypter le texte clair source avec la cle de cryptage cypher_key
*
* \param[in] source : le texte clair a chiffrer
* \param[in] cypher_key : cle de chiffrement
* \param[in] min : Liste des lettres de l'alaphabet au format miniscule
* \param[in] maj : Liste des lettres de l'alaphabet au format majiscule
* \return char : contenu du texte crypte.
*/
char * encrypt_source(const char *source, const char *cypher_key, const char *min, const char *maj)
{
    char *target = NULL;
    if(check_datas(cypher_key, source) == -1)
    {
		return NULL;
    }
	unsigned size_key = strlen(cypher_key);
	target = alloc_memory(strlen(source) + 1);
	for(unsigned int i = 0 ; source[i] != '\0' ; i++)
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
* \brief Fonction permettant l'entree dans le menu de decryptage du texte chiffre
* \param[in] min : alphabet au format miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] pathFileNameCypherKey : chemin vers le fichier contenant la cle de chiffrement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffre
* \return void : sortie sans retour.
*/
void cryptage(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *pathFileNameCypher)
{
   char * clair = NULL;
   char * cypher_key = NULL;
   clair = read_source_from_file(pathFileNameTexte);
   cypher_key = read_source_from_file(pathFileNameCypherKey);
   char * cypher = encrypt_source(clair, cypher_key, min, maj);
   write_cypher_in_file(cypher, pathFileNameCypher);
   free(cypher);
}

/**
* \fn void cryptage_saisie_cle(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *cypher_key)
* \brief Fonction permettant l'entree dans le menu de decryptage du texte chiffre
* \param[in] min : alphabet au format miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] cypher_key : la cle de chiffrement saisie manuellement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffre
* \return void : sortie sans retour.
*/
void cryptage_saisie_cle(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypher, const char *cypher_key)
{
    char * clair = NULL;
    clair = read_source_from_file(pathFileNameTexte);
	char * cypher = encrypt_source(clair, cypher_key, min, maj);
    write_cypher_in_file(cypher, pathFileNameCypher);
	free(cypher);
}

/**
* \fn void crypt_containt_file(const char *min, const char *maj)
* \brief Entree de la fonction de cryptage.
* \param[in] min : alphabet au format miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] cypher_key : la cle de chiffrement saisie manuellement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffre
* \return void - Arret normal du programme.
*/
void crypt_containt_file(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *pathFileNameCypher)
{
   cryptage(min, maj, pathFileNameTexte, pathFileNameCypherKey, pathFileNameCypher);
}

/**
* \fn void crypt_containt_file_key(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char * cypher_key)
* \brief Entree de la fonction de cryptage avec saisie manuelle de la cle et des chemins vers les fichiers.
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] cypher_key : la cle de chiffrement saisie manuellement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffre
* \return void -
*/
void crypt_containt_file_key(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypher, const char * cypher_key)
{
   cryptage_saisie_cle(min, maj, pathFileNameTexte, pathFileNameCypher, cypher_key);
}
