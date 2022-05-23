#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "load_dic.h"
#include "ia.h"
#include "next_word.h"
#include "chose_word.h"


char* algo_final (char* biblio)
{
	// Variables
	int nb_tour = 0;
	char **tab;
    unsigned int len = 7980;
    char *mot_joue = "TARIE";

    char *mot_choisi = piocher_mot (biblio);

    tab = malloc (sizeof(char*)*len);

    if (tab == NULL)
    {
    	printf("ERREUR. tab est vide\n");
    	return mot_joue;
    }

    tab = load_file (biblio,&len);

	while (len > 1)
	{
		tab = ia (tab,mot_joue,mot_choisi,&len);

		mot_joue = next_word (tab,len);
		
		nb_tour ++;
	}
	free (tab);

	printf ("Le mot recherché est %s\n",mot_choisi);
	printf ("Je l'ai trouvé en %d coups \n\n",nb_tour);

	return mot_joue; 
}


int main(int argc, char* argv[]) 
	{
    	if (argc!=2)
	{
		printf("ERREUR. Mauvais nombre d'arguments\n");
	}
	printf ("%s\n", algo_final(argv[1]));

	return 1;
	}
