/*direct.c*/
/* Il s agit de lire et d ecrire dans un fichier massif */
#include "direct.h"

int lire (FILE * f, int nb) {
  int nf, i, v, w, * tf;
/* on commence par savoir s il y a assez d elements dans f*/
  fread(&nf, (size_t) 4, (size_t) 1, f);
  printf("Dans ce fichier il y a %d elements\n",nf);
  if (nf > nb) {
	tf = (int *) malloc ((nb+1) * sizeof (int));
	fread(tf, (size_t) 4, (size_t) (1 + nb), f);
	for (i=0; i <= nb; i++) {
	  printf("fib(%d) == %d\n",i, tf[i]);
	}
	return tf[nb];
  }
  else {
	return remplir (f, nb);
  }
}


int remplir (FILE * f, int nb) {
  int nf, i, v, w, * tf;

  tf = (int *) malloc ((nb+1) * sizeof (int));
  tf[0] = 1;
  tf[1] = 1;
  for (i=2, v=1, w=1; i <= nb; i++) {
	v += w;
	tf[i] = v;
	w = v - w;
  }
  for (i=0; i < nb; i++) {
	printf("fib(%d) = %d\n",i,tf[i]);
  }
  fseek (f,0,SEEK_SET);
  fwrite(&nb, (size_t) 4, (size_t) (1), f);
  fwrite(tf, (size_t) 4, (size_t) (1 + nb), f);
  return tf[nb];
}
