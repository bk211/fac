#include <stdio.h>
int main(){
	int largeur,longueur;
	printf("largeur ?");
	scanf("%d",&largeur);
	printf("longueur?");	
	scanf("%d",&longueur);
	printf("perimetre =%.2f\n",(largeur+longueur)*2.00);
	printf("surface =%.2f\n", largeur*longueur*1.00);
}