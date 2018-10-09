/*!\file myMain.c
 * \brief fichier de tests de fonctionnalités de la lib ratio
 * \author Farès Belhadj
 * \date September 25, 2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <myLib/ratio.h>

int main(void) {
  ratio_t * a, * b, * c, * d, * e, * f;
  atexit(quit);
  a = ratio_new(-5, 10);
  b = ratio_new(-18, -27);
  d = ratio_moins(c = ratio_neg(b), a);
  f = ratio_mul(e = ratio_div(d, c), a); /* -1 / 8 */
  printf("resultat : %d / %d\n", ratio_num(f), ratio_denom(f));
  ratio_delete(a); ratio_delete(b); ratio_delete(c);
//  ratio_delete(d); ratio_delete(e); ratio_delete(f);
  return 0;
}
