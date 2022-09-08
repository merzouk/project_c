/**
* \file decryptage.c
* \brief Point d'entrée du décryptage du contenu du fichier crypté.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gère le décryptage du contenu du fichier crypté :
	 - Lire le fichier source contenant le texte chiffré
	 - Ecrire le texte clair dans le fichier destintation
*
*/

#include "header.h"

/**
* \fn int check_datas(const char * cypher_key, const char * source)
* \brief Fonction permettant de vérifier le contenu du texte clair ou chiffré source plus la clé de chiffremennt cypher_key
*
* \param[in] cypher_key : clé de chiffrement
* \param[in] source : texte chiffrer à déchiffrer
* \return int : 0 si le contenu est correct -1 sinon
*/
int check_datas(const char * cypher_key, const char * source)
{
	if(!source || strlen(source) == 0)
	{
        printf("\nLe texte chiffre %s n'est pas renseigne, cryptage/decryptage impossible\n",source);
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
* \brief Fonction permettant de decrypter le texte crypté contenu dans le fichier source avec la clé de decryptage cypher_key
*
* \param[in] cypher_key : clé de chiffrement
* \param[in] source : texte chiffrer à déchiffrer
* \param[in] min : lettre miniscule de l'alaphabet
* \param[in] maj : lettre majiscule de l'alaphabet
* \return char : contenu du texte decrypté.
*/
char * decrypt_cypher(const char * cypher_key, const char * source, const char *min, const char *maj)
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
	src = alloc_memory(strlen(source) + 1);
	char * key = NULL;
	key = alloc_memory(strlen(cypher_key) + 1);
	target = alloc_memory(strlen(source) + 1);
	unsigned int i = 0;
	while(*(source + i) != '\0')
	{
		src[i] = *(source +i);
		i++;
	}
	src[strlen(source)] = '\0';
	i = 0;
	while(*(cypher_key + i) != '\0')
	{
		key[i] = *(cypher_key +i);
		i++;
	}
	key[strlen(cypher_key)] = '\0';

	for(i = 0 ; src[i] != '\0' ; i++)
	{
		if(((int)(src[i]) >= (int)('a') && (int)(src[i]) <= (int)('z')))
		{
			int rang = (get_rang_min(src[i]) + get_rang_min(key[i%(size_key)]) + 26)%26;
			target[i] = min[rang];
		}
		else if(((int)(src[i]) >= (int)('A') && (int)(src[i]) <= (int)('Z')))
		{
			int rang = (get_rang_maj(src[i]) + get_rang_min( key[i%(size_key)]) + 26)%26;
			target[i] = maj[rang];
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
* \fn void decryptage()
* \brief Fonction permettant l'entré dans le menu de decryptage le texte chiffré
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] pathFileNameCypherKey : chemin vers le fichier contenant la clé de chiffrement
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffré
* \return void : sortie sans retour.
*/
void decryptage(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *pathFileNameCypher)
{
   char * cypher = NULL;
   char * cypher_key = NULL;

   cypher = read_source_from_file(pathFileNameCypher);

   cypher_key = read_source_from_file(pathFileNameCypherKey);

   char * clair = decrypt_cypher(cypher_key, cypher, min, maj);
   printf("clair = %s ", clair);
   write_cypher_in_file(clair, pathFileNameTexte);
}

/**
* \fn int main (void)
* \brief Entrée de la fonction de decryptage.
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \return EXIT_SUCCESS - Arrêt normal du programme.
* \return EXIT_FAILURE - Arrêt anormal du programme.
*/
void decrypt_containt_file(const char *min, const char *maj)
{
   const char *pathFileNameTexte = "F:/SECURITE/source.txt";
   const char *pathFileNameCypherKey = "F:/SECURITE/peroq.def";
   const char *pathFileNameCypher = "F:/SECURITE/dest.crt";
   decryptage(min, maj, pathFileNameTexte, pathFileNameCypherKey, pathFileNameCypher);
}


