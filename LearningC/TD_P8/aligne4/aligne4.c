/*Aligne 4
Part.1 
Le jeu se deroule sur une grille 4x4.
Il y a 16 types de pieces.
Chaque piece possede 4 caracteristiques binaires :
  sa couleur (noire ou blanche) ;
  sa taille (grande ou petite) ; 
  son type (animal ou vegetal) ; 
  sa forme (ronde ou carree). 

Part.2
Le gagnant est le joueur qui parvient a 
    -aligner 4 pieces 
        -horizontalement
        ou
        -verticalement
        ou
        -diagonale. 
    -ayant une caracteristique commune
Part.2.5
Il peut y avoir un match nul si 
    grille est remplie
    et  
    pas d’alignement.

Part.3
Interface Graphique

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

struct ttableau{
    // une initialisation de ttes les pieces a -1 est peut etre necessaire, a voir
    //struct pieces cases[16];
    struct pieces cases[16];
    int etat[16];
    // 0 -> vide    , 1 -> occupe
/*                 0 <= y < 4     
    0  1  2  3   >> 0  + y      >> x*4 + y   > x=0 
    4  5  6  7   >> 4  + y      >> x*4 + y   > x=1
    8  9  10 11  >> 8  + y      >> x*4 + y   > x=2
    12 13 14 15  >> 12 + y      >> x*4 + y   > x=3
*/
/*
    00 10 20 30
    01 11 21 31
    02 12 22 32
    03 13 23 33
*/
};

struct ttableau table;

void initialisation_table(struct ttableau *tab){
    // initialise la table de jeu en donnant chaque cases de jeu l'etat 0 (inoccupé)
    int i,j;
    for (i = 0; i < 16; ++i){
            tab->etat[i]=0;
        
    }
}

void print_piece(struct pieces p){
//à modifier pour remplacer les int par string qui correspond
    printf("couleur: %d\ntaille : %d\ntype   : %d\nforme  : %d\n \n",
        p.couleur , p.taille, p.type , p.forme );
}

void placer_piece(struct pieces* p, struct ttableau* t, int num){
    t->cases[num] = *p;
    t->etat[num] = 1;
}

int verifier_piece_utilise(struct pieces *p, struct ttableau* t){
    // verifie si une piece p est deja placée ou non sur la table
    // enleve moi ces if immonde.... creer des fct annexe?
    // >fct_a()->fct_b()->fct_c()->fct_d(d)->reponse booleen?
    //   -liste intermediare ds les parametre, si liste vide >alors False (pense au hash_table)
    // >affectation conditionnelle?
    int i,j;
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


struct pieces creer_piece(int couleur, int taille, int type, int forme){
    struct pieces resultat = {couleur, taille, type, forme};
    return resultat;
}

int check_case_occupe(struct ttableau *tab, int num){
    if(!tab->etat[num])
        return 0;
    return 1;
}

int * cases_occupe_de_la_table(struct ttableau* tab){
    int * resultat = malloc(16 * sizeof(int));// remplacer plutard 16 par nb de coup joue > economie memoire
    resultat[0] = 0;
    int i,j,k=1;
    for (i = 0; i < 16; ++i){
        if(check_case_occupe(tab,i)){
            resultat[k] = 4*j+i;
            resultat[0]=k;
            k++;
        }    
    }
    /*
    for (int m = 0; m <= resultat[0]; ++m)
    {
        printf("%d ,",resultat[m]);   
    }*/
    return resultat;
}

void printf_table(struct ttableau* tab){
    int i,j;
    for (i = 0; i < 16; ++i){
        if(check_case_occupe(tab,i))
            print_piece(tab->cases[i]);
    }
}



int member(int tab[],int elem){
    int i;
    for (i = 1; i <= tab[0]; ++i){
        if(elem == tab[i])
            return 1;
    }
    return 0;
}

struct stockage_alignement{
    int tete;
    int pas; // ou type d'alignement honri verti diago
    int nature_d_alignement; // couleur taille type forme 
};

int check_aligne4_annexe(int resultat_case_occupe[],int curseur, int indentation_du_pas){
    int i;
    for (i = 0; i < 4; i++){
        if(!member(resultat_case_occupe,curseur)) // facilement remplacable par une test+affectation conditionnel
            return 0;
        curseur += indentation_du_pas;
    }
    return 1;
}

int check_aligne4_verticale(int resultat_case_occupe[], struct stockage_alignement* temp){
    int i;
    for (i = 0; i <= 12; i += 4){ //iter 4 fois + i donne la tete de l'alignement horizontale
        if(check_aligne4_annexe(resultat_case_occupe, i,1)){ // le pas == 1
            temp->pas = 1;
            temp->tete= i;
            return 1;
        }
    }
}

int check_aligne4_honrizontale(int resultat_case_occupe[], struct stockage_alignement* temp){
    int i;
    for (i = 0; i <= 3; i++){ //iter 4 fois + i donne la tete de l'alignement verticale
        if(check_aligne4_annexe(resultat_case_occupe, i,4)){ // le pas == 4
            temp->pas = 4;
            temp->tete= i;
            return 1;
        }
    }
}

int check_aligne4_diagonale(int resultat_case_occupe[], struct stockage_alignement* temp){
    int i, pas = 5;
    for (i = 0; i <= 3; i += 3){//iter 2 fois comme il n'y a que 2 possibilité d'alignement
        if(check_aligne4_annexe(resultat_case_occupe, i, pas)){
            temp->pas = pas;
            temp->tete= i;
            return 1;}
        pas -= 2;// on passe vers l'autre diagonale où le pas est de 3 
    }
    return 0;
}


int check_aligne_terminale(int resultat_case_occupe[],struct stockage_alignement *temp){
//si c'est vrai la fct check_aligne affecte une valeur + non nul a temporaire pas, sinon on verifie un autre patterne d'alignement
    check_aligne4_honrizontale(resultat_case_occupe, temp)?
        :check_aligne4_verticale(resultat_case_occupe, temp)?
            :check_aligne4_diagonale(resultat_case_occupe, temp);
    if(temp->pas)
        return 1;
    return 0;
}


int* reformatage_resultat_si_aligne4(int resultat_case_occupe[]){
    struct stockage_alignement temporaire;
    temporaire.pas = 0;
    int * resultat = malloc(5 * sizeof(int));
    resultat[0] = 0;
    if(check_aligne_terminale(resultat_case_occupe, &temporaire)){
        resultat[0] = 1;
        resultat[1] = temporaire.tete;
        resultat[2] = temporaire.pas;
    }
    return resultat;
}

int check_couleur(struct ttableau *tab, int resultat_case_occupe_et_aligne4[], int couleur){
    int i;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_case_occupe_et_aligne4[1] + i * resultat_case_occupe_et_aligne4[2]].couleur != couleur)
            return 0;
    }
    return 1;
}

int check_taille(struct ttableau *tab, int resultat_case_occupe_et_aligne4[], int taille){
    int i;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_case_occupe_et_aligne4[1] + i * resultat_case_occupe_et_aligne4[2]].taille != taille)
            return 0;
    }
    return 1;
}

int check_type(struct ttableau *tab, int resultat_case_occupe_et_aligne4[], int type){
    int i;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_case_occupe_et_aligne4[1] + i * resultat_case_occupe_et_aligne4[2]].type != type)
            return 0;
    }
    return 1;
}
int check_forme(struct ttableau *tab, int resultat_case_occupe_et_aligne4[], int forme){
    int i;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_case_occupe_et_aligne4[1] + i * resultat_case_occupe_et_aligne4[2]].forme != forme)
            return 0;
    }
    return 1;
}

int check_intermediaire(struct ttableau *tab, int resultat[],int etat){ //resultat_case_occupe_et_aligne4
    resultat[3]=check_couleur(tab, resultat, etat)? 1 
        :check_taille(tab, resultat, etat)? 2 
            :check_type(tab, resultat, etat)? 3 
                :check_forme(tab, resultat, etat)? 4: 0;
    return resultat[3];
}

int check_finale(struct ttableau *tab, int resultat[]){
    if(check_intermediaire(tab, resultat,0))
        resultat[4] = 0;
    else if(check_intermediaire(tab, resultat, 1))
        resultat[4] = 1;
}



int main(int argc, char const *argv[]){
    struct pieces p1={0,0,0,0};
    struct pieces p2={0,0,1,1};
    struct pieces p3={0,1,0,1};
    struct pieces p4={1,0,0,1};
    initialisation_table(&table);
    //print_piece(piece);
    placer_piece(&p1,&table,0);
    placer_piece(&p2,&table,5);
    placer_piece(&p3,&table,10);
    placer_piece(&p4,&table,15);
    int resultat[5]={1,0,5,1};
    check_finale(&table,resultat);
    for (int i = 0; i < 5; ++i)
    {
    printf("%d\n",resultat[i] );}
        /* code */
    //cases_occupe_de_la_table(&table);
    //printf_table(&table);
    //print_piece(table.cases[3]);
    //printf("%d\n",verifier_piece_utilise(&p2,&table));
    //print_piece(p2);
    //print_piece(creer_piece(0,0,0,0));
    //int test_aligne[5]={4,0,1,2,4}; // non valide 0
    //int test_aligne2[5]={4,0,4,8,12}; //verticale 1
    //int test_aligne3[5]={4,1,5,9,13}; // verticale 1
    //int test_aligne4[5]={4,0,5,10,15}; // diagonale 1
    //int test_aligne5[5]={4,3,6,9,12}; // diagonale 1
    //int test_aligne6[6]={5,0,1,5,2,3}; // honrizontale 1
    //int test_aligne7[10]={7,12,13,5,14,2,3,15}; // honrizontale 1
    //reformatage_resultat_si_aligne4(test_aligne);
    //reformatage_resultat_si_aligne4(test_aligne2);
    //reformatage_resultat_si_aligne4(test_aligne3);
    //reformatage_resultat_si_aligne4(test_aligne4);
    //reformatage_resultat_si_aligne4(test_aligne5);
    //reformatage_resultat_si_aligne4(test_aligne6);
    //reformatage_resultat_si_aligne4(test_aligne6);
    


    return 0;
}