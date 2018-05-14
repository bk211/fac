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
#include <time.h>

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
    int i;
    for (i = 0; i < 16; ++i){
            tab->etat[i]=0;
        
    }
}

void placer_piece(int couleur, int taille, int type, int forme, struct ttableau* t, int num){
    t->cases[num].couleur = couleur;
    t->cases[num].taille = taille;
    t->cases[num].type = type;
    t->cases[num].forme = forme;
    t->etat[num] = 1;
}



struct pieces creer_piece(int couleur, int taille, int type, int forme){
    struct pieces resultat = {couleur, taille, type, forme};
    return resultat;
}


int check_case_occupe(struct ttableau *tab, int num){
    if(tab->etat[num]==1)
        return 1;
    return 0;
}

int table_de_jeu_remplie(struct ttableau *tab, int num){
    int i;
    for (i = 0; i < 16; ++i)
    {
        if(!check_case_occupe(tab,num))
            return 0;
    }
    return 1;
}

void cases_occupe_de_la_table(struct ttableau* tab, int * resultat){
    resultat[0] = 0;
    int i,k=0;
    for (i = 0; i < 16; ++i){
        if(check_case_occupe(tab,i)){
            resultat[k+1] = i;
            k++;
            resultat[0]=k;
        }    
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

/*================= secondaire  =====================*/
int check_aligne_annexe(int resultat_case_occupe[],int curseur, int indentation_du_pas, int nombrealigne){
    int i;
    int compteur = 0;
    for (i = 0; i < nombrealigne; i++){
        if(member(resultat_case_occupe,curseur)) // facilement remplacable par une test+affectation conditionnel
            compteur++;
        curseur += indentation_du_pas;
    }

    if(compteur == nombrealigne)
        return 1;
    return 0;
}

int check_aligne_verticale(int resultat_case_occupe[], int resultat_finale[], int nombrealigne){
    int i;
    for (i = 0; i <= 12; i += 4){ //iter 4 fois + i donne la tete de l'alignement horizontale
        if(check_aligne_annexe(resultat_case_occupe, i,1,nombrealigne)){ // le pas == 1
            resultat_finale[1] = i;
            resultat_finale[2] = 1;
            return 1;
        }
    }
    return 0;
}
int check_aligne_honrizontale(int resultat_case_occupe[], int resultat_finale[],int nombrealigne){
    int i;
    for (i = 0; i <= 3; i++){ //iter 4 fois + i donne la tete de l'alignement verticale
        if(check_aligne_annexe(resultat_case_occupe, i,4, nombrealigne)){ // le pas == 4
            resultat_finale[1] = i;
            resultat_finale[2] = 4;
            return 1;
        }
    }
    return 0;
}

int check_aligne_diagonale(int resultat_case_occupe[], int resultat_finale[],int nombrealigne){
    int i;
    int pas =5;
    for (i = 0; i <= 3; i += 3){//iter 2 fois comme il n'y a que 2 possibilité d'alignement
        if(check_aligne_annexe(resultat_case_occupe, i, 5,nombrealigne)){
            resultat_finale[1] = i;
            resultat_finale[2] = pas;
            return 1;}
        pas -= 2;// on passe vers l'autre diagonale où le pas est de 3 
    }
    return 0;
}

int check_aligne_second(int resultat_case_occupe[], int resultat_finale[], int nombrealigne){
    check_aligne_honrizontale(resultat_case_occupe, resultat_finale, nombrealigne)?
        :check_aligne_verticale(resultat_case_occupe, resultat_finale, nombrealigne)?
            :check_aligne_diagonale(resultat_case_occupe, resultat_finale, nombrealigne);
    if(resultat_finale[1]>=0 && resultat_finale[1] <=15)
        return 1;
    return 0;
}

/*================= fin fct secondaire  =====================*/

// phase 1 check d'alignement  
int check_phase1_alignement(int resultat_case_occupe[] , int resultat_finale[],int nombrealigne){
    //retourne 1 si alignement et affecte au tableau_finale les coordonnee d'alignement
    // sinon la fct retoune 0
    resultat_finale[0] = 0;
    resultat_finale[2] = 0;
    if(check_aligne_second(resultat_case_occupe, resultat_finale,nombrealigne)){
        resultat_finale[0] = 1;
        return 1;
    }
    return 0;
}

// phase 2 check des characteristique 
/*============ secondaire ===================== */
int check_couleur(struct ttableau *tab, int resultat_case_occupe_et_aligne[], int sous_type, int nombrealigne){
    //on va a la case precise puis on compare les sous type, si c'est faux cad pas d'alignement de meme type on retourne 0
    //a la fin, si on a finit de parcourir 4 fois le tableau, on a un alignement de sous type, on retourne 1; 

    int i;
    int count = 0;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_case_occupe_et_aligne[1] + i * resultat_case_occupe_et_aligne[2]].couleur != sous_type)
            count++;
    }
    if(count == nombrealigne)
        return 1;
    return 0;

}

