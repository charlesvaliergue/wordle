#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int* compare2 (char mot1[5], char mot2[5])
{
	// Variables
	int i,j;
	int cpt = 0;
	int* verif;

	// On initialise mon tableau de vérification

	verif = malloc (sizeof (char) * 5);

	if (verif == NULL)
	{
		printf("ERREUR au moment de l'allocution\n");
		return verif;
	}

	for (i=0; i<5; i++)
	{
		verif[i] = 0;
	}

	// On regarde dans un premier temps les lettres placées correctement 
	for (i=0; i<5; i++)
	{
		if (mot1[i] == mot2[i])
		{
			verif[i] = 2;
			cpt++;
		}
	}

	// Si la lettre qui reste n'est pas bien placée alors elle n'est nécaisserement
	// pas dans le mot

	if (cpt == 4)
	{
		return verif;
	}

	// On regarde ensuite si les lettres qui restent sont mal placées
	for(i=0;i<5;i++)
	{
		if (verif[i] == 0)
		{
			for(j=0;j<5;j++)
			{
				if (mot2[i] == mot1[j] && i!=j)
				{
					verif[i]=1;
				}
			}
		}
		
	}
	return verif;
}


// int main()
// {
// 	int* buffer = malloc (sizeof(int)* 5);

// 			if (buffer == NULL)
// 			{
// 				printf("ERREUR au moment de l'allocution\n");
// 				return 0;
// 			}
	
// 	char mot1[5] = "TARIF";
// 	char mot2[5] = "TARIE";

// 	buffer = compare2 (mot1, mot2);

// 	for (int x=0;x<5;x++)
// 		{
// 			printf ("%d",buffer[x]);
// 		}
// 		printf ("\n");
// }
