#include <stdio.h>
#define POIDS 0.25;
int main(int argc, char const *argv[])
{
	int nb_piece;
	double poids_total;
	printf("combien de quatre-quarts a expedier?");
	scanf("%d",&nb_piece);
	poids_total=POIDS*nb_piece;
	printf("le colis pese au total %.3f kilos \n",poids_total);
	return 0;
}