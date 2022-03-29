#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#include "load_dic.h"


bool find_word_dicho (char *biblio, char *word, int left, int right){
	int middle;
	char** tab;
	unsigned int len = 7980;

	tab = load_file(biblio,&len);


	while(left-right!=-1 && left-right!=0 && left-right!=1){
		middle=(right+left)/2;

		if(strcmp(tab[middle],word)==0){
			return true;
		}

		if(strcmp(tab[middle],word)<0){
			left=middle;
		}

		if(strcmp(tab[middle],word)>0){
			right=middle;
		}
	}

	return false;
}


/*int main (int argc, char *argv[])
{
	if(argc!=3){
		printf("ERREUR. Mauvais nombre d'arguments\n");
	}

	printf("%d\n",find_word_dicho(argv[1],argv[2],0,7980));
}*/
