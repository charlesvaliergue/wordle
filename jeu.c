#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "chose_word.h"
#include "compare.h"
#include "recherche_dicotomique.h"
#include "load_dic.h"
#include "condition_passage.h"



/*Code du jeu, il faut juste traiter les cas qui bug dans la fonction compare
et on pourra la foutre ici*/ 


void jeu (char *biblio, char* mot_choisi)
{
	// Variables
	unsigned int len = 7980;
	int i = 6;
	char buffer[50];
	char **tab = load_file(biblio, &len);
	bool condition1 = true;
	bool condition2 = true;

	while (i > 0)
	{
		printf("Veuillez choisir un mot de 5 lettres en majuscule\n");
		scanf("%s",buffer);

		if (strlen (buffer) != 5)
		{
			// printf("Le mot saisi n'est pas de la bonne taille, retaper un mot de 5 lettres\n");
			condition1 = false;
			buffer = condition_passage1 (condition1);
		}

		if (find_word_dicho (tab,buffer,0,len) == false)
		{
			printf("Le mot saisi n'est pas français\n");
			// condition1 = false;
			condition2 = false;
			// condition_passage1 (condition1);
			buffer = condition_passage2 (tab,condition2);
		}

		if (strcmp(buffer,mot_choisi) == 0)
		{
			printf("Félicitations, vous avez trouvé le bon mot\n");
			return;
		}

		else
		{
			compare (buffer,mot_choisi);
			i--;
		}	
	}

	printf("Vous n'avez pas trouvé le bon mot au bout des 6 essais.\n");
	printf("Le bon mot était: %s\n",mot_choisi);
	return;
}

int main (int argc, char** argv)
{
	if (argc != 2)
	{
		printf ("ERREUR. Mauvais nb d'arg\n");
		return -1;
	}
	jeu(argv[1], piocher_mot(argv[1]));
}