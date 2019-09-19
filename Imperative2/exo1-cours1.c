#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
typedef unsigned short Shu;
int suite (int n) {
  int a;
  a = n >> 1;//divise a par 2
  if (n & 0x01)//si n est impair
	return 3 * (a + 1);//appliquer le calcul
  return a;
}

int main (int argc, char * * argv) {
  int n, i, v, seed;
  Shu tab [MAX], *crt;
  if (argc > 1)
	n = atoi (argv[1]);
  else
	n = 7;
  for (seed = 1; seed < 10; seed++) {
	for (i = 0, crt = tab; i < MAX; i++)//parcourt le tableau de ushort et l initialise a 0
	  *crt++ = (Shu) 0;

	v = seed;//1-10
	tab [v] = 1;//[1 1 1 1 1 1 1 1 1 1 ]
	for (i = 1; i < n; i++) {
	  v = suite (v);//
      printf("v==%d n==%d\n",v,n);
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
