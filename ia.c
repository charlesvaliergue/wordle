#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "compare2.h"
#include "load_dic.h"

char** ia(char** tab, char* mot_joue, char* mot_choisi,unsigned int* len)
{
    int *res;
    int *res2;
    int j,k,l,m;
    int cpt;
    int cpt0, cpt1, cpt3;
    int n = 0;
    char** new;

    new = malloc (sizeof(char*)*(*len));

    if (new == NULL)
    {
        printf("ERREUR. new est vide\n");
        return new;
    }

        res = compare2 (mot_choisi,mot_joue);

        

        for (j=0;j<(*len);j++)
        {
            cpt = 0;

            for (k=0;k<5;k++) 
            {

                if (res[k]==2) 
                {
                    if (tab[j][k]==mot_joue[k])
                    {
                        cpt++;
                    }
                }

                if (res[k]==1)
                { 
                    cpt1 = 0;                   
                    for (l=0;l<5;l++)
                    {
                        if (mot_joue[k] == tab[j][l] && l != k && cpt1 != 1)
                        {
                            cpt++;
                            cpt1++;
                        }
                    }
                }

                if (res[k] == 0)
                {
                    cpt0 = 0;
                    for(l=0;l<5;l++)
                    {
                        if (mot_joue[k]!=tab[j][l])
                        {
                            cpt0++;
                        }
                        
                    }
                    if(cpt0==5)
                    {
                        cpt++;
                    }
                }
            }

            res2 = compare2(tab[j],mot_joue);

            cpt3 = 0;

            for (m=0;m<5;m++)
            {
                if (res[m] == res2[m])
                {
                    cpt3++;
                }
            }

            if (cpt == 5 && cpt3 == 5)
            {
                new[n]=tab[j];
                n = n+1;
            }            
        }

        *len=n;

    return new;
}