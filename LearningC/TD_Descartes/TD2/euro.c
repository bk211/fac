#include <stdio.h>
int main(){
	int somme;
		printf("somme d'argent?");
		scanf("%d",&somme);
		printf("billet de 100=%d\n",somme/100);
		somme=somme%100;
		printf("billet de 50=%d\n",somme/50);
		somme=somme%50; 

}