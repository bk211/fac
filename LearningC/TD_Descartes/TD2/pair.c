#include <stdio.h>
int main(){
	int nombre;
	printf("nombre?");
	scanf("%d",&nombre);
	if (nombre%2)
		printf("votre nombre est pair\n");
	else
		printf("votre nombre est impair\n");
	return 0;

}