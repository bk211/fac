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

};

struct ttableau table;

void initialisation_table(struct ttableau *tab){
    // initialise la table de jeu en donnant chaque cases de jeu l'etat 0 (inoccupe)
    int i;
    for (i = 0; i < 16; ++i){
            tab->etat[i]=0;
            tab->cases[i].couleur =-1;
            tab->cases[i].taille =-1;
            tab->cases[i].type =-1;
            tab->cases[i].forme =-1;

        
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


int membre_case_occupe(int tab[],int elem){
    int i;
    for (i = 1; i <= tab[0]; ++i){
        if(elem == tab[i])
            return 1;
    }
    return 0;
}

/*================= secondaire  =====================*/
void affiche_(int * tab){
    for (int i = 0; i < 5; ++i)
    {
        printf("%d=%d ,",i,tab[i]);
    }
}

int check_aligne_annexe(int resultat_case_occupe[],int tete, int indentation_du_pas, int nombrealigne){
    int i;
    int compteur = 0;
    int curseur = tete;
    for (i = 0; i < 4; i++){
        if(membre_case_occupe(resultat_case_occupe,curseur)) 
            compteur++;
        curseur += indentation_du_pas;
    }
    if(compteur == nombrealigne)
        return 1;
    return 0;
}



/*============ secondaire ===================== */
int check_couleur(struct ttableau *tab, int resultat_finale[], int sous_type, int nombrealigne){
    int i;
    int compteur = 0;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_finale[1] + i * resultat_finale[2]].couleur == sous_type){
            compteur++;            
        }
    }
    if(compteur == nombrealigne)
        return 1;
    return 0;
    
}

int check_taille(struct ttableau *tab, int resultat_finale[], int sous_type, int nombrealigne){
    int i;
    int compteur = 0;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_finale[1] + i * resultat_finale[2]].taille == sous_type){
            compteur++;
        }
    }
    if(compteur == nombrealigne)
        return 1;
    return 0;
    
}

int check_type(struct ttableau *tab, int resultat_finale[], int sous_type, int nombrealigne){
    int i;
    int compteur = 0;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_finale[1] + i * resultat_finale[2]].type == sous_type){
            compteur++;   
        }
    }
    if(compteur == nombrealigne)
        return 1;
    return 0;
    
}
int check_forme(struct ttableau *tab, int resultat_finale[], int sous_type, int nombrealigne){
    int i;
    int compteur = 0;
    for (i = 0; i < 4; ++i){
        if(tab->cases[ resultat_finale[1] + i * resultat_finale[2]].forme == sous_type){
            compteur++;   
        }
    }
    if(compteur == nombrealigne)
        return 1;
    return 0;
    
}


/* ======================}== fin fct secondaire ======================*/
int check_intermediaire_forme(struct ttableau *tab, int resultat_finale[],int etat, int nombrealigne){
    if(check_couleur(tab, resultat_finale, etat, nombrealigne))
        resultat_finale[3] = 1;
    else if(check_taille(tab, resultat_finale, etat, nombrealigne))
        resultat_finale[3] = 2;
    else if(check_type(tab, resultat_finale, etat, nombrealigne))
        resultat_finale[3] = 3; 
    else if(check_forme(tab, resultat_finale, etat, nombrealigne))
        resultat_finale[3] = 4;
    else 
        resultat_finale[3]= 0;
    
}

void check_forme_finale(struct ttableau *tab, int resultat_finale[], int nombrealigne){
    // on chereche le sous type d'alignement 
    // cad si type = couleur ,sous type = noire ou rouge (0 ou 1);
    // en meme tps il fait appelle a check_intermediaire qui va affecter le type

    check_intermediaire_forme(tab, resultat_finale,0,nombrealigne);
    if(resultat_finale[3]==0){

        check_intermediaire_forme(tab, resultat_finale,1,nombrealigne);
        resultat_finale[4] = 1;
    }
    else
        resultat_finale[4] = 0;

}

int validation(int resultat_finale[]){
    if(resultat_finale[0] ==1
        && resultat_finale[1] >=0
        && resultat_finale[1] <=15
        && resultat_finale[3] >0
        && resultat_finale[3] <=4 
        && (resultat_finale[4] == 0 || resultat_finale[4] == 1))
        return 1;
    return 0; 
}
void affiche_table_de_jeu(struct ttableau* tab);
void procedure_de_fermeture_du_jeu(int resultat_intermediaire[],int resultat_finale[]);
int conversion_nb_de_coup_jouer(int nombre_de_coup);

void check_horizontale4(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup){
    for (int i = 0; i <= 12; i+=4){
        if(check_aligne_annexe(resultat_intermediaire,i, 1, 4)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = 1;
            check_forme_finale(tab, resultat_finale, 4);

            if(validation(resultat_finale)){
                printf("\n\n>>Le joueur %d a aligne honrizontalement 4 pieces, il remporte la victoire!!!\n",conversion_nb_de_coup_jouer(*nombre_de_coup) );
                procedure_de_fermeture_du_jeu(resultat_intermediaire,resultat_finale);
            }
        }
    }
}

void check_verticale4(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup){
    for (int i = 0; i <= 3 ; i++){
        if(check_aligne_annexe(resultat_intermediaire,i, 4, 4)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = 4;
            check_forme_finale(tab, resultat_finale, 4);

            if(validation(resultat_finale)){
                printf("\n\n>>Le joueur %d a aligne verticalement 4 pieces, il remporte la victoire!!!\n",conversion_nb_de_coup_jouer(*nombre_de_coup) );
                procedure_de_fermeture_du_jeu(resultat_intermediaire,resultat_finale);
            }
        }
    }
}

void check_diagonale4(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup){
    int pas = 5;
    for (int i = 0; i < 2 ; i++){
        if(check_aligne_annexe(resultat_intermediaire,i, pas, 4)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = pas;
            check_forme_finale(tab, resultat_finale, 4);

            if(validation(resultat_finale)){
                printf("\n\n>>Le joueur %d a aligne diagonalement 4 pieces, il remporte la victoire!!!\n",conversion_nb_de_coup_jouer(*nombre_de_coup) );
                procedure_de_fermeture_du_jeu(resultat_intermediaire,resultat_finale);
            }
        }
        pas = 3;
    }
}



void procedure_de_fermeture_du_jeu(int resultat_intermediaire[],int resultat_finale[]){
    free(resultat_finale);
    free(resultat_intermediaire);
    printf("\n>>>Fin de jeu,merci\n");
    exit(EXIT_SUCCESS);
}

void affiche_table_de_jeu(struct ttableau* tab){
    int i;

    for (i = 0; i < 20; ++i)
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
            tab->cases[j].couleur? printf("B") :printf("N");
            tab->cases[j].taille? printf("P") :printf("G");
            tab->cases[j].type? printf("V") :printf("A");
            tab->cases[j].forme? printf("C") :printf("R");
            printf(" ");
        }
        else if(!tab->etat[j]){ //case non occupe
            printf(".... ");
        }
    }

    printf("\n\n=");
    for (i = 0; i < 20; ++i)
    {
        printf("=");
    }
}


