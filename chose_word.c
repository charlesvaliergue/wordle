#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


/* Permet de rechercher un mot aléatoire dans un dictionnaire
(fichier texte avec plusieurs mots)
Je sais juste pas comment faire pour sélectionner les mots de 5 lettres.
Je pense qu'on va juste faire un dico qu'avec des mots de 5 lettres c'est 
plus simple*/

int piocher_mot (char* biblio)
{

	// Variables
	srand(time(NULL));
	FILE* dico = NULL;
	int nb_mots = 0;
	int num_mot_choisi = 0;
	int caractere_lu = 0;
	char* mot_choisi;

	// Ouverture du fichier
	dico = fopen(biblio, "rb");

	if (dico == NULL)
	{
		printf("ERREUR. Le fichier n'a pas pu s'ouvrir\n");
		return 0;
	}

	// On récupère le nombre de mots dans le fichier
	while (caractere_lu != EOF)
	{
		caractere_lu = fgetc (dico);
		if (caractere_lu == '\n')
		{
		nb_mots++;
		}
	}

	// On choisit un nombre aléatoire entre 0 et nb_mots
	num_mot_choisi = rand()%nb_mots;

	printf("%d\n",num_mot_choisi);

	// On place le curseur face au mot souhaité dans le fichier
	rewind(dico);

	while (num_mot_choisi > 1)
	{
		caractere_lu = fgetc (dico);
		if (caractere_lu == '\n')
		{
			num_mot_choisi--;
		}
	}

	// On récupère le mot choisi
	mot_choisi = malloc(sizeof(char));

	fgets(mot_choisi,100,dico);

	mot_choisi[strlen(mot_choisi) - 1] = '\0';

	fclose(dico);

	printf("%s\n",mot_choisi);

	return 1;
}


int main(int argc,char** argv){
	if (argc!=2){
		printf("ERREUR. Mauvais nombre d'arguments\n");
	}
	piocher_mot(argv[1]);
}