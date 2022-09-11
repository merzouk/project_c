/**
* \file decryptage.c
* \brief Point d'entree du decryptage du contenu du fichier crypte.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gere le decryptage du contenu du fichier crypte :
	 - Lire le fichier source contenant le texte chiffre
	 - Ecrire le texte clair dans le fichier destintation
*
*/

#include "header.h"

/**
* \fn int check_datas(const char * cypher_key, const char * source)
* \brief Fonction permettant de verifier le contenu du texte clair ou chiffre source plus la cle de chiffremennt cypher_key
*
* \param[in] cypher_key : cle de chiffrement
* \param[in] source : texte chiffrer a dechiffrer ou clair a chiffrer
* \return int : 0 si le contenu est correct -1 sinon
*/
int check_datas(const char * cypher_key, const char * source)
{
	if(!source || strlen(source) == 0)
	{
        printf("\nLe texte clair/chiffre %s n'est pas renseigne, cryptage/decryptage impossible\n",source);
		return -1;
	}
	if(!cypher_key || strlen(cypher_key) == 0)
	{
		printf("\nLa cle de chiffrement non renseignee %s, cryptage/decryptage impossible \n", cypher_key);
		return -1;
	}
	return 0;
}

/**
* \fn char * decrypter(const char *cypher_key, const char * source)
* \brief Fonction permettant de decrypter le texte crypte contenu dans le fichier source avec la cle de decryptage cypher_key
*
* \param[in] cypher_key : cle de chiffrement
* \param[in] source : texte chiffrer a dechiffrer
* \param[in] min : lettre au format miniscule de l'alaphabet
* \param[in] maj : lettre au format majiscule de l'alaphabet
* \return char : contenu du texte decrypte.
*/
char * decrypt_cypher(const char * cypher_key, const char * source, const char *min, const char *maj)
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
		if(((int)(source[i]) >= (int)('a') && (int)(source[i]) <= (int)('z')))
		{
			target[i] = min[(get_rang_min(source[i], min) + get_rang_min(cypher_key[i%(size_key)], min) + 26)%26];
		}
		else if(((int)(source[i]) >= (int)('A') && (int)(source[i]) <= (int)('Z')))
		{
			target[i] = maj[(get_rang_maj(source[i], maj) + get_rang_min( cypher_key[i%(size_key)], min) + 26)%26];
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
* \fn void decryptage()
* \brief Fonction permettant l'entre dans le menu de decryptage le texte chiffre
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] pathFileNameCypherKey : chemin vers le fichier contenant la cle de chiffrement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffre
* \return void : sortie sans retour.
*/
void decryptage(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *pathFileNameCypher)
{
   char * cypher = NULL;
   char * cypher_key = NULL;
   cypher = read_source_from_file(pathFileNameCypher);
   cypher_key = read_source_from_file(pathFileNameCypherKey);
   char * clair = decrypt_cypher(cypher_key, cypher, min, maj);
   write_cypher_in_file(clair, pathFileNameTexte);
}

/**
* \fn void cryptage_saisie_cle(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *cypher_key)
* \brief Fonction permettant l'entre dans le menu de decryptage le texte chiffre par sais de la cle
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] cypher_key : la cle de dechiffrement saisie manuellement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffre
* \return void : sortie sans retour.
*/
void decryptage_saisie_cle(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypher, const char *cypher_key)
{
   char * cypher = NULL;
   cypher = read_source_from_file(pathFileNameCypher);
   char * clair = decrypt_cypher(cypher_key, cypher, min, maj);
   write_cypher_in_file(clair, pathFileNameTexte);
}

/**
* \fn void decrypt_containt_file(const char *min, const char *maj, const char *pathFileNameTexte,  const char *pathFileNameCypherKey, const char *pathFileNameCypher)
* \brief Entree de la fonction de decryptage.
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] cypher_key : la cle de dechiffrement saisie manuellement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffre
* \return void : sortie sans retour.
*/
void decrypt_containt_file(const char *min, const char *maj, const char *pathFileNameTexte,  const char *pathFileNameCypherKey, const char *pathFileNameCypher)
{
   decryptage(min, maj, pathFileNameTexte, pathFileNameCypherKey, pathFileNameCypher);
}

/**
* \fn int main (void)
* \brief Entree de la fonction de decryptagepar sais de cle.
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] cypher_key : la cle de dechiffrement saisie manuellement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffre
* \return void - Arrêt normal du programme.
*/
void decrypt_containt_file_cle(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypher, const char * cypher_key)
{
   decryptage_saisie_cle(min, maj, pathFileNameTexte, pathFileNameCypher, cypher_key);
}
