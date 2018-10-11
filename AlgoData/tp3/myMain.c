/*!\file myMain.c
 * \brief fichier de tests de fonctionnalités de la lib ratio
 * \author Farès Belhadj
 * \date September 25, 2013
 */
#include <stdio.h>
#include <stdlib.h>
#include "myLib/ratio.h"
#include "myLib/rpile.h"
//#include "myLib/inf2post.c"
int main(void) {
  atexit(quit);
  ratio_t * a, * b, * c, * d, * e, * f;
  a = ratio_new(-5, 10);
  b = ratio_new(-18, -27);
  d = ratio_moins(c = ratio_neg(b), a);
  f = ratio_mul(e = ratio_div(d, c), a); /* -1 / 8 */
  printf("resultat : %d / %d\n", ratio_num(f), ratio_denom(f));
  char* chaine= "(((1+2)*3)+4*(((5+6)/7)+8))";
  //char* chaine2;
  //infixe2postfixe(chaine, chaine2);
  printf("l’expression infixee : %s\n", chaine);
  //printf("s’ecrit : %s en postfixe\n", chaine2);
  return 0;
}
