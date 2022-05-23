#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "recherche_dicotomique.h"
#include "load_dic.h"

char buffer[50];

char *condition_passage1 (bool condition)
{
	while (condition != true)
	{
		printf("Veuillez saisir à nouveau un mot de bonne taille\n");
		scanf("%s",buffer);
		printf ("\n");
		if (strlen(buffer) == 5)
		{
			condition = true;
		}
	}

	return buffer;
}


char *condition_passage2 (char **tab, bool condition)
{
	while (condition == false)
	{
		printf("Veuillez saisir à nouveau un mot français, de bonne taille et en majuscule\n");
		scanf("%s",buffer);
		printf ("\n");
		if (find_word_dicho(tab,buffer,0,7980) == true)
		{
			condition = true;
		}
	}

	return buffer;
}