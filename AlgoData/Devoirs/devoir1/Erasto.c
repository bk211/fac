#include "stdio.h"
#include "math.h"
#include "stdlib.h"

void tri_erasto(int* tab, int x, int n){
	/*
	parcours le tableaux tab, si la valeur de la casse est divisible par x, supprimer cette valeur
	en affectant 0
	*/
	int i;
	for (i = x+1; i < n; ++i)
	{
		if(!(tab[i] % x))
			tab[i] = 0;
	}
}

int erastosthene(int n){
	
	int* tableaux = malloc(sizeof (int) * n);
	if(n <= 1){
		fprintf(stderr, "%s\n","N doit etre superieur a 1" );
		return -1;
	}

	int i;
	for (i = 0; i < n-2; ++i)
	{
		tableaux[i] = i + 2;
	}

	for (i = 2; i < sqrt(n)+1; ++i)
	{
		if((tableaux[i-2]))
			tri_erasto(tableaux, i, n);
	}

	for (int i = 0; i < n-2; ++i)
	{
		if(tableaux[i])
			printf("%d, ",tableaux[i] );
	}

	return 0; //sert a rien..
}

int main()
{	
	int a;
	printf("Ce programme affiche ts les nb premier de 2 a N\nn?:"); 
	scanf("%d",&a);
	erastosthene(a);
	return 0;
}