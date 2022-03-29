#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Code du jeu, il faut juste traiter les cas qui bug dans la fonction compare
et on pourra la foutre ici*/ 


void jeu (char* mot_choisi)
{
	// Variables
	int i = 6;
	char buffer[50];


	while (i > 0)
	{
		printf("Veuillez choisir un mot de 5 lettres\n");
		scanf("%s",buffer);

		if (strlen(buffer) != 5)
		{
			printf("Le mot saisi n'est pas de la bonne taille\n");
			return;
		}

		if (strcmp(buffer,mot_choisi) == 0)
		{
			printf("Félicitations, vous avez trouvé le bon mot\n");
			return;
		}	
	}
}