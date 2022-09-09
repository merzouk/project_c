/**
* \file menu.c
* \brief Point d'entrée du menu.
* \author Merzouk MENHOUR
* \version 1.0
* \date 08 septembre 2022
*
* cette partie gère le menu principal :
            -1. Chiffrer un texte
       	    -2. Dechiffrer un texte
       	    -3. Chiffrer par saisi de cle
			-4. Dechiffrer par saisi de cle
			-5. Chiffrer par saisi des paths des fichiers
			-6. Dechiffrer par saisi des paths des fichiers
       	    -7. Supprimer le fichier source
			-8. Voir une demo
       	    -0. Quitter
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
* \fn void menu(char *min, char *maj)
* \brief Fonction permettant de gérer le menu par l'utilisateur
*
* \param[in] min : alphabet au miniscule
* \param[in] maj : alphabet au format majiscule
* \return void : Sortie du programme.
*/
void menu(const char *min, const char *maj)
{
	int menu = -1;
        do
    	{
    	    menu = -1;
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
            scanf("%d",&menu);
       	    if(check_value(menu) == 'K')
			{
				printf("\nVotre choix (%d) n'est pas correct, veuillez recommencer !!! \n",menu);
				continue;
			}
       	    printf("\n");

       	    switch(menu)
       		{
				case 0 :
				    printf("\nFin exécution du programme de cryptage de données \n");
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
}