int check_taille(struct ttableau *tab, int resultat_case_occupe_et_aligne[], int sous_type, int nombrealigne){
    int i;
    int count = 0;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_case_occupe_et_aligne[1] + i * resultat_case_occupe_et_aligne[2]].taille != sous_type)
            count++;
    }
    if(count == nombrealigne)
        return 1;
    return 0;

}

int check_type(struct ttableau *tab, int resultat_case_occupe_et_aligne[], int sous_type, int nombrealigne){
    int i;    
    int count = 0;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_case_occupe_et_aligne[1] + i * resultat_case_occupe_et_aligne[2]].type != sous_type)
            count++;
    }
    if(count == nombrealigne)
        return 1;
    return 0;

}
int check_forme(struct ttableau *tab, int resultat_case_occupe_et_aligne[], int sous_type, int nombrealigne){
    int i;    
    int count = 0;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_case_occupe_et_aligne[1] + i * resultat_case_occupe_et_aligne[2] ].forme != sous_type)
            count++;
    }
    if(count == nombrealigne)
        return 1;
    return 0;
    

}

/* ======================== fin fct secondaire ======================*/
int check_intermediaire_forme(struct ttableau *tab, int resultat_case_occupe_et_aligne[],int etat, int nombrealigne){
    //serie de fct entonnoir si on a un alignement de couleur alors on affecte 1 a la case [3] des resultats,et on continue si ce n'est pas le cas
    //a la fin si il n'y a pas d'alignement, la case[3] des resultats prend la valeur 0
    //des lors,la case [4] est affecte de la valeur -1 par la fct check_intermediaire2

    resultat_case_occupe_et_aligne[3]=check_couleur(tab, resultat_case_occupe_et_aligne, etat, nombrealigne)? 1 
        :check_taille(tab, resultat_case_occupe_et_aligne, etat, nombrealigne)? 2 
            :check_type(tab, resultat_case_occupe_et_aligne, etat, nombrealigne)? 3 
                :check_forme(tab, resultat_case_occupe_et_aligne, etat, nombrealigne)? 4: 0;
    return resultat_case_occupe_et_aligne[3];
}

void check_intermediaire2(struct ttableau *tab, int resultat_case_occupe_et_aligne[], int nombrealigne){
    // on chereche le sous type d'alignement 
    // cad si type = couleur ,sous type = noire ou rouge (0 ou 1);
    // en meme tps il fait appelle a check_intermediaire qui va affecter le type

    if(check_intermediaire_forme(tab, resultat_case_occupe_et_aligne,0,nombrealigne))
        resultat_case_occupe_et_aligne[4] = 0;
    else if(check_intermediaire_forme(tab, resultat_case_occupe_et_aligne,1,nombrealigne))
        resultat_case_occupe_et_aligne[4] = 1;
    
    /*else
        resultat_case_occupe_et_aligne[4] = -1;
    necessaire? a voir;
    */
}

