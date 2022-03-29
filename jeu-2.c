#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chose_word.h"
#include "compare.h"



/*Code du jeu, il faut juste traiter les cas qui bug dans la fonction compare
et on pourra la foutre ici*/ 


void jeu (char* mot_choisi)
{
	// Variables
	int i = 6;
	char buffer[50];

	while (i > 0)
	{
		printf("Veuillez choisir un mot de 5 lettres en majuscule\n");
		scanf("%s",buffer);

		if (strlen(buffer) != 5)
		{
			printf("Le mot saisi n'est pas de la bonne taille\n");
			return;
		}

		if ()

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
	}
	jeu(piocher_mot(argv[1]));
}