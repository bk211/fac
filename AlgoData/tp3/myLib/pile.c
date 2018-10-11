#include "rpile.h"
/*!\file pile.c
2 * \brief Biblioth`eque de gestion de (une) pile de taille fixe
3 * \author Far`es Belhadj amsi@ai.univ-paris8.fr
4 * \date October 02, 2013
5 */
#include <assert.h>

 /*!\brief indice indiquant le haut de la pile.*/
static int haut = -1;
//static int taille = 0;
/*!\brief tableau static utilis´e pour le stockage de la pile.*/
static ratio_t* pile[PILE_MAX];
//static ratio_t* pile = NULL;
/*!\brief Empiler la valeur \a v dans la pile.
* \param v la valeur `a empiler
*/
void rpush(ratio_t* v) {
	pile[++haut] = v;
}
/*!\brief d´epiler et renvoyer la valeur de l’´el´ement en haut de la pile.
* \return la valeur en haut de la pile.
*/
ratio_t* rpop(void) {
	return pile[haut--];
}

/*!\brief Indique si la pile est vide.
* \return vrai si la pile est vide, faux sinon.
*/
int rvide(void) {
	return (haut < 0);
}