#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "compare2.h"


void first_word (char* biblio)
{
	// Variables
	FILE* dico = NULL;
	char mot_choisi[5];
	char mot_lu[5];
	int cas[243][5];
	int i;
	int n = 0;
	int j;
	int buffer[5];
	int cpt=0;
	int freq[243];

	// On crée la matrice de cas possible
	for (i=0;i<243;i++)
	{
		for (j=0;j<5;j++)
		{
			cas[i][5-j] = n%3;
			n = n/3;	
		}
	}

	// On récupère un mot dans le dictionnaire
	dico = fopen (biblio, "rb");

	if (dico == NULL)
	{
		printf("ERREUR. Le fichier n'a pas pu s'ouvrir\n");
		return;
	}

	fscanf (dico, "%d", &mot_choisi);

	// Retour du pointeur au début
	fclose (dico);

	dico = fopen (biblio, "rb");

	fscanf (dico, "%d", &mot_lu);

	for (i=0;i<243;i++)
	{ 
		cpt = 0;

		while (mot_lu != EOF)
		{
			buffer = compare2 (mot_choisi, mot_lu);
			if (buffer == cas[i])
			{
				cpt++;
			}

			fscanf (dico, "%d", &mot_lu);
		}

		freq[i] = cpt;
	}
}