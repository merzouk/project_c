/**
* \file demo.c
* \brief Point d'entrée d'une démonstration du chiffeement et de déchiffrement.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gère une demo :

*
*/

#include "header.h"

const char min_t [26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y','z'};

const char maj_t [26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y','Z'};

/**
* \fn int main (void)
* \brief Entrée du programme.
* \return void - Arrêt normal du programme.
*/
void demo(void)
{
	char * source = "Hello tout le monde !";
	char * cypher_key = "crypto";
	printf("\n\nCle de chiffremment = %s \ntexte clair = %s\n", cypher_key, source);
	char * cypher = encrypt_source(source, cypher_key, min_t, maj_t);
	printf("\nLe chiffre = %s   \n", cypher);
	char * clair = decrypt_cypher(cypher_key, cypher, min_t, maj_t);
	printf("\nLe dichiffre = %s  \n", clair);

	printf("\n=================================================\n");

	char * source1 = "Hello tout le monde depuis paris!";
	char * cypher_key1 = "cryptographie";
	printf("\n\nCle de chiffremment = %s \ntexte clair = %s\n\n", cypher_key1, source1);
	char * cypher1 = encrypt_source(source1, cypher_key1, min_t, maj_t);
	printf("\nLe chiffre =  %s\n", cypher1);
	char * clair1 = decrypt_cypher(cypher_key1, cypher1, min_t, maj_t);
	printf("\nLe dichiffre = %s  \n", clair1);
}
