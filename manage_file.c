/**
* \file manage_file.c
* \brief Point d'entrée de la gestion de lecture et écriture de fichiers.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gère la lecture du fichier source du contenu clair, et l'écriture dans le fichier destination du texte chiffré :
    - Lire le fichier source contenant le texte clair
	- Ecrire du texte chiffré dans le fichier destintation
*
*/

#include "header.h"

/**
* \fn char * read_source_from_file(char *pathFileName)
* \brief Fonction permettant de lire le texte clair depuis le fichier source dans le pathFileName est indiqué dans les paramètres
*
* \param[in] pathFileName : Opérande 1
* \return char : contenu du texte clair.
*/
char * read_source_from_file(const char *pathFileName)
{
    FILE    *textfile;
    char    *text;
    long    numbytes;

    printf("reading file containt %s \n", pathFileName);
	if(!pathFileName)
	{
		printf("Le fichier contenant le texte à chiffrer n'est pas renseigné %s ", pathFileName);
		return NULL;
	}

    textfile = fopen(pathFileName, "r");
    if(textfile == NULL)
        return NULL;

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL)
        return NULL;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

    printf(text);

    return text;
}


/**
* \fn void write_cypher_in_file(char *source, char * pathFileName)
* \brief Fonction permettant d'écrire le texte chiffré source dans le fichier cible dans le pathFileName est indiqué dans les paramètres
*
* \param[in] source : Opérande 1
* \param[in] pathFileName : Opérande 2
* \return void : sortie sans retour.
*/
void write_cypher_in_file(char *source, const char * pathFileName)
{
    printf("\nWriting cypher text in file %s \n", pathFileName);
	if(!pathFileName)
	{
		printf("Le fichier contenant le texte a chiffrer n'est pas renseigne %s ", pathFileName);
		return;
	}

	if(!source)
	{
		printf("Le contenu a inserer dans le fichier n'est pas renseigne %s ", source);
		return;
	}

    int length = 0;
    FILE *pfile = NULL;

   pfile = fopen(pathFileName, "w+t");
   if(pfile == NULL)
   {
     printf("Error opening %s for writing. Program terminated.", pathFileName);
     return;
   }

   length = strlen( source );
   for(int i = 0 ; i < length ; i++)
   {
     fputc(*(source + i), pfile);  /* Write string to file backwards */
   }
   fclose(pfile);
   printf("Ecriture dans le fichier %s s'est terminee avec succes ",pathFileName);
}

char choose()
{
    int choix;
    fflush(stdin);
    scanf("%d", &choix);
    return choix;
}

void delete_file_source()
{
    const char *pathFileNameTexte = "F:/SECURITE/source.txt";
    printf("Etes vous sur de vouloir supprimer le fichier %s \n", pathFileNameTexte);
    printf("(1) pour oui et autre nombre pour non : ");
    if(choose() == 1)
    {
        if (remove(pathFileNameTexte) == 0)
            {
            printf("\nLe fichier %s est supprime avec succes.", pathFileNameTexte);
        }
        else
        {
            printf("\nLe fichier  %s n'est pas supprime.", pathFileNameTexte);
        }
    }
}
