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

static inline int min(int a, int b) {
  return a > b ? b : a;
}

static void propagation(int * t, int l, int x, int y, int v, int * ncz) {
  t[y * l + x] = v;
  if(v == 0 && (x&1) && (y&1))
    (*ncz)++;
  if(v < t[y * l + x + 1])
    propagation(t, l, x + 1, y, v, ncz);
  if(v < t[y * l + x - 1])
    propagation(t, l, x - 1, y, v, ncz);
  if(v < t[y * l + x + l])
    propagation(t, l, x, y + 1, v, ncz);
  if(v < t[y * l + x - l])
    propagation(t, l, x, y - 1, v, ncz);
}

static int * labyInit(int m, int n) {
  int mp = 2 * m + 1, np = 2 * n + 1, mpnp = mp * np, mn = m * n;
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
    propagation(t, mp, (x + xp) / 2, (y + yp) / 2, min(t[y * mp + x], t[yp * mp + xp]), &nCasesAZero);
  } while(nCasesAZero < mn);
  return t;
}

static void labyPrint(int * t, int l, int h) {
  int x, y;
  const int pas = 10;
  printf("%%!PS-Adobe-2.0 EPSF-1.2\n");
  printf("%%%%BoundingBox: -%d -%d %d %d\n", pas, pas, (l + 1) * pas, (h + 1) * pas);
  printf("/srgb {setrgbcolor} def\n");
  printf("/s {stroke} def\n");
  printf("/mt {moveto} def\n");
  printf("/lt {lineto} def\n");
  printf("/ms {moveto show} def\n");
  printf("/sqe {/y exch def /x exch def gsave x y mt x 10 add y lt x 10 add y 10 add lt x y 10 add lt x y lt s grestore} def\n");
  printf("/sqf {/y exch def /x exch def gsave x y mt x 10 add y lt x 10 add y 10 add lt x y 10 add lt x y lt .3 .3 .3 srgb fill s grestore} def\n");
  printf("0.000 0.000 0.000 srgb\n");
  printf(".1 setlinewidth\n");
  for(y = 0; y < h; ++y)
    for(x = 0; x < l; ++x)
      if(t[y * l + x] == -1)
	printf("%d %d sqf\n%d %d sqe\n", x * pas, y * pas, x * pas, y * pas);
      else
	printf("%d %d sqe\n", x * pas, y * pas);
  printf("%%%%EOF\n");
}

int main(void) {
  int * t;
  const int l = 100, h = 50;
  t = labyInit(l, h);
  labyPrint(t, 2 * l + 1, 2 * h + 1);
  free(t);
  return 0;
}
