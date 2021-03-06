#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
			printf("La lettre %c (place %d) est bien placée\n",mot1[i],i+1);
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
				if ((mot1[i] == mot2[j])&&(verif[j]==0))
				{
					printf("La lettre %c (place %d) est dans le mot mais mal placée\n",mot1[i],i+1);
					verif[j]=1;
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