#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NB_CARTES 9
#define NB_SYMBOLES 12
#define NB_SYMBOLES_PAR_CARTE 4

void imprimerCarte(char * c);
void remplirCarteAleatoirement(char*c,char*ts);
double tirage();
int carteValide(char*c);

int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
//init tableau ts
	char ts[12]={'+','x','*','=','~','!','w','#','&','@','%','$'};

//boucle d'affichage ts
	printf("symboles :");
	for (int i = 0; i < 12; ++i)
	{
		printf(" %c", ts[i]);
	}

//1er carte du jeu
	char carte1[NB_SYMBOLES_PAR_CARTE]={'&','@','%','$'};
	imprimerCarte(carte1);
	int y=carteValide(carte1);
	printf("\n check=%d\n",y );
	return 0;
}


// fct 
void imprimerCarte(char*c)
{
	printf("\nles cartes sont les suivantes");
		for (int i = 0; i < NB_SYMBOLES_PAR_CARTE;++i)
			{
				printf(" %c",*(c+i));
			}
}

double tirage()
{
	rand();
    return (double)rand()/(RAND_MAX+1);
}

void remplirCarteAleatoirement(char*c,char*d)
{
	for (int i = 0; i < NB_SYMBOLES_PAR_CARTE; ++i)
	{
		*(c+i)=*(d+int(NB_SYMBOLES*tirage()));
	}
}

int carteValide(char *c)
{int result=1;
	for (int i = 0; i < NB_SYMBOLES_PAR_CARTE; ++i)
	{
		for (int j = 0; j < NB_SYMBOLES_PAR_CARTE; ++j)
		{
			if((i!=j)&&(*(c+i)==*(c+j))){result=0;break;}
		}
	}return result;
}