void check_finale_aligne4(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup){
    cases_occupe_de_la_table(tab,resultat_intermediaire);

    check_horizontale4(tab, resultat_intermediaire, resultat_finale,nombre_de_coup);
    check_verticale4(tab, resultat_intermediaire, resultat_finale,nombre_de_coup);
    check_diagonale4(tab, resultat_intermediaire, resultat_finale,nombre_de_coup);
    
    
    if(*nombre_de_coup <15){
        printf("\nNous n'avons pas trouve d'alignement, c'est au joueur %d de jouer\n\n", conversion_nb_de_coup_jouer(*nombre_de_coup));           
    }
    else if(*nombre_de_coup ==15){
        affiche_table_de_jeu(tab);
        printf("\nToutes pieces ont ete joue, nous avons un match nul\n\n");
        procedure_de_fermeture_du_jeu(resultat_intermediaire,resultat_finale);
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
    for (i = 1; i <= resultat_case_occupe[0]; ++i){
        if(comparer_characteristique(tab->cases[resultat_case_occupe[i]].couleur,couleur)
        && comparer_characteristique(tab->cases[resultat_case_occupe[i]].taille,taille)
        && comparer_characteristique(tab->cases[resultat_case_occupe[i]].type,type)
        &&comparer_characteristique(tab->cases[resultat_case_occupe[i]].forme,forme))
            return 1;
    }
    return 0;
};


int coin_flip(int a){
    //si a est faut la fct retourne 1, sinon pour toutes les autres valeurs de a, elle retourne 0
    if(!a)
        return 1;
    return 0;
}

int confirmation_saisie(int numero_case,int couleur,int taille,int type,int forme){
    int reponse;
    printf("\nvous avez choisis la case numero %d et la piece :",numero_case);
    couleur? printf("B") :printf("N");
    taille? printf("P") :printf("G");
    type? printf("V") :printf("A");
    forme? printf("C") :printf("R");
    printf("\n>> confirmez? (1/0) ");
    reponse = coin_flip(boucle_de_saisie(0,1));
    return reponse;
}


/*partie joueur*/
void saisie_piece(struct ttableau* tab,int resultat_case_occupe[]){
    int numero_case, couleur, taille, type, forme ;
    int verrou_etat=1;

    cases_occupe_de_la_table(tab, resultat_case_occupe);
    while(verrou_etat){
        
        do{
            printf("\ncase de jeu? ");
            numero_case = boucle_de_saisie(0,15);
        }while(check_case_occupe(tab,numero_case));

        printf("couleur? (0 pour Noire, 1 pour Blanche) ");
        couleur = boucle_de_saisie(0,1);

        printf("taille? (0 pour Grande, 1 pour Petite)  ");
        taille = boucle_de_saisie(0,1);
        //taille =0;

        printf("type? (0 pour Animal, 1 pour Vegetal)   ");
        type = boucle_de_saisie(0,1);
        //type = 1;

        printf("forme? (0 pour Ronde, 1 pour Carre)     ");
        forme = boucle_de_saisie(0,1);
        //forme = 0;
        if(verifier_piece_utilise(couleur, taille, type, forme, tab, resultat_case_occupe))
            printf("piece deja utilise, merci de recommencer la saisie des characteristique\n");
        else{
            verrou_etat = confirmation_saisie(numero_case,couleur, taille, type, forme);
            
        }
    }

    placer_piece(couleur, taille, type, forme,tab, numero_case);

}

/*====================*partie random*/
int tirage(int max){
    //tire au sort un nombre compris entre 0 inclus max; 
    //srand((unsigned)time(NULL));
    rand();
    return (double)(rand()/(double)(RAND_MAX) * (max+1));
}

void saisie_piece_random(struct ttableau* tab,int resultat_case_occupe[]){
    int numero_case, couleur, taille, type, forme ;
    int verrou_etat=1;

    while(verrou_etat){
        srand((unsigned)time(NULL));

        do{
        numero_case = tirage(15);
        }while(check_case_occupe(tab,numero_case));

        couleur = tirage(1);

        taille = tirage(1);

        type = tirage(1);

        forme = tirage(1);

        if(!verifier_piece_utilise(couleur, taille, type, forme, tab, resultat_case_occupe))
            verrou_etat = 0;
    }

    placer_piece(couleur, taille, type, forme,tab, numero_case);
    
}

/*=========partie AI LV1 ==================*/
int compter_nb_charac_piece_utilise(int couleur, int taille, int type, int forme,struct ttableau* tab, int* resultat_case_occupe){
    int i;
    int compteur = 0;
    for (i = 1; i <= resultat_case_occupe[0]; ++i){
        if(comparer_characteristique(tab->cases[resultat_case_occupe[i]].couleur,couleur)
        || comparer_characteristique(tab->cases[resultat_case_occupe[i]].taille,taille)
        || comparer_characteristique(tab->cases[resultat_case_occupe[i]].type,type)
        || comparer_characteristique(tab->cases[resultat_case_occupe[i]].forme,forme))
            compteur++;

    }
    return compteur;

}

int numero_case_vide(struct ttableau* tab, int resultat_finale[]){
    //retourne la premiere numero de case vide trouve, sinon on retourne -1
    int i;
    int reponse;
    for (i = 0; i < 4; ++i){
        if(!tab->etat[ resultat_finale[1]+ i * resultat_finale[2]])//on parcours la rangee/colonne/diagonale en question et on cherche la premiere case non occupe
            reponse = resultat_finale[1]+ i * resultat_finale[2];
    }
    return reponse;
}



int generer_et_placer_piece_definie(struct ttableau* tab,int resultat_intermediaire[],int resultat_finale[],int numero_case){
    int compteur;
    int couleur, taille, type, forme ;
    int verrou_etat =1;
    while(verrou_etat){
        srand((unsigned)time(NULL));
        compteur = 1;

        couleur = tirage(1);
        if (compteur == resultat_finale[3]){
            couleur = resultat_finale[4];
            if(compter_nb_charac_piece_utilise(resultat_finale[4], -2, -2, -2, tab, resultat_intermediaire) ==8){
                return 0;
            }
        }
        compteur ++;
        
        taille = tirage(1);
        if (compteur == resultat_finale[3]){
            taille = resultat_finale[4];
            if(compter_nb_charac_piece_utilise(resultat_finale[4], -2, -2, -2, tab, resultat_intermediaire) ==8){
                return 0;
            }
        }
        compteur ++;

        type = tirage(1);
        if (compteur == resultat_finale[3]){
            type = resultat_finale[4];
            if(compter_nb_charac_piece_utilise(resultat_finale[4], -2, -2, -2, tab, resultat_intermediaire) ==8){
                return 0;
            }
        }
        compteur ++;

        forme = tirage(1);
        if (compteur == resultat_finale[3]){
            forme = resultat_finale[4];
            if(compter_nb_charac_piece_utilise(resultat_finale[4], -2, -2, -2, tab, resultat_intermediaire) ==8){
                return 0;
            }
        }

        if(!verifier_piece_utilise(couleur, taille, type, forme, tab, resultat_intermediaire))
            verrou_etat = 0;
    }

    placer_piece(couleur, taille, type, forme,tab, numero_case);
    return 1;
}
/*============mode joueur vs AI lv1 ===================*/
int check_forme_AI_et_placement(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[]){
    int i;
    for (i = 0; i < 2; ++i){
        if(check_couleur(tab, resultat_finale, i, 3)){
           int case_vide = numero_case_vide(tab, resultat_finale);
           resultat_finale[3] = 1;
           resultat_finale[4] = i;
           if(generer_et_placer_piece_definie( tab, resultat_intermediaire, resultat_finale,case_vide))
                goto cas_succes; 
        }

        else if(check_taille(tab, resultat_finale, i, 3)){
           int case_vide = numero_case_vide(tab, resultat_finale);
           resultat_finale[3] = 2;
           resultat_finale[4] = i;
           if(generer_et_placer_piece_definie( tab, resultat_intermediaire, resultat_finale,case_vide))
                goto cas_succes; 
        }

        else if(check_type(tab, resultat_finale, i, 3)){
           int case_vide = numero_case_vide(tab, resultat_finale);
           resultat_finale[3] = 3;
           resultat_finale[4] = i;
           if(generer_et_placer_piece_definie( tab, resultat_intermediaire, resultat_finale,case_vide))
                goto cas_succes; 
        }

        else if(check_forme(tab, resultat_finale, i, 3)){
           int case_vide = numero_case_vide(tab, resultat_finale);
           resultat_finale[3] = 4;
           resultat_finale[4] = i;
           if(generer_et_placer_piece_definie( tab, resultat_intermediaire, resultat_finale,case_vide))
                goto cas_succes; 
        }
    }
    return 0;

    cas_succes:
        return 1;
    
}

int check_horizontale3_AI(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[]){
    int i;
    for (i = 0; i <= 12; i+=4){
        if(check_aligne_annexe(resultat_intermediaire,i, 1, 3)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = 1;
            if(check_forme_AI_et_placement(tab, resultat_intermediaire, resultat_finale)){
                return 1;
            }
        }
    }
    return 0;
}

int check_verticale3_AI(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[]){
    int i;
    for (i = 0; i <= 3; i++){
        if(check_aligne_annexe(resultat_intermediaire,i, 1, 3)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = 4;
            if(check_forme_AI_et_placement(tab, resultat_intermediaire, resultat_finale)){
                return 1;
            }
        }
    }
    return 0;
}

int check_diagonale3_AI(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[]){
    int i;
    int pas = 5;
    for (i = 0; i < 2; i++){
        if(check_aligne_annexe(resultat_intermediaire,i, 1, 3)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = pas;
            if(check_forme_AI_et_placement(tab, resultat_intermediaire, resultat_finale)){
                return 1;
            }
        }
        pas -= 2;
    }
    return 0;
}





/*===========mode joueur contre joueur=======*/
int conversion_nb_de_coup_jouer(int nombre_de_coup){
    if(nombre_de_coup%2==0)
        return 1;
    return 2;
}

void game_mode_joueur(struct ttableau* tab,int resultat_intermediaire[],int resultat_finale[],int * nombre_de_coup){
    cases_occupe_de_la_table(tab,resultat_intermediaire);
    saisie_piece(tab,resultat_intermediaire);
    printf("\n>>Le Joueur %d a joue le coup numero %d\n",conversion_nb_de_coup_jouer(*nombre_de_coup),*nombre_de_coup+1);
    affiche_table_de_jeu(tab);
    nombre_de_coup++;
    check_finale_aligne4(tab,resultat_intermediaire,resultat_finale,nombre_de_coup);
        
}

/*===========mode joueur contre AI random=======*/
void game_1vsAI_random(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup){
    cases_occupe_de_la_table(tab,resultat_intermediaire);
    saisie_piece_random(tab, resultat_intermediaire);
    affiche_table_de_jeu(tab);
    printf("\n>>Le Joueur 2 joue le coup numero %d\n",*nombre_de_coup+1);
    nombre_de_coup++;
    check_finale_aligne4(tab,resultat_intermediaire,resultat_finale,nombre_de_coup);
}

/*===========mode joueur contre AI Lv1=======*/

void game_mode_AI_lv1(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup){
    cases_occupe_de_la_table(tab,resultat_intermediaire);

    if(!check_horizontale3_AI(tab,resultat_intermediaire,resultat_finale)|| !check_verticale3_AI(tab,resultat_intermediaire,resultat_finale) || !check_diagonale3_AI(tab,resultat_intermediaire,resultat_finale))
        saisie_piece_random(tab, resultat_intermediaire);

    affiche_table_de_jeu(tab);
    printf("\n>>Le Joueur 2 a joue le coup numero %d\n",*nombre_de_coup+1);
    nombre_de_coup++;
    check_finale_aligne4(tab,resultat_intermediaire,resultat_finale,nombre_de_coup);
}

/*===============partie jeu===========*/
void lanceur_de_jeu(struct ttableau* tab){
    int * resultat_intermediaire= malloc(17 * sizeof(int));//case occupe 
    int * resultat_finale= malloc(5 * sizeof(int));
    int nombre_de_coup = 0;
    printf("Bienvenue dans notre jeu d'aligne 4\nLe but du jeu est d'aligner 4 pieces de meme characteristique\nsur une même ligne,colonne ou diagonale\n");
    printf("Quelle mode de jeu voulez vous choisir?\n0 ==> 1 Vs 1\n1 ==> 1 Vs Random\n2 ==> 1 Vs AI Lv1\n3 ==> 1 Vs AI Lv2");
    int choix_mode =boucle_de_saisie(0,3);
    int verrou_etat = 1;
    
    if (choix_mode == 0){
        printf("Vous avez choisi le mode 1 vs 1\nLa partie va commencer\n");
        affiche_table_de_jeu(tab);
        while(verrou_etat){   
            game_mode_joueur(tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
        }   
    }
    if (choix_mode == 1){
        printf("Vous avez choisi le mode 1 vs random\nLa partie va commencer\n");
        affiche_table_de_jeu(tab);
        while(verrou_etat){
            game_mode_joueur(tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
            game_1vsAI_random(tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
        
        }
    }
    if (choix_mode == 2){
        printf("Vous avez choisi le mode 1 vs AI\nLa partie va commencer\n");
        affiche_table_de_jeu(tab);
        while(verrou_etat){
                game_mode_joueur(tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
                game_mode_AI_lv1(tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
        }

    }

}  



int main(int argc, char const *argv[]){
    initialisation_table(&table);
    //printf("%d\n",table.cases[12].couleur );
    //game_1vsAI_random(&table);
    placer_piece(1, 0, 0, 0,&table, 9);
    placer_piece(0, 1, 0, 1,&table, 10);
    placer_piece(0, 0, 1, 1,&table, 11);
    //saisie_piece(&table,&a);
    //saisie_piece(&table,&a);
    //affiche_table_de_jeu(&table);
    lanceur_de_jeu(&table);
    return 0;
//excetion saisie char;                    1n
}