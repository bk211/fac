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
void jouer(char ** tc);

int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
//init tableaux
	char ts[NB_SYMBOLES]={'+','x','*','=','~','!','w','#','&','@','%','$'};
	char carte1[NB_SYMBOLES_PAR_CARTE],carte2[NB_SYMBOLES_PAR_CARTE],carte3[NB_SYMBOLES_PAR_CARTE],carte4[NB_SYMBOLES_PAR_CARTE],carte5[NB_SYMBOLES_PAR_CARTE],carte6[NB_SYMBOLES_PAR_CARTE],carte7[NB_SYMBOLES_PAR_CARTE],carte8[NB_SYMBOLES_PAR_CARTE],carte9[NB_SYMBOLES_PAR_CARTE];
	char *cartes[NB_CARTES]={carte1,carte2,carte3,carte4,carte5,carte6,carte7,carte8,carte9};
//init cartes
	do{remplirCarteAleatoirement(carte1,ts);}while(!carteValide(carte1));
	
	do{
	do{remplirCarteAleatoirement(carte2,ts);}while(!carteValide(carte2));
	}while((!paireValide(carte1,carte2)));

	do{
	do{remplirCarteAleatoirement(carte3,ts);}while(!carteValide(carte3));
	}while((!paireValide(carte1,carte3)&&(!paireValide(carte2,carte3))));
	
	do{
	do{remplirCarteAleatoirement(carte4,ts);}while(!carteValide(carte4));
	}while((!paireValide(carte1,carte4)&&(!paireValide(carte2,carte4))&&(!paireValide(carte4,carte4))));

	do{
	do{remplirCarteAleatoirement(carte5,ts);}while(!carteValide(carte5));
	}while((!paireValide(carte1,carte5)&&(!paireValide(carte2,carte5))&&(!paireValide(carte3,carte5))&&(!paireValide(carte4,carte5))));

	do{
	do{remplirCarteAleatoirement(carte6,ts);}while(!carteValide(carte6));
	}while((!paireValide(carte1,carte6)&&(!paireValide(carte2,carte6))&&(!paireValide(carte3,carte6))&&(!paireValide(carte4,carte6))&&(!paireValide(carte5,carte6))));

	do{
	do{remplirCarteAleatoirement(carte7,ts);}while(!carteValide(carte7));
	}while((!paireValide(carte1,carte7)&&(!paireValide(carte2,carte7))&&(!paireValide(carte3,carte7))&&(!paireValide(carte4,carte7))&&(!paireValide(carte5,carte7))&&(!paireValide(carte6,carte7))));

	do{
	do{remplirCarteAleatoirement(carte8,ts);}while(!carteValide(carte8));
	}while((!paireValide(carte1,carte8)&&(!paireValide(carte2,carte8))&&(!paireValide(carte3,carte8))&&(!paireValide(carte4,carte8))&&(!paireValide(carte5,carte8))&&(!paireValide(carte6,carte8))&&(!paireValide(carte7,carte8))));

	do{
	do{remplirCarteAleatoirement(carte9,ts);}while(!carteValide(carte9));
	}while((!paireValide(carte1,carte9)&&(!paireValide(carte2,carte9))&&(!paireValide(carte3,carte9))&&(!paireValide(carte4,carte9))&&(!paireValide(carte5,carte9))&&(!paireValide(carte6,carte9))&&(!paireValide(carte7,carte9))&&(!paireValide(carte8,carte9))));

//imprimer deck
/*
	for (int i = 0; i < NB_CARTES; ++i)
	{
		imprimerCarte(*(cartes+i));
	}
*/

printf("game start\n");
jouer(cartes);

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
		for (int i = 0; i < NB_SYMBOLES_PAR_CARTE;++i)
			{
				printf("%c ",*(c+i));
			}
		printf("\n");
		numero_carte++;
}

double tirage()
{
	rand();
    return (double)rand()/(RAND_MAX);
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

void jouer(char **tc){
	//game set
	int numero1,numero2;
	do{
		numero1=int((NB_CARTES)*tirage()), numero2=(int((NB_CARTES)*tirage()));}
	while((numero1==numero2)&&(nombreSymbolesCommuns(*(tc+numero1),*(tc+numero2))==1));
	imprimerCarte(*(tc+numero1));
	imprimerCarte(*(tc+numero2));
	char reponse_joueur;
	char reponse=symboleCommun(*(tc+numero1),*(tc+numero2));
	//user round
	do{
	printf("symbole commun? ");
	fflush(stdin);
	scanf("%c",&reponse_joueur);}
	while((reponse!=reponse_joueur)||(reponse_joueur=='q'));
	if(reponse_joueur!='q') printf("bravo");
}