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
		printf("Veuillez saisir à nouveau un mot français\n");
		scanf("%s",buffer);
		if (find_word_dicho(tab,buffer,0,7980) == true)
		{
			condition = true;
		}
	}

	return buffer;
}

/*int main (int argc, char **argv)
{
	bool c = false;
	unsigned int len = 7980;

	char **tab = load_file (argv[1],&len);

	condition_passage2 (tab,c);
}*/