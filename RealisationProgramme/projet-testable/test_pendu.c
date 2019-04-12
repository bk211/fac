/* ----------------------------------

   Programme de test pour le pendu

   ---------------------------------- */

#include <stdlib.h>
#include <stdio.h>
// #include <strings.h>
#include <string.h>
#include <assert.h>

int existe (char, char *);

char mot[9];

int main (void) {
  int res;

  /* creation de la configuration pour test */
  strcpy ( mot, "cartable" );
  printf("%s\n", mot);
  printf ("Debut des tests\n");

  /* appels a existe() et verification de son resultat */

  /* une lettre au milieu du mot */
  res = existe ('t', mot);
  assert (res == 1);

  /* une lettre qui existe deux fois */
  res = existe ('a', mot);
  assert (res == 2);

  /* la lettre au debut du mot */
  res = existe ('c', mot);
  assert (res == 1);

  /* la lettre a la fin du mot */
  res = existe ('e', mot);
  assert (res == 1);

  /* une lettre qui n'existe pas */
  res = existe ('m', mot);
  assert (res == 0);

  printf ("Tout est OK\n");

  return (EXIT_SUCCESS);
}

			   
  
