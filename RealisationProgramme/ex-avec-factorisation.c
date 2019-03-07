#include <stdio.h>
#include <stdlib.h>

void affiche_plateau(void);

#define DIMENSION 20

// decommenter pour definir DEBUG
// ou compiler gcc -DDEBUG fichier.c
// #define DEBUG

int plateau[DIMENSION][DIMENSION];

char *lecture(int nb, int l, int c, int depli, int deplj, int valeur, char *message, char *mot);
char *lectH(int nb, int l, int c);
char *lectV(int nb, int l, int c);

int main(void) {

  int i,j;
  char resultat[BUFSIZ];

  #ifdef DEBUG
  affiche_plateau();
  #endif
  
  // initialiser un tableau avec des lettres
  for (i=0 ; i<DIMENSION ; i++) 
    for (j=0 ; j<DIMENSION ; j++){
       plateau[i][j]=(rand()%26)+'a';
    }
  affiche_plateau();

  // lire des mots
  // avec le code factorise
  lectH(4,3,2);
  lectH(9,6,2);
  lectH(9,6,15);
  lectV(5,4,7);
  lectV(3,9,5);
  lectV(3,19,1);
  return EXIT_SUCCESS;
}

void affiche_plateau(void) {
  int lig, col;
    for(lig=0; lig<DIMENSION; lig++) {
      printf("Ligne %2d : ", lig);
      for (col=0;col<DIMENSION; col++) {
	printf("%2c ", plateau[lig][col]);
      }
      printf("\n");
    }
    printf("           ");
    for (col=0; col<DIMENSION; col++) {
      printf("%2d ", col);
    }
    printf("\n");
  
}


/* la fonction lecture() est generique
   elle factorise les deux fonctions precedentes
   elle recoit en parametres les valeurs qui permettent d'implementer la
   difference entre elles, en plus des parametres necessaires a la lecture
*/
char *lecture (int nb, int l, int c, int depli, int deplj, int valeur, char *message, char *mot) {
   int i, j, p;
   printf("Lecture de %d lettres en %s a partir de %d,%d --> ", nb, message, l, c);
   for (p=0,i=l, j=c ;  i<DIMENSION&&j<DIMENSION&&p<nb ; i=i+depli, j=j+deplj, p++) {
     mot[p]=plateau[i][j];
  }
#ifdef DEBUG
  printf("\np = %d\n", p);
#endif
  if (p == nb )
    mot[p]='\0';
  else
    mot[0]='\0';
  printf("[%s]\n", mot);
  return mot;
}

/* on ajoute deux fonctions intermediaires qui appelent la fonction generique
   cela permet de garder le code utilisant la lecture simple a lire (pas de
   parametres incomprehensibles)
   on pourrait les implementer au moyen de macros mais on peut aussi compter
   sur le compilateur qui optimise ...
*/ 
char *lectH (int nb, int l, int c) {
  char resultat[BUFSIZ];
  return lecture(nb ,l, c, 0, 1, 1, "H", resultat);
}

char *lectV (int nb, int l, int c) {
  char resultat[BUFSIZ];
  return lecture(nb, l, c, 1, 0, 2, "V", resultat);
}

