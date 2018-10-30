/*!\file ratio.c
 * \brief fonctions de la lib ratio
 * \author Farès Belhadj
 * \date September 25, 2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ratio.h"
#include "pile.h"
#include "rpile.h"
#include "string.h"
static int idd = -1;
static ratio_t *ptr [10000];
/*int ratio_pgcd(int p, int q) {
  
  if(p == q) return p;
  if(p > q) return ratio_pgcd(p - q, q);
  return ratio_pgcd(q - p, p);
}*/


int ratio_pgcd(int a, int b) {
  //reecriture de pgcd, pour eviter une erreur de segmentation 
  //due a la grande taille des nombres 
  int temp;
  while (b != 0){
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}


int ratio_signe(int p, int q) {
  int a = (p < 0) ? -1 : 1;
  int b = (q < 0) ? -1 : 1;
  return a*b;
}

ratio_t * ratio_new(int p, int q) {
  int m = 1, s;
  ratio_t * r;

  if(!p || !q) {
    r = malloc(sizeof *r);
    ratio_num(r) = p;
    ratio_denom(r) = q;
    ptr[++idd]= r;    
    return r;
  }
  s = ratio_signe(p, q); 
  p = abs(p);q = abs(q);
  if(p){m = ratio_pgcd(p, q);}
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
    }
  }
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


void infixe2postfixe(const char * s, char * d) {
  while(*s) {
    if(*s >= '0' && *s <= '9') {
      do {
        *d++ = *s++;
      } while( *s >= '0' && *s <= '9');
      *d++ = ' ';
    if(!*s) break;
    }

    if((*s == ')') && !vide()) {
      *d++ = (char)pop();
      *d++ = ' '; }
    else if(*s == '+') push((int) *s);
    else if(*s == '-') push((int) *s);
    else if(*s == '*') push((int) *s);
    else if(*s == '/') push((int) *s);
    s++;
  }
  while(!vide()) {*d++ = (char)pop(); *d++ = ' '; }
  *d = '\0';
}
