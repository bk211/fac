
/*!\file pile.h
2 * \brief Biblioth`eque de gestion de (une) pile de taille fixe
3 * \author Far`es Belhadj amsi@ai.univ-paris8.fr
4 * \date October 02, 2013
5 */
#ifndef _PILE_H
#define _PILE_H
/*!\brief taille de la pile (dynamique) */
#include "ratio.h"
extern void rpush(ratio_t* v);
extern ratio_t* rpop(void);
extern int rvide(void);

#endif