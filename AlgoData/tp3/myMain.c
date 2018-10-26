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

int main(void){
  atexit(quit);
  char* chaine= "(((1+2)*3)+4*(((5+6)/7)+8))";
  conversion_calcul(chaine);
  return 0;
}
