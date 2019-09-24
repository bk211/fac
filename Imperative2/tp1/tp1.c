#include "tp1.h"
#include "suite.h"

int main (int argc, char * * argv) {
  int n, i, v, seed;
  Shu tab [MAX], *crt;
  if (argc > 1)
	n = atoi (argv[1]);
  else
	n = 7;
  for (seed = 1; seed < 900; seed++) {
	for (i = 0, crt = tab; i < MAX; i++)
	  *crt++ = (Shu) 0;
	v = seed;
	tab [v] = 1;
	for (i = 1; i < n; i++) {
	  v = suite (v);
	  if (v > MAX) {
		printf("Depassement pour %d : %d\n", seed, v);
		exit (0);
	  }
	  if (tab[v])
		break;
	  tab[v] = 1;
	}
	if (n == i)
	  printf("seed %d \t n %d i %d\n", seed, n, i);
  }
}
