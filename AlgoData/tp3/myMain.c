/*!\file myMain.c
 * \brief fichier de tests de fonctionnalités de la lib ratio
 * \author Farès Belhadj
 * \date September 25, 2013
 */
#include <stdio.h>
#include <stdlib.h>
#include "myLib/ratio.h"
#include "myLib/rpile.h"
#include "myLib/pile.h"
#include "myLib/infix2post.c"
#include "string.h"

int main(void) {
  atexit(quit);
  char* chaine= "(((1+2)*3)+4*(((5+6)/7)+8))";
  char* chaine2= malloc( strlen(chaine)*sizeof(char));
  char* chaine3 = "10 2 *";
  printf("l’expression infixee : %s\n", chaine);
  infixe2postfixe(chaine, chaine2);
  printf("s’ecrit : %s en postfixe\n", chaine2);
  calcul(chaine2);
  return 0;
}
