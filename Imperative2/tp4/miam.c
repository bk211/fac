/* miam.c */
#include "direct.h"
#define NOM "fib.dat"
#define NORMAL 43

int main (int argc, char * * argv) {
  FILE * fichier;
  int i, j, v, w;

  if (argc == 2) {
	i = atoi (argv [1]);
	if ((fichier = fopen(NOM,"r+"))!= NULL) {
	  printf("On cherche fib(%d)\n",i);
	  v = lire (fichier, i);
	  printf("fib(%d) = %d\n",i,v);
	}
	else {
	  if ((fichier = fopen(NOM,"w+"))== NULL) {
		printf(" Rien a faire nous revenons a une fonction classique\n");
		v = fibiter (i);
		printf("fib(%d) = %d\n",i,v);
	  }
	  else {
		v = remplir (fichier, i);
		printf("fib(%d) = %d \n",i,v);
	  }
	}
	fclose(fichier);
  }
  else { /* Taille indefinie  */
	if ((fichier = fopen(NOM,"r+"))== NULL) {
	  printf("il faut creer ce fichier \n\n");
	  fichier = fopen(NOM,"w+");
	  v = remplir (fichier, NORMAL);
	  w = lire (fichier, NORMAL);
	  printf("fib(%d) = %d == %d\n",NORMAL,v, w);
	  fclose (fichier);
	}
	else {
	  v = lire (fichier, NORMAL);
	  printf("fib(%d) = %d \n",NORMAL,v);
	 // close(fichier);
	  fclose(fichier);
	}
  }
}
