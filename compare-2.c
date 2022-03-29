#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Cette fonction permet de comparer les lettres. La première partie du code
(pour savoir si les lettres sont bien placées) se fait sans erreur alors
que la 2e partie bug si par exemple on a un mot avec 2x la même lettre 
(ex: belle) et que tu rentres un mot avec 1x chauq lettre (ex: livre)*/

void compare (char mot1[5], char mot2[5])
{
	// Variables
	int i,j;
	int cpt = 0;
	int verif[5];

	// On initialise mon tableau de vérification

	for (i=0; i<5; i++)
	{
		verif[i] = 0;
	}

	// On regarde dans un premier temps les lettres placées correctement 
	for (i=0; i<5; i++)
	{
		if (mot1[i] == mot2[i])
		{
			printf("La lettre %c est bien placée\n",mot1[i]);
			verif[i] = 1;
			cpt++;
		}
	}

	// Si la lettre qui reste n'est pas bien placée alors elle n'est nécaisserement
	// pas dans le mot

	if (cpt == 4)
	{
		return;
	}

	i = 0;
	// On regarde ensuite si les lettres qui restent sont mal placées
	while (i<5)
	{
		if (verif[i] == 0)
		{
			for(j=0;j<5;j++)
			{
				if (mot1[i] == mot2[j])
				{
					printf("La lettre %c est dans le mot mais mal placée\n",mot1[i]);
				}
			}
			i++;
		}
		else
		{
			i++;
		}
	}

	return;
}