#include <stdio.h>

double interets(int annee,double somme,double taux);

int main(){
	int annee;
	double a,taux,somme;
	printf("taux?");scanf("%d",&a);
	taux=a/100;
	printf("%f\n",taux );
	printf("somme?");
	scanf("%d",&somme);
	printf("annee?");
	scanf("%d",&annee);
	printf("somme apres %d annee=%.2f\n",annee,interets(annee,somme,taux));
	return 0;
}

double interets(int annee,double somme,double taux){
	for (int i = 0; i < annee; ++i)
	{
		somme*=(taux+1);
	}return somme;


}