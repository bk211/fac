/*Aligne 4
Le jeu se deroule sur une grille 4x4.
Il y a 16 types de pieces.
Chaque piece possede 4 caracteristiques binaires :
  sacouleur (noire ou blanche) ;
  sa taille (grande ou petite) ; 
  son type (animal ou vegetal) ; 
  sa forme (ronde ou carree). 

Le gagnant est le joueur qui parvient a 
    -aligner 4 pieces 
    -ayant une caracteristique commune 
        -horizontalement
        ou
        -verticalement
        ou
        -diagonale. 
 Il peut y avoir un match nul si 
    grille est remplie
    et  
    pas d’alignement.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct pieces{
    int couleur;
    // 0 ->  noire  , 1 -> blanche
    int taille;
    // 0 ->  grande , 1 -> petite
    int type;
    // 0 ->  animal , 1 -> vegetal
    int forme;
    // 0 ->  ronde  , 1 -> carre
};
struct pieces piece;

struct ttableau{
    struct pieces cases[16];
    //struct pieces cases[4][4];
};
struct ttableau table;

void print_piece(struct pieces p){
//à modifier pour remplacer les int par string qui correspond
    printf("couleur: %d\ntaille : %d\ntype   : %d\nforme  : %d\n \n",
        p.couleur , p.taille, p.type , p.forme );
}

void placer_piece(struct pieces* p, struct ttableau* t, int num_rangee,int num_colonne){
    t->cases[ 4 * num_colonne + num_rangee] = *p;
}

int verifier_piece_utilise(struct pieces *p, struct ttableau* t){
    // verifie si une piece p est deja placée ou non sur la table
    // enleve moi ces if immonde.... creer des fct annexe?
    // >fct_a()->fct_b()->fct_c()->fct_d(d)->reponse booleen?
    //   -liste intermediare ds les parametre, si liste vide >alors False (pense au hash_table)
    // >affectation conditionnelle?
    int i;
    for (i = 0; i < 16; ++i){
        if(t->cases[i].couleur == p->couleur){            
            if(t->cases[i].taille == p->taille){
                if(t->cases[i].type == p->type){
                    if(t->cases[i].forme == p->forme)
                        return 1;
                }
            }
        }
    }        
    return 0;
}

int main(int argc, char const *argv[]){
    piece.couleur =0;
    piece.taille =1;
    piece.type =1;
    piece.forme =0;
    struct pieces p2={1,1,1,1};
    //print_piece(piece);
    placer_piece(&piece,&table,1,0);
    //print_piece(table.cases[1]);
    printf("%d\n",verifier_piece_utilise(&p2,&table));
    //print_piece(p2);

    return 0;
}