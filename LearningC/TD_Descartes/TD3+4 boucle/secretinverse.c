#include <stdlib.h>  
#include <stdio.h>  
#include <time.h>           
int maximum,minimum,reponse_ordi;
int guess();
double tirage();
void secretinverse();
int reponse_continuation;
int recommencez_check(int reponse_continuation);

int main(int argc, char const *argv[])
{
	secretinverse();
	recommencez_check(reponse_continuation);	
}


void secretinverse(){
	char reponse_utilisateur;
	srand((unsigned)time(NULL));
	int bonne_reponse=0;
	printf("maximum t=?");
	scanf("%d",&maximum);
	printf("le nombre a deviner est compris entre 0 et %d inclus\n",maximum++);
		printf("taper '>' si la reponse de l'ordi est trop grande\n");
		printf("taper '<' si la reponse de l'ordi est trop petite\n");		
		printf("taper '=' si la reponse de l'ordi est correcte\n");
	while(!bonne_reponse) {
		reponse_ordi=guess();
		fflush(stdin);
		printf("nombre mystere=%d?",reponse_ordi);
		scanf("%c",&reponse_utilisateur);
		switch(reponse_utilisateur){
		case '>':{maximum=reponse_ordi;printf("trop grand\n");break;}
		case '<':{minimum=reponse_ordi;printf("trop petit\n");break;}
		case '=':{bonne_reponse=1;break;}
}}
	printf("bravo a notre cher ordi\n");
	printf("votre reponse etait %d\n",reponse_ordi);

}
int guess(){
	int reponse=(minimum+(maximum-minimum)*tirage());
	return reponse;}

double tirage(){
	rand();
    return (double)rand()/(RAND_MAX+1);}

int recommencez_check(int reponse_continuation){
	printf("voulez vous recommencer? (1/0) \n");
	scanf("%d",&reponse_continuation);
	if (reponse_continuation==1) secretinverse();//recursive yeah
	else printf("fin du prog\n");

}