#include <stdio.h>
int main(int argc, char const *argv[])
{	int nombre;
	printf("Entrez le nombre à multiplier: ");scanf("%d",&nombre);
	for (int i = 1; i <= 9; ++i)
	{
		int resultat=i*nombre;
		printf("%d * %d = %2d\n",nombre,i,resultat );
	}
	return 0;
}