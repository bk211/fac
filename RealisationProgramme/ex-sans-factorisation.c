#include <stdio.h>
#include <stdlib.h>

void affiche_plateau(void);

// decommenter pour definir DEBUG
// ou compiler gcc -DDEBUG fichier.c
// #define DEBUG

int plateau[20][20];
char *lectHorizontal(int nb, int l, int c, char *mot);
char *lectVertical(int nb, int l, int c, char *mot);

int main(void) {

  int i,j;
  char resultat[BUFSIZ];

  #ifdef DEBUG
  affiche_plateau();
  #endif
  
  // initialiser un tableau avec des lettres
  for (i=0 ; i<20 ; i++) 
    for (j=0 ; j<20 ; j++){
      // printf("%d %d %d\n", rand(), rand()%26, rand()%26-'a');
      plateau[i][j]=(rand()%26)+'a';
    }
  affiche_plateau();

  // lire des mots
  printf ("Lecture de 4 lettres en H a partir de 3,2 --> [%s]\n", lectHorizontal(4,3,2,resultat) );
  printf ("Lecture de 9 lettres en H a partir de 6,2 --> [%s]\n", lectHorizontal(9,6,2,resultat) );
  printf ("Lecture de 9 lettres en H a partir de 6,15 --> [%s]\n", lectHorizontal(9,6,15,resultat) );
  
  printf ("Lecture de 5 lettres en V a partir de 4,7 --> [%s]\n", lectVertical(5,4,7,resultat) );
  printf ("Lecture de 3 lettres en V a partir de 9,5 --> [%s]\n", lectVertical(3,9,5,resultat) );
  printf ("Lecture de 3 lettres en V a partir de 19,1 --> [%s]\n", lectVertical(3,19,1,resultat) );

  return EXIT_SUCCESS;
}

void affiche_plateau(void) {
  int lig, col;
    for(lig=0; lig<20; lig++) {
      printf("Ligne %2d : ", lig);
      for (col=0;col<20; col++) {
	printf("%2c ", plateau[lig][col]);
      }
      printf("\n");
    }
    printf("           ");
    for (col=0; col<20; col++) {
      printf("%2d ", col);
    }
    printf("\n");
  
}

/* les fonctions lectHorizontal() et lectVertical sont tres proches
   elles sont ecrites sur le meme format
   il y a peu de differences entre elles
*/
char *lectHorizontal (int nb, int l, int c, char *mot) {
  int i, j, p;
#ifdef DEBUG
  printf("Lecture de %d lettres en Horizontal à partir de %d %d\n", nb, l, c);
#endif
  for (p=0,i=l, j=c ;  i<20&&j<20&&p<nb ; j++,p++) {
    mot[p]=plateau[i][j];
  }
#ifdef DEBUG
  printf("p = %d\n", p);
#endif
  if (p == nb )
    mot[p]='\0';
  else
    mot[0]='\0';
#ifdef DEBUG
  printf("Le mot lu est %s\n", mot);
#endif
  return mot;
}

char *lectVertical (int nb, int l, int c, char *mot) {
  int i, j, p;
  #ifdef DEBUG
  printf("Lecture d'un alignement de %d en Vertical à partir de %d %d\n", nb, l, c);
  #endif
  for (p=0,i=l, j=c ;  i<20&&j<20&&p<nb ; i++,p++) {
    mot[p]=plateau[i][j];
  }
#ifdef DEBUG
  printf("p = %d\n", p);
#endif
  if (p == nb )
    mot[p]='\0';
  else
    mot[0]='\0';
#ifdef DEBUG
  printf("Le mot lu est %s\n", mot);
#endif
  return mot;
}


