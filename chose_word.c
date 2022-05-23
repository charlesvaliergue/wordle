#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "load_dic.h"


/* Permet de rechercher un mot aléatoire dans un dictionnaire
(fichier texte avec plusieurs mots) */

char* piocher_mot (char* biblio)
{
	srand (time(NULL));

	// Variables
	unsigned int len = 7980;
	char **tab = load_file (biblio, &len);
	char* mot_choisi;
	int num_mot_choisi;

	mot_choisi = malloc(5*sizeof(char));

	if (mot_choisi == NULL)
	{
		printf ("ERREUR. Mauvais alllocation\n");
		return mot_choisi;
	}

	num_mot_choisi = rand()%len;

	strcpy (mot_choisi,tab[num_mot_choisi]);

	return mot_choisi;
}