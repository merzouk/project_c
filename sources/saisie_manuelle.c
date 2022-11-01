/**
* \file saisie_manuelle.c
* \brief Point d'entree de la gestion de la saisie manuelle de la cle de chiffrement.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
*   cette partie gere
    - la saisie manuelle de la cle de chiffrement et de dechiffrement
*/

#include "../header/header.h"

/**
* \fn void saisie_cle_chiffrement(const char * min, const char * maj, const char *pathFileNameTexte,  const char *pathFileNameCypher)
* \brief Fonction permettant de saisir manuellement la cle de chiffrement
*
* \param[in] min : lettre au format miniscule de l'alaphabet
* \param[in] maj : lettre au format majiscule de l'alaphabet
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffre
*
* \return void : retour sans valeur.
*/
void saisie_cle_chiffrement(const char * min, const char * maj, const char *pathFileNameTexte,  const char *pathFileNameCypher)
{
    char cypher_key[100];
    printf("Votre cle pour chiffrer  ? ");
    scanf("%s", cypher_key);
    crypt_containt_file_key(min, maj, pathFileNameTexte, pathFileNameCypher, cypher_key);
}

/**
* \fn void saisie_cle_dechiffrement(const char * min, const char * maj, const char *pathFileNameTexte, const char *pathFileNameCypher)
* \brief Fonction permettant de saisir manuellement la cle de dechiffrement
*
* \param[in] min : lettre au format miniscule de l'alaphabet
* \param[in] maj : lettre au format majiscule de l'alaphabet
* \param[in] pathFileNameTexte : chemin vers le fichier contenant le texte clair
* \param[in] pathFileNameCypher : chemin vers le fichier contenant le texte chiffre
*
* \return void : retour sans valeur.
*/
void saisie_cle_dechiffrement(const char * min, const char * maj, const char *pathFileNameTexte, const char *pathFileNameCypher)
{
    char cypher_key[100];
    printf("Votre cle pour dechiffrer  ? ");
    scanf("%s", cypher_key);
    decrypt_containt_file_cle(min, maj, pathFileNameTexte, pathFileNameCypher, cypher_key);
}

