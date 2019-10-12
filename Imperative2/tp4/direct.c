/*direct.c*/
/* Il s agit de lire et d ecrire dans un fichier massif */
#include "direct.h"

unsigned long long int  lire (FILE * f, int nb) {
  int nf, i, v, w;//v w never used??
  unsigned long long int * tf;

/* on commence par savoir s il y a assez d elements dans f*/

  fread(&nf, (size_t) sizeof (unsigned long long int), (size_t) 1, f);
  printf("Dans ce fichier il y a %d elements\n",nf);

  if (nf > nb) {
	tf = (unsigned long long int *) malloc ((nb+1) * sizeof (unsigned long long int));
	fread(tf, (size_t) sizeof (unsigned long long int), (size_t) (1 + nb), f);
	for (i=0; i <= nb; i++) {
	  printf("fib(%d) == %llu\n",i, tf[i]);
	}
	return tf[nb];
  }
  else {
	return remplir (f, nb);
  }
}

unsigned long long int  remplir (FILE * f, int nb) {
  int nf, i;
  unsigned long long int v, w,* tf;
  tf = (unsigned long long int *) malloc ((nb+1) * sizeof (unsigned long long int));
  tf[0] = 1;
  tf[1] = 1;
  for (i=2, v=1, w=1; i <= nb; i++) {
	v += w;
	tf[i] = v;
	w = v - w;
  }
  for (i=0; i < nb; i++) {
	printf("fib(%d) = %llu\n",i,tf[i]);
  }
  fseek (f,0,SEEK_SET);
  fwrite(&nb, (size_t) sizeof (unsigned long long int), (size_t) (1), f);
  fwrite(tf, (size_t) sizeof (unsigned long long int), (size_t) (1 + nb), f);
  return tf[nb];
}
