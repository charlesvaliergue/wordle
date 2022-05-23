#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "load_dic.h"


void occurence(char* dico) {



int cpt[26];
char *alphabet;
unsigned int len = 7980;
char **tab = load_file(dico,&len);
int i,j,k,l;

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


for (i=0;i<26;i++)
{
    cpt[i]=0;
}

for (j=0;j<len;j++)
{
    for( k=0;k<26;k++)
    {
        for (l=0;l<5;l++)
        {
            if(tab[j][l] == alphabet[k])
            {
                cpt[k]++;
                
            }
            
        }
        

    }
    
}

    for(i=0;i<26;i++) 
    {
        printf ("%c = %d\n",alphabet[i],cpt[i]);
    }
}


int main(int argc,char** argv)
{
if (argc!=2)
{
	printf("ERREUR. Mauvais nombre d'arguments\n");
}



occurence(argv[1]);
return 1;
}

