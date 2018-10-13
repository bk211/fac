/*!\file ratio.c
 * \brief fonctions de la lib ratio
 * \author Farès Belhadj
 * \date September 25, 2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ratio.h"
static int idd = -1;
static ratio_t *ptr [10000];
int ratio_pgcd(int p, int q) {
  if(p == q) return p;
  if(p > q) return ratio_pgcd(p - q, q);
  return ratio_pgcd(q - p, p);
}
ratio_t * ratio_new(int p, int q) {
  int m = 1, s;
  ratio_t * r;
  if(q == 0) {
    fprintf(stderr, "Votre denominateur est nul.\n");
    return NULL;
  }
  s = ratio_signe(p, q); p = abs(p); q = abs(q);
  if(p) m = ratio_pgcd(p, q);
  r = malloc(sizeof * r);
  assert(r);
  ratio_num(r) = s * p / m;
  ratio_denom(r) = q / m;
  ptr[++idd]= r;
  return r;
}
void ratio_delete(ratio_t * r) { 
  int i = 0;
  for (i = 0; i <= idd; ++i){
    if(r == ptr[i]){
      ptr[i] = NULL;
      break;
    }
  }
  free(r);
}

extern void quit(void){
  for (int i = 0; i <= idd; ++i)
  {
    if(ptr[i] != NULL){
      free(ptr[i]);
      printf(".\n");
    }
  }
  printf("Done\n");
}

ratio_t * ratio_neg(ratio_t * r) {
  return ratio_new(-ratio_num(r), ratio_denom(r));
}
ratio_t * ratio_moins(ratio_t * r1, ratio_t * r2) {
  return ratio_new(ratio_num(r1) * ratio_denom(r2) - ratio_num(r2) * ratio_denom(r1), 
		   ratio_denom(r1) * ratio_denom(r2));
}
ratio_t * ratio_plus(ratio_t * r1, ratio_t * r2) {
  return ratio_new(ratio_num(r1) * ratio_denom(r2) + ratio_num(r2) * ratio_denom(r1), 
		   ratio_denom(r1) * ratio_denom(r2));
}
ratio_t * ratio_mul(ratio_t * r1, ratio_t * r2) {
  return ratio_new(ratio_num(r1) * ratio_num(r2), 
		   ratio_denom(r1) * ratio_denom(r2));
}
ratio_t * ratio_div(ratio_t * r1, ratio_t * r2) {
  return ratio_new(ratio_num(r1) * ratio_denom(r2), 
		   ratio_denom(r1) * ratio_num(r2));
}