#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "compare2.h"
#include "load_dic.h"


char* next_word (char** tab, int len)
{
	// Variables
	int cas[243][5];
	int i,j,k,l,compteur,indice;
	int n = 0;
	int* buffer;
	double freq = 0;
	double word_freq = 0;

	// On crée la matrice de cas possible
	for (i=0;i<243;i++)
	{
		for (j=1;j<6;j++)
		{
			cas[i][5-j] = n%3;
			n = n/3;	
		}
		n = i+1;
	}


	for(k=0;k<len;k++)
	{		
		for (i=0;i<243;i++)
		{
			compteur = 0;

			for (l=0;l<len;l++)
			{
				buffer = malloc (sizeof(int)* 5);

				if (buffer == NULL)
			{
				printf ("ERREUR au moment de l'allocution\n");
				return tab[k];
			}


				buffer = compare2 (tab[k], tab[l]);	

				int cpt = 0;

				for (j=0;j<5;j++)
				{
					if (buffer[j] == cas[i][j])
					{
						cpt++;
					}
				}
				free(buffer);


				if (cpt == 5)
				{
					compteur++;
				}

			}

			compteur = (compteur / len);

			if (compteur != 0)
			{
				compteur = - log (compteur) / log (2);
			}

			freq = freq + compteur;
		}

		if (freq > word_freq)
		{
			word_freq = freq;
			indice = k;
		}
	}

	return tab[indice];
}

