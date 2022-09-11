/**
* \file menu.c
* \brief Point d'entrée du menu.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gère le menu principal :
   - 1. Chiffrer un texte
   - 2. Dechiffrer un texte
   - 3. Chiffrer par saisi de cle
   - 4. Dechiffrer par saisi de cle
   - 5. Chiffrer par saisi des paths des fichiers
   - 6. Dechiffrer par saisi des paths des fichiers
   - 7. Supprimer le fichier source
   - 8. Voir une demo
   - 0. Quitter
*
*/

#include "header.h"
#include "file.h"

/**
* \fn void mmenu (void)
* \brief Entrée de la gestion du menu principal.
*
*/


/**
* \fn char check_value(int choose)
* \brief Fonction permettant de vérifier la valeur saisie par l'utilisateur
*
* \param[in] choose : Opérande 1
* \return char : Valeur indiquant si le choix de l'utilisateur est correct ou pas.
*/
char check_value(int choose)
{
	if(choose >= 0 && choose <= 8)
	{
		return 'O';
	}
	return 'K';
}

/**
* \fn int length(char * str)
* \brief Fonction permettant de calculer la logueur de la chaine de caracteres
*
* \param[in] str : chaine de caracteres
* \return int : longueur de la chaine
*/
int length(char * str)
{
    if(!str) return 0;
    int length = 0;
    while(*(str + length) != '\0') length++;
    return length;
}

/**
* \fn void string_copy(char *src, char * dest)
* \brief Fonction permettant de copier le contenu de la chaine src vers la chaine dest
*
* \param[in] src : chaine de caracteres a copier
* \param[in] dest : chaine de caracteres ver laquelle on copie le contenu de la chaine src
* \return void : sans retour
*/
void string_copy(char *src, char * dest)
{
    int length_dst = length(dest);
    if(length_dst == 0)
    {
        int i = 0;
		int j = length_dst;
        while (*(src + i))
		{
            *(dest + j) = *(src + i);
			i++;
			j++;
        }
        *(dest + j) = '\0';
    }
    else
    {
        int i = 0;
        int j = length_dst;
        while (*(src + i )) {
            *(dest + j) = *(src + i);
            i++;
            j++;
        }
        *(dest + j) = '\0';
    }
}

/**
* \fn char infos_messages()
* \brief Fonction permettant d'afficher les messages du menu
*
* \return void : sortie sans retour.
*/
void infos_messages()
{
	    printf("\n----------------------- MENU -----------------------\n");
   	    printf("1. Chiffrer un texte\n");
   	    printf("2. Dechiffrer un texte  \n");
   	    printf("3. Chiffrer par saisi de cle \n");
     	printf("4. Dechiffrer par saisi de cle \n");
		printf("5. Chiffrer par saisi des paths des fichiers \n");
		printf("6. Dechiffrer par saisi des paths des fichiers \n");
        printf("7. Supprimer le fichier source \n");
		printf("8. Voir une demo \n");
        printf("0. Quitter \n");
        printf("Votre choix : ");
}

/**
* \fn int get_choose_for_menu()
* \brief Fonction permettant la saisie du choix pour le menu
*
* \return menu : le choix du menu allant de 0 a 8
*/
int get_choose_for_menu()
{
     char res = 'S';
     int menu = -1;
	 do{
        infos_messages();
        scanf("%d",&menu);
        res = check_value(menu);
        if(res == 'K')
        {
            printf("\nVotre choix (%d) n'est pas correct, veuillez recommencer !!! \n",menu);
            continue;
        }
	 }while(res == 'K');
	 printf("\n");
     return menu;
}

/**
* \fn int menu(const char *min, const char *maj, int argc, char **argv)
* \brief Fonction permettant de gérer le menu par l'utilisateur
*
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \param[in] argc : le nombre d'arguments fournis a l'entree du programme
* \param[in] argv : la liste des arguments fournis a l'entree du programme
* \return 0 : Sortie normal du programme.
* \return 1 : Sortie en erreur du programme
*/
int menu(const char *min, const char *maj, int argc, char **argv)
{
	int menu = -1;
    do
    {
        switch(menu = get_choose_for_menu())
       	{
        case 0 :
        	printf("\nFin execution du programme de cryptage de donnees \n");
        	break;
        case 1 :
        	crypt_containt_file(min, maj, pathFileNameTexte, pathFileNameCypherKey, pathFileNameCypher);
        	break;
        case 2 :
        	decrypt_containt_file(min, maj, pathFileNameTexte, pathFileNameCypherKey, pathFileNameCypher);
        	break;
        case 3:
        	saisie_cle_chiffrement(min, maj, pathFileNameTexte, pathFileNameCypher);
        	break;
        case 4:
        	saisie_cle_dechiffrement(min, maj, pathFileNameTexte, pathFileNameCypher);
        	break;
        case 5:
        	saisie_fichiers_chiffrement(min, maj);
        	break;
        case 6:
        	saisie_fichiers_dechiffrement(min, maj);
        	break;
        case 7:
        	delete_file_source(pathFileNameTexte);
        	break;
        case 8:
        	demo(min, maj);
        	break;
       	}
    }while (menu!=0);
    printf("Sortie du programme \n");
    return 0;
}
