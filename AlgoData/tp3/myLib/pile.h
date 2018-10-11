/*!\file pile.h
 * \brief Biblioth`eque de gestion de (une) pile de taille fixe
 * \author Far`es Belhadj amsi@ai.univ-paris8.fr
 * \date October 02, 2013
 */
#ifndef _PILE_H
#define _PILE_H
/*!\brief taille de la pile (statique) */
#define PILE_MAX 256 
extern void push(int v);
extern int pop(void);
extern int vide(void);

#endif