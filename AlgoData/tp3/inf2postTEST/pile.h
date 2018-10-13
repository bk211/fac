/*!\file pile.h
* \brief Bibliothèque de gestion de (une) pile de taille fixe
* \author Farès Belhadj amsi@ai.univ-paris8.fr
* \date October 02, 2013
*/
#ifndef _PILE_H
#define _PILE_H
#define PILE_MAX 256
extern void push(int v);
extern int pop(void);
extern int vide(void);
#endif