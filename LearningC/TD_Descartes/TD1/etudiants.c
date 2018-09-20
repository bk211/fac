#include <stdio.h>
int main()
{
	int m,n;
	printf("nombre d'etudiants inscrits ?");
	scanf("%d",&m);
	printf("nombre d'etudiants inscrits =%d\n",m );
	printf("nombre d'etudiants presents ?");
	scanf("%d",&n);
	printf("nombre d'etudiants presents= %d\n",n);
	printf("pourcentage de presence=%.1f \n",n/m*100.0 );

}