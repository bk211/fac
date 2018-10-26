#include "rpile.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
/*!\file pile.c
2 * \brief Biblioth`eque de gestion de (une) pile de taille fixe
3 * \author Far`es Belhadj amsi@ai.univ-paris8.fr
4 * \date October 02, 2013
5 */

 /*!\brief indice indiquant le haut de la pile.*/
static int rhaut = -1,rtaille = 0;
/*!\brief tableau static utilis´e pour le stockage de la pile.*/
static ratio_t* rpile = NULL;
/*!\brief Empiler la valeur \a v dans la pile.
* \param v la valeur `a empiler
*/
void rpush(ratio_t* v) {
	if(++rhaut == rtaille){

		if(!rhaut){
			rpile = malloc( (rtaille = 1024) * sizeof *rpile);
			assert(rpile);
		}else{
			rpile = realloc(rpile,(rtaille *=2) * sizeof *rpile);
			assert(rpile);
		}
	}

		rpile[rhaut] = *v;
}
/*!\brief d´epiler et renvoyer la valeur de l’´el´ement en haut de la pile.
* \return la valeur en haut de la pile.
*/
ratio_t* rpop(void) {
	return &rpile[rhaut--];
}

/*!\brief Indique si la pile est vide.
* \return vrai si la pile est vide, faux sinon.
*/
int rvide(void) {
	return (rhaut < 0);
}



ratio_t * calcul(char * s){//ecriture post fixee
    
    while(*s){
        if(*s >= '0' && *s <= '9'){
	        int nb = 0;
            do {
				nb = nb *10 + *s -'0';
				s++;
			}
			while(*s >= '0' && *s <= '9');
			rpush(ratio_new(nb, 1));
            nb = 0;
			//si le char est un chiffre

		}
		else if(*s == '+'){
			ratio_t* A = rpop();
			ratio_t* B = rpop();
            rpush(ratio_plus(A,B));
			s++;
		}
		else if(*s == '-'){
            ratio_t* A = rpop();
            ratio_t* B = rpop();

            rpush(ratio_moins(B,A));
            s++;
        }

        else if(*s == '*'){
            ratio_t* A = rpop();
            ratio_t* B = rpop();
            rpush(ratio_mul(B,A));
            s++;
        }

        else if(*s == '/'){
            ratio_t* A = rpop();
            ratio_t* B = rpop();
            rpush(ratio_div(B,A));
            s++;
        }
        else s++;

	}
    ratio_t* resultat = rpop();
    return resultat;
}