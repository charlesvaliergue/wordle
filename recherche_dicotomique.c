#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#include "load_dic.h"


bool find_word_dicho (char ** tab, char *word, int left, int right){
	int middle;

	while (left-right!=-1 && left-right!=0 && left-right!=1){
		middle=(right+left)/2;

		if (strcmp(tab[middle],word)==0){
			return true;
		}

		if (strcmp(tab[middle],word)<0){
			left=middle;
		}

		if (strcmp(tab[middle],word)>0){
			right=middle;
		}
	}

	return false;
}