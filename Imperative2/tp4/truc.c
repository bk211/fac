#include <stdio.h>
#include "mydef.h"
#define NOM "num.dat"

#define SIZE 45
void remplir (FILE * f) {
  int i,n,m,p;
  n=1, m=1;
  fprintf(f,"%9d %9d %9d ",SIZE,1,1);
  for (i=2;i < SIZE; i++ ) {
	p = n+m;
	fprintf(f,"%9d ",p);
	n=m;
	m=p;
	printf("%d ",p);
  }
  fprintf(f,"\n");
  printf("\n");
}
int remplirn (FILE * f, int nb) {
  int i,n,m,p;
  n=1;
  m=1;
  p=1;

  fprintf(f,"%9d %9d %9d ",nb,1,1);
  for (i=2;i < nb; i++ ) {
	p = n+m;
	fprintf(f,"%9d ",p);
	n=m, m=p;
	printf("%d ",p);
  }
  fprintf(f,"\n");
  printf("\n");
  return p;
}
void lire (FILE * f) {
  int i, j, taille, buf[SIZE];
  fscanf(f,"%d ",&j);
  taille = j > SIZE ? SIZE : j;
  for (i=0;i < taille;i++) {
	fscanf(f,"%d ",&j);
	buf[i]=j;
  }
  for (i=0;i < taille;i++) {
	printf("%9d ",buf[i]);
	printf("%d |",buf[i]);
  }
  printf("\n");
}
int liren (FILE * f, int nb) {
  int i, j, v0, v1, v;
  long posi;

  fseek(f, 0, SEEK_SET);
  fscanf(f,"%d ",&j);
  if (j > nb) {
	posi = (nb * 10);
	fseek(f, posi, SEEK_SET);
	fscanf(f,"%d ",&v);
	return v;
  }
  /* Il n y avait pas assez de valeurs  */
  fclose(f);
  if ((f = fopen(NOM,"r+"))== NULL) {
	printf("Ca ne va plus du tout\n\n");
	return fib(nb);
  }
  fseek(f, -19L, 2);
  fscanf(f,"%d ",&v0);
  printf("%d => %d\n",j-2, v0);
  fseek(f, -10L, 2);
  fscanf(f,"%d ",&v1);
  printf("%d => %d\n",j-1, v1);
  for ( ; j < nb; j++ ) {
	v  = v0 + v1;
	fprintf(f,"%9d ",v);
	printf("%d ",v);
	v0 = v1;
	v1 = v;
  }
  v1 = ftell(f);
  printf("on est maintenant en %d\n",v1);
  fseek(f,-v1,1);
  fscanf(f,"%d ",&v0);
  printf("On y trouve %d\n", v0);
  fseek(f,0L,SEEK_SET);
  fprintf(f,"%9d ",nb);
  printf("remis %d au debut\n", nb);
  v1 = ftell(f);
  printf("on est encore en %d\n",v1);
  fseek(f,-v1,1);
  fscanf(f,"%d ",&v0);
  printf("On y trouve %d\n", v0);
  return v;
}

int fib (int n) {
  int v0, v1, v;

  v0 = 1;
  v1 = 1;
  while (--n) {
	v  = v0 + v1;
	v0 = v1;
	v1 = v;
  }
  return v1;
}
/*
gcc truc.c main.c -o fil
neige: fil
il faut creer ce fichier

2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 102334155 165580141 267914296 433494437 701408733 1134903170

neige: fil 49
43 => 408733
44 => 34903170
35311903 70215073 105526976 175742049 281269025 on est maintenant en 512
On y trouve 45
remis 49 au debut
on est encore en 522
On y trouve 45
fib(49) = 281269025

neige: cat num.dat
       45         1         1         2         3         5
8        13        21        34        55        89       144
233       377       610       987      1597      2584      4181
6765     10946     17711     28657     46368     75025    121393
196418    317811    514229    832040   1346269   2178309   3524578
5702887   9227465  14930352  24157817  39088169  63245986 102334155
165580141 267914296 433494437 701408733 1134903170
 3
*/
