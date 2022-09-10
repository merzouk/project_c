/**
* \file manage_file.c
* \brief Point d'entrée de la gestion de lecture et écriture de fichiers.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gere la lecture du fichier source du contenu clair, et l'ecriture dans le fichier destination du texte chiffre :
    - Lire le fichier source contenant le texte clair
	- Ecrire du texte chiffre dans le fichier destintation
*
*/

#include "header.h"

/**
* \fn char * read_source_from_file(char *pathFileName)
* \brief Fonction permettant de lire le texte clair depuis le fichier source dans le pathFileName est indique dans les parametres
*
* \param[in] pathFileName : chemin vers le fichier a lire
* \return char : contenu du texte clair.
*/
char * read_source_from_file(const char *pathFileName)
{
    FILE    *textfile;
    char    *text;
    long    numbytes;
	if(!pathFileName)
	{
		printf("Le fichier contenant le texte a chiffrer n'est pas renseigne %s ", pathFileName);
		return NULL;
	}
    textfile = fopen(pathFileName, "r");
    if(textfile == NULL)
    {
    	printf("\nErreur d'ouverture en lecture du fichier %s Programme termine en echec ", pathFileName);
        return NULL;
    }

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL)
        return NULL;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

    return text;
}


/**
* \fn void write_cypher_in_file(char *source, char * pathFileName)
* \brief Fonction permettant d'ecrire le texte chiffre source dans le fichier cible dans le pathFileName est indique dans les parametres
*
* \param[in] source : contenu a inserer
* \param[in] pathFileName : chemin vers le fichier a ouvrir en ecriture
* \return void : sortie sans retour.
*/
void write_cypher_in_file(char *source, const char * pathFileName)
{
	if(!pathFileName)
	{
		printf("Le fichier contenant le texte a chiffrer n'est pas renseigne %s ", pathFileName);
		return;
	}

	if(!source)
	{
		printf("Le contenu a inserer dans le fichier %s n'est pas renseigne %s ", pathFileName, source);
		return;
	}

    int length = 0;
    FILE *pfile = NULL;

   pfile = fopen(pathFileName, "w+t");
   if(pfile == NULL)
   {
     printf("Erreur d'ouverture pour ecriture du fichier %s Programme termine en echec.", pathFileName);
     return;
   }

   length = strlen( source );
   for(int i = 0 ; i < length ; i++)
   {
     fputc(*(source + i), pfile);
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

/**
* \fn int exists_file(const char *pathFileName)
* \brief Fonction permettant de verifier si un fichier existe ou pas
*
* \param[in] pathFileName : chemin vers le fichier
* \return void : sortie sans retour.
*/
int exists_file(const char *pathFileName)
{
    FILE * fichier = fopen(pathFileName, "r+");
    if (fichier == NULL)
    {
        printf("Le fichier %s n\'exixte pas", pathFileName);
        return 1;
    }
    else
    {
        fclose(fichier);
        return 0;
     }
}

/**
* \fn void delete_file_source(const char *pathFileNameTexte)
* \brief Fonction permettant de supprmer le fichier mis en parametre
*
* \param[in] pathFileNameTexte : le chemin vers le fichier a supprimer
* \return void : sortie sans retour.
*/
void delete_file_source(const char *pathFileNameTexte)
{
    printf("Etes vous sur de vouloir supprimer le fichier %s \n", pathFileNameTexte);
    printf("(1) pour oui et autre nombre pour non : ");
    if(choose() == 1)
    {
        if(exists_file(pathFileNameTexte) == 0)
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
}
