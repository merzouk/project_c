
/**
* \file saisie_manuelle.c
* \brief Point d'entrée de la gestion de la saisie manuelle de la cle de chiffrement et du texte.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gère l'allocation dynamique de mémoire :

*
*/

#include "header.h"


int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
    int r = -1;
    // On lit le texte saisi au clavier
    if (fgets(chaine, longueur, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }
        r = 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
    else
    {
        r = 0; // On renvoie 0 s'il y a eu une erreur
    }
    return r;
}


char * read_key()
{
    char buffer[100];
    scanf("%s", buffer);
    char *p = NULL;
    p = buffer;
    return p;

}

/**
* \fn void saisie_cle_chiffrement(const char * min, const char * maj);
* \brief Fonction permettant de saisir manuellement la cle de chiffrement
*
* \param[in] min : lettre miniscule de l'alaphabet
* \param[in] maj : lettre majiscule de l'alaphabet
*
* \return void : retour sans valeur.
*/
void saisie_cle_chiffrement(const char * min, const char * maj)
{
    const char *pathFileNameTexte = "F:/SECURITE/source.txt";
    const char *pathFileNameCypher = "F:/SECURITE/dest.crt";
    char cypher_key[100];
    printf("Votre cle pour chiffrer  ?");
    scanf("%s", cypher_key);
    printf("%s ",cypher_key);
    crypt_containt_file_key(min, maj, pathFileNameTexte, pathFileNameCypher, cypher_key);
}

/**
* \fn void saisie_cle_dechiffrement(const char * min, const char * maj);
* \brief Fonction permettant de saisir manuellement la cle de dechiffrement
*
* \param[in] min : lettre miniscule de l'alaphabet
* \param[in] maj : lettre majiscule de l'alaphabet
*
* \return void : retour sans valeur.
*/
void saisie_cle_dechiffrement(const char * min, const char * maj)
{
    const char *pathFileNameTexte = "F:/SECURITE/source.txt";
    const char *pathFileNameCypher = "F:/SECURITE/dest.crt";
    char cypher_key[100];
    printf("Votre cle pour dechiffrer  ?");
    scanf("%s", cypher_key);
    printf("%s ",cypher_key);
    decrypt_containt_file_cle(min, maj, pathFileNameTexte, pathFileNameCypher, cypher_key);
}