void procedure_de_fin_de_jeu(int resultat_final[],int *nombre_de_coup){
    if(resultat_final[3] && *nombre_de_coup <= 16){
        printf("fin de jeu,victoire du joueur %d\n",*nombre_de_coup/2);
        exit(1);
    }
    else if(resultat_final[3] == -1 && *nombre_de_coup ==16){
        printf("fin de jeu, match nul");
        exit(1);
    }
}

int check_finale4(struct ttableau *tab, int resultat_intermediaire[], int resultat_final[]){
    // retourne un bool selon un cas de victoire ou rien
    // etat d'arret cad cas de match nul a definir > procedure de match nul
    cases_occupe_de_la_table(tab,resultat_intermediaire);
    if(check_phase1_alignement(resultat_intermediaire, resultat_final,4)){
        free(resultat_intermediaire);
        check_intermediaire2(tab,resultat_final,4);
        if(resultat_final[3])
            printf("nice alignement \n");
        //retourne 1 et on lance la procedure de fin de jeu();
        
        else if(!resultat_final[3])
            printf("pas d'aliement\n");
    }
}


void affiche_table_de_jeu(struct ttableau* tab){
    int i;

    for (i = 0; i < 10; ++i)
    {
        printf("=");
    }
    printf("\n");

    for (int j = 0; j < 16; ++j) // on parcours chaque case
    {   
        if(!(j % 4)){
            printf("\n");
        }

        if(tab->etat[j]){ // case occupe
            tab->cases[j].couleur? printf("B") :printf("A");
            tab->cases[j].taille? printf("D") :printf("C");
            tab->cases[j].type? printf("F") :printf("E");
            tab->cases[j].forme? printf("H") :printf("G");
            printf(" ");
        }
        else if(!tab->etat[j]){ //case non occupe
            printf(".... ");
        }
    }

    printf("\n\n=");
    for (i = 0; i < 10; ++i)
    {
        printf("=");
    }
}

int boucle_de_saisie(int a, int b){
    //retourne l'entier i ssi il est compris dans intervalle [a,b]
    int i;
    do{
        fflush(stdin);
        //necessaire pour eviter un bug de boucle infinie si utilisateur saisie un type non int comme une charactere par exemple
        //meme si un char est un int...(scanf)
        printf("merci de saisir un nombre compris entre %d et %d\n", a, b);
        scanf("%d",&i);
    }while( i <a || i>b ||sizeof(i) != sizeof(int) );
    return i;
}

int comparer_characteristique(int a, int b){
    if(a == b)
        return 1;
    return 0;
}

int verifier_piece_utilise(int couleur, int taille, int type, int forme,struct ttableau* tab, int* resultat_case_occupe){
    int i;
    int a;
    for (i = 1; i <= resultat_case_occupe[0]; ++i){
        if(comparer_characteristique(tab->cases[resultat_case_occupe[i]].couleur,couleur)
        && comparer_characteristique(tab->cases[resultat_case_occupe[i]].taille,taille)
        && comparer_characteristique(tab->cases[resultat_case_occupe[i]].type,type)
        &&comparer_characteristique(tab->cases[resultat_case_occupe[i]].forme,forme))
            return 1;
    }
    return 0;
};

