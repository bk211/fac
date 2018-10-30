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
#define MAX 256

int main(void){
  atexit(quit);
  char source[MAX], destination[MAX<<1];
  if(!fgets(source, MAX, stdin))
  	return 1;
  infixe2postfixe(source, destination);
  printf("%s\n",destination );
  ratio_t* reponse = calcul(destination);
  double rep = reponse->p/(double)reponse->q;
  printf("%d / %d = %.3lf\n",reponse->p,reponse->q,rep);
  return 0;
}

