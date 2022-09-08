/**
* \file header.h
* \brief Liste des Prototypes de Fonctions.
* \author Merzouk MENHOUR
* \version 1.0
* \date 8 septembre 2022
*/

#ifndef HEADER_H_FILE
#define HEADER_H_FILE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * read_source_from_file(const char *path);

void write_cypher_in_file(char *source, const char * path);

char * encrypt_source(const char *source, const char *cypher_key, const char *min, const char *maj);

void cryptage(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *pathFileNameCypher);

char * decrypt_cypher(const char * cypher_key, const char * source, const char *min, const char *maj);

void decryptage(const char *min, const char *maj, const char *pathFileNameTexte, const char *pathFileNameCypherKey, const char *pathFileNameCypher);

char check_value(int choose);

void menu(const char *min, const char *maj);

char * choose_cypher_key(int choose);

char *alloc_memory(int size);

int get_rang_maj(char c);

void crypt_containt_file(const char *min, const char *maj);

void decrypt_containt_file(const char *min, const char *maj);

int get_rang_min(char c);

void delete_file_source();

void demo();

int check_datas(const char * cypher_key, const char * source);

#endif
