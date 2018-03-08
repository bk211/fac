#include <stdio.h>
#define pi 3.14159
int main(){
	int rayon;
	printf("rayon?");
	scanf("%d",&rayon);
	printf("aire du cercle =%.2f\n", pi*rayon*rayon);
	printf("volume de la sphere=%.2f\n",pi*4/3*rayon*rayon*rayon);
}