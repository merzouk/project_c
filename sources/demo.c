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

#include "../header/header.h"


/**
* \fn int main (void)
* \brief Entrée du programme.
* \return void - Arrêt normal du programme.
*/
void demo(char *min, char *maj)
{
    printf("\n=================== Debut Demo ========================\n");

    printf("\n=================== Exemple 1 ========================\n");
	char * source = "Hello tout le monde !";
	char * cypher_key = "crypto";
	printf("\n\nCle de chiffremment = %s \ntexte clair = %s\n", cypher_key, source);
	char * cypher = encrypt_source(source, cypher_key, min, maj);
	printf("\nLe chiffre = %s   \n", cypher);
	char * clair = decrypt_cypher(cypher_key, cypher, min, maj);
	printf("\nLe dichiffre = %s  \n", clair);

    printf("\n=================== Exemple 2 ========================\n");

	char * source1 = "Hello tout le monde depuis paris!";
	char * cypher_key1 = "crYptoGraphie";
	printf("\n\nCle de chiffremment = %s \ntexte clair = %s\n\n", cypher_key1, source1);
	char * cypher1 = encrypt_source(source1, cypher_key1, min, maj);
	printf("\nLe chiffre =  %s\n", cypher1);
	char * clair1 = decrypt_cypher(cypher_key1, cypher1, min, maj);
	printf("\nLe dichiffre = %s  \n", clair1);

    printf("\n=================== Exemple 3 ========================\n");

	char * source2 = "Hello tout le monde depuis paris!";
	char * cypher_key2 = "cryptographie";
	printf("\n\nCle de chiffremment = %s \ntexte clair = %s\n\n", cypher_key2, source2);
	char * cypher2 = encrypt_source(source2, cypher_key2, min, maj);
	printf("\nLe chiffre =  %s\n", cypher2);
	char * clair2 = decrypt_cypher(cypher_key2, cypher2, min, maj);
	printf("\nLe dichiffre = %s  \n", clair2);


	printf("\n=================== Exemple 4 ========================\n");

	char * source3 = "Hello tout le monde depuis paris!";
	char * cypher_key3 = "haropiro";
	printf("\n\nCle de chiffremment = %s \ntexte clair = %s\n\n", cypher_key3, source3);
	char * cypher3 = encrypt_source(source3, cypher_key3, min, maj);
	printf("\nLe chiffre =  %s\n", cypher3);
	char * clair3 = decrypt_cypher(cypher_key3, cypher3, min, maj);
	printf("\nLe dichiffre = %s  \n", clair3);

	printf("\n=================== Fin demo ========================\n");
}
