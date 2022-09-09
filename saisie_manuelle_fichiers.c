
/**
* \file saisie_manuelle_fichiers.c
* \brief Point d'entrée de la gestion de la saisie manuelle des paths vers les fichiers.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gère l'allocation dynamique de mémoire :

*
*/

#include "header.h"

/**
* \fn void saisie_cle_chiffrement(const char * min, const char * maj);
* \brief Fonction permettant de saisir manuellement les paths vers les fichiers et de la cle de chiffrement
*
* \param[in] min : lettre miniscule de l'alaphabet
* \param[in] maj : lettre majiscule de l'alaphabet
*
* \return void : retour sans valeur.
*/
void saisie_fichiers_chiffrement(const char * min, const char * maj)
{
    char pathFileTxt[50];
    char pathFileCypher[50];
    char cypher_key[100];
    printf("Votre cle pour chiffrer  ? ");
    scanf("%s", cypher_key);
    printf("Le path vers le fichier contenant le texte clair ? ");
    scanf("%s", pathFileTxt);
    printf("Le path vers le fichier contenant le texte chiffree ? ");
    scanf("%s", pathFileCypher);
    crypt_containt_file_key(min, maj, pathFileTxt, pathFileCypher, cypher_key);
}

/**
* \fn void saisie_cle_dechiffrement(const char * min, const char * maj);
* \brief Fonction permettant de saisir manuellement les paths des fichiers et de cle de dechiffrement
*
* \param[in] min : lettre miniscule de l'alaphabet
* \param[in] maj : lettre majiscule de l'alaphabet
*
* \return void : retour sans valeur.
*/
void saisie_fichiers_dechiffrement(const char * min, const char * maj)
{
    char pathFileTxt[50] ;
    char pathFileCypher[50] ;
    char cypher_key[100];
    printf("Votre cle pour dechiffrer  ? ");
    scanf("%s", cypher_key);
    printf("Le path vers le fichier contenant le texte clair ? ");
    scanf("%s", pathFileTxt);
    printf("Le path vers le fichier contenant le texte chiffree ? ");
    scanf("%s", pathFileCypher);
    decrypt_containt_file_cle(min, maj, pathFileTxt, pathFileCypher, cypher_key);
}