/*partie joueur*/
void saisie_piece(struct ttableau* tab,int resultat_case_occupe[], int* nombre_de_coup){
    int numero_case, couleur, taille, type, forme ;
    int verrou_etat=1;

    do{
        printf("case de jeu? ");
        numero_case = boucle_de_saisie(0,15);
    }while(check_case_occupe(tab,numero_case));

    cases_occupe_de_la_table(tab, resultat_case_occupe);
    
    while(verrou_etat){
        printf("couleur? (0 pour noire, 1 pour blanche) ");
        couleur = boucle_de_saisie(0,1);

        printf("taille? (0 pour grande, 1 pour petite)  ");
        taille = boucle_de_saisie(0,1);
        //taille =0;

        printf("type? (0 pour animal, 1 pour vegetal)   ");
        type = boucle_de_saisie(0,1);
        //type = 1;

        printf("forme? (0 pour ronde, 1 pour carre)     ");
        forme = boucle_de_saisie(0,1);
        //forme = 0;
        if(verifier_piece_utilise(couleur, taille, type, forme, tab, resultat_case_occupe))
            printf("piece deja utilise, merci de recommencer la saisie des characteristique\n");
        else
            verrou_etat = 0;
    }

    placer_piece(couleur, taille, type, forme,tab, numero_case);
    nombre_de_coup++;
}

/*====================*partie random*/
int tirage(int max){
    //tire au sort un nombre compris entre 0 inclus max; 
    //srand((unsigned)time(NULL));
    rand();
    return (double)(rand()/(double)(RAND_MAX) * (max+1));
}

void saisie_piece_random(struct ttableau* tab,int resultat_case_occupe[], int* nombre_de_coup){
    int numero_case, couleur, taille, type, forme ;
    int verrou_etat=1;
    srand((unsigned)time(NULL));

    do{
        numero_case = tirage(15);
    }while(check_case_occupe(tab,numero_case));

    cases_occupe_de_la_table(tab, resultat_case_occupe);
    //printf("%d %d %d %d %d\n",resultat_case_occupe[0],resultat_case_occupe[1],resultat_case_occupe[2],resultat_case_occupe[3],resultat_case_occupe[4],resultat_case_occupe[5]);
    
    while(verrou_etat){
        couleur = tirage(1);

        taille = tirage(1);

        type = tirage(1);

        forme = tirage(1);

        if(!verifier_piece_utilise(couleur, taille, type, forme, tab, resultat_case_occupe))
            verrou_etat = 0;
    }

    placer_piece(couleur, taille, type, forme,tab, numero_case);
    nombre_de_coup++;

    //cases_occupe_de_la_table(tab, resultat_case_occupe);
    //printf("%d %d %d %d %d %d \n",resultat_case_occupe[0],resultat_case_occupe[1],resultat_case_occupe[2],resultat_case_occupe[3],resultat_case_occupe[4],resultat_case_occupe[5]);
}

/*=========partie AI ==================*/


void analyse_AI(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[]){
    cases_occupe_de_la_table(tab,resultat_intermediaire);
    // retourne un bool selon un cas de victoire ou rien
    // etat d'arret cad cas de match nul a definir > procedure de match nul
    if(check_phase1_alignement(resultat_intermediaire, resultat_finale,3)){
        
    check_intermediaire2(&table, resultat_finale, 3);
    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n",resultat_finale[i] );
    }
    }
    
}


/*===============partie jeu===========*/
void game(struct ttableau* tab){
    int * resultat_intermediaire= malloc(17 * sizeof(int));//case occupe 
    int * resultat_finale= malloc(5 * sizeof(int));
    cases_occupe_de_la_table(tab,resultat_intermediaire);
    //check_finale(&table, resultat_intermediaire,resultat_finale);
    int a=check_aligne_annexe(resultat_intermediaire,0,4,3);
    int b=0;
    analyse_AI(&table,resultat_intermediaire,resultat_finale);

    //printf("%d %d\n",a ,b);
    free(resultat_intermediaire);
    free(resultat_finale);
}


int main(int argc, char const *argv[]){
    initialisation_table(&table);
    //print_piece(piece);
    //placer_piece(0,0,0,0,&table,0);
    placer_piece(1,1,1,1,&table,0);
    placer_piece(0,1,0,1,&table,4);
    placer_piece(0,0,0,1,&table,8);
    game(&table);
    //saisie_piece(&table,&a);
    //saisie_piece(&table,&a);
    affiche_table_de_jeu(&table);
    return 0;
//excetion saisie char;                    1n
}