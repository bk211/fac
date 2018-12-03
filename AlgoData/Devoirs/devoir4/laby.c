/*!\file laby.c
 *
 * \brief Début du générateur de labyrinthes
 *
 * \author Farès BELHADJ, amsi@ai.univ-paris8.fr
 * \date November 17 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static inline int myRand(int n) {
  return (int)(n * (rand() / (RAND_MAX + 1.0)));
}

static int * labyInit(int m, int n) {
  int mp = 2 * m + 1, np = 2 * n + 1, mpnp = mp * np;
  int x, y, xp, yp, k, nCasesAZero = 1;
  int * t = malloc(mpnp * sizeof *t);
  assert(t);
  for(y = 0, k = 0; y < np; y++) {
    int ymp = y * mp;
    for(x = 0; x < mp; x++)
      t[ymp + x] = ((x&1) && (y&1)) ? k++ : -1;
  }
  do {
    do {
      /* version de sélection de binômes de noeuds faite en cours */
      x = 2 * myRand(m) + 1;
      y = 2 * myRand(n) + 1;
      if(myRand(2)) { //nord-sud
	xp = x;
	yp = y + (4 * myRand(2) - 2);
	if(yp < 0 || yp >= np)
	  yp = y;
      } else { // est-ouest
	yp = y;
	xp = x + (4 * myRand(2) - 2);
	if(xp < 0 || xp >= mp)
	  xp = x;
      }
    } while(t[y * mp + x] == t[yp * mp + xp]);
    fprintf(stderr, "Deux IDs différents ont été trouvés : %d %d\n", 
	    t[y * mp + x], t[yp * mp + xp]);
    /* sans la modification de la valeur de la variable nCasesAZero
       nous resterons dans une boucle infinie. Il faut ajouter une
       fonction qui, récursivement, propage le plus petit id de noeud
       sur le sous graphe ayant le plus grand id. Quand cette
       propagation propage 0, il faut incrémenter nbCasesAZero à
       chaque fois.*/
  } while(nCasesAZero < mpnp);
  return t;
}

int main(void) {
  labyInit(15, 10);
  return 0;
}
