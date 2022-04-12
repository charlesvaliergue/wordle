#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	int cas[243][5];
	int i;
	int n = 0;
	int j;

	// On crée la matrice de cas possible
	for (i=0;i<243;i++)
	{
		for (j=0;j<5;j++)
		{
			cas[i][5-j]=n%3;
			n=n/3;
		}
		n=i+1;
	}

	for (i=0;i<243;i++)
	{
		for (j=1;j<6;j++)
		{
			printf ("%d", cas[i][j]);
		}
		printf ("\n");
	}
}