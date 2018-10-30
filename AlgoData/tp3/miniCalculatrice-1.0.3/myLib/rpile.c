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

void affiche(ratio_t * nb){
	printf("num:%ld\n",nb->p);
	printf("denum:%ld\n",nb->q );
}

ratio_t * calcul(char * s){//ecriture post fixee necessaire
	//soit la chaine destination apres infixe2post()
    while(*s){
        if(*s >= '0' && *s <= '9'){
	        int nb = 0;
            do {
				nb = nb *10 + *s -'0';
				s++;
			}
			while(*s >= '0' && *s <= '9');
			//on recupere d'abord le nombre puis le jete dans la pile
			rpush(ratio_new(nb, 1));
            nb = 0;

		}
		//dans les cas ou une operation est demandé on retire les 2 derniers nombres de la pile
		//on effectue l'operation demandée puis le resultat est réinjecté dans la pile
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
            rpush(ratio_mul(A,B));
            s++;
        }

        else if(*s == '/'){
            ratio_t* A = rpop();
            ratio_t* B = rpop();
			rpush(ratio_div(B,A));
            s++;
        }

        //si une espace est reconnue, on passe à la case suivante
        else s++;

	}
	//la chaine s est lue en entier,il ne reste plus que le resultat dans la pile
	//le resultat est donné en retour;
	ratio_t * resultat = rpop();
    return resultat;
}