#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void affiche_tableau(int* tab,int n){
	//affiche le contenue du tableau de taille n
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d, ",tab[i] );
	}
	putchar('\n');

}

void produit_tableaux(int *tab,int n){
	//affiche le produit de ts les elements du tableau de taille n
	int resultat = 1;
	int i;
	affiche_tableau(tab,n);
	for(i = 0; i < n; ++i)
	{	
		resultat *= tab[i];
		printf("%d,",resultat );
	}
	printf("resultat = %d\n",resultat);

}


int * saisie_tableaux(int n){
	//alloue la memoire pour le tableau de taille net le remplie
	int i;
	int *tab = malloc(sizeof (int*) *n);
	for (i = 0; i < n; ++i)
	{
		printf("Valeur case %d ? ",i );
		scanf("%d",&tab[i]);
		assert(tab[i]);
	}
	return tab;
}


void copier_tableau(int *src, int *dest,int n){
	//copie le contenue du tableau src de taille n vers le tableau dest
	// puis affiche le contenue des 2 tableau
	int i;
	for (i = 0; i < n; ++i)
	{
		dest[i] = src[i];
	}

	affiche_tableau(src,n);
	affiche_tableau(dest,n);

}

int saisir_taille(){
	// scanf un int et le retourne
	int t;
	printf("entrez la taille du tableau a saisir :");
	scanf("%d",&t);
	assert(t);
	return t;
}

int* saisie_et_calcul_moyenne(){
	//cree un tableau et calcule la moyenne des element du tableau puis l'affiche
	//a la fin on retourne le tableau remplie
	//la moyenne est perdu car non recupere 
	int i,taille = saisir_taille(); 
	int *tab =saisie_tableaux(taille);

	float resultat = 0;
	for (i = 0; i < taille; ++i)
	{
		resultat += tab[i];
	}
	resultat /= taille;
	printf("Moyenne = %.2f \n",resultat);

	return tab;

}


int main(int argc, char const *argv[])
{	
	int taille = saisir_taille(); 
	int* temp =saisie_tableaux(taille);
	int tab2[5];
	int * temp2 = saisie_et_calcul_moyenne();

	copier_tableau(temp,tab2,taille);
	produit_tableaux(temp,taille);
	free(temp); 
	free(temp2);
	return 0;
}