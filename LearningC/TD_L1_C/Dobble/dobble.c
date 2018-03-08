#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NB_CARTES 9
#define NB_SYMBOLES 12
#define NB_SYMBOLES_PAR_CARTE 4

void imprimerSymbole(char*c);
void imprimerCarte(char * c);
double tirage();
void remplirCarteAleatoirement(char*c,char*ts);
int carteValide(char*c);
int nombreSymbolesCommuns(char*c1,char*c2);
int paireValide(char*c1,char*c2);
char symboleCommun(char*c1,char*c2);

int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
//init tableau ts
	char ts[12]={'+','x','*','=','~','!','w','#','&','@','%','$'};
//	imprimerSymbole(ts);

//1er carte du jeu
	char carte1[NB_SYMBOLES_PAR_CARTE];
	do{remplirCarteAleatoirement(carte1,ts);}while(!carteValide(carte1));
	imprimerCarte(carte1);

//2eme carte du jeu ssi paire valide
	char carte2[NB_SYMBOLES_PAR_CARTE];
	do{
		do{remplirCarteAleatoirement(carte2,ts);}while(!carteValide(carte2));
	}while(!paireValide(carte1,carte2));

	imprimerCarte(carte2);

//nb de paire match
//	printf("nb de paires: %d\n",nombreSymbolesCommuns(carte1,carte2));

//test paire valide
//	printf("test de paire valide: %d\n",paireValide(carte1,carte2));

//symbole commun c1 c2
//	printf("symbole commun: %c\n",symboleCommun(carte1,carte2));

	char carte3[NB_SYMBOLES_PAR_CARTE];
	do{
	do{remplirCarteAleatoirement(carte3,ts);}while(!carteValide(carte3));
	}while((!paireValide(carte1,carte3)&&(!paireValide(carte2,carte3))));
	imprimerCarte(carte3);
}

// fct 
void imprimerSymbole(char*c){
printf("symboles :");
	for (int i = 0; i < 12; ++i)
	{
		printf(" %c",*(c+i));
	}printf("\n");}
void imprimerCarte(char*c)
{	static int numero_carte=1;
	printf("carte%d:",numero_carte);
		for (int i = 0; i < NB_SYMBOLES_PAR_CARTE;++i)
			{
				printf(" %c",*(c+i));
			}
		printf("\n");
		numero_carte++;
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

int nombreSymbolesCommuns(char*c1,char*c2){
	int count=0;
	for (int i = 0; i < NB_SYMBOLES_PAR_CARTE; ++i)
	{
		for (int j = 0; j < NB_SYMBOLES_PAR_CARTE; ++j)
		{
			if(*(c1+i)==*(c2+j)) count++;
		}
	}return count;
}

int paireValide(char*c1,char*c2){
	if (nombreSymbolesCommuns(c1,c2)==1) return 1;
	else return 0;
}

char symboleCommun(char*c1,char*c2){
	if(nombreSymbolesCommuns(c1,c2)==1){
		for (int i = 0; i < NB_SYMBOLES_PAR_CARTE; ++i)
		{
			for (int j = 0; j < NB_SYMBOLES_PAR_CARTE; ++j)
			{
				if(*(c1+i)==*(c2+j)) return *(c1+i);
			}
		}
	}
	else return '\0';
}