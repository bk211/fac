#include <stdio.h>
#include "mydef.h"
#define NOM "num.dat"

int main (int argc, char * * argv) {
  FILE * fichier;
  int i, j, v, w;

  if (argc == 2) {
	i = atoi (argv [1]);
	if ((fichier = fopen(NOM,"r"))!= NULL) {
	  v = liren (fichier, i);
	  printf("fib(%d) = %d\n",i,v);
	}
	else {
	  if ((fichier = fopen(NOM,"w+"))== NULL) {
		printf(" Rien a faire nous revenons a une fonction classique\n");
		v = fib (i);
		printf("fib(%d) = %d\n",i,v);
	  }
	  else {
		v = remplirn (fichier, i);
		fseek (fichier, -10L, 2);
		fscanf(fichier,"%d",&w);
		printf("fib(%d) = %d ou %d\n",i,v, w);
	  }
	}
	fclose(fichier);
  }
  else if (argc == 3) {
	i = atoi (argv [1]);
	j = atoi (argv [2]);
//	printf("les valeurs de %d a %d\n",i,j);
	if ((fichier = fopen(NOM,"r"))!= NULL) {
	  for ( ; i <= j; i++) {
		v = liren (fichier, i);
		printf("fib(%3d) = %10d\n",i,v);
	  }
	}
	else {
	  if ((fichier = fopen(NOM,"w+"))== NULL) {
		printf(" Rien a faire nous revenons a une fonction classique\n");
		for ( ; i <= j; i++) {
		  v = fib (i);
		  printf("fib(%d) = %d\n",i,v);
		}
	  }
	  else {
		v = remplirn (fichier, i);
		fseek (fichier, -10L, 2);
		fscanf(fichier,"%d",&w);
		printf("fib(%d) = %d ou %d\n",i,v, w);
	  }
	}
	fclose(fichier);
  }
  else { /* Taille indefinie  */
	if ((fichier = fopen(NOM,"r"))== NULL) {
	  printf("il faut creer ce fichier \n\n");
	  fichier = fopen(NOM,"w+");
	  remplir (fichier);
	  lire (fichier);
	  fclose (fichier);
	}
	else {
	  lire (fichier);
	  fclose(fichier);
	}
  }
}
