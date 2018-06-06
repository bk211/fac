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
int check_aligne_annexe(int resultat_case_occupe[],int curseur, int indentation_du_pas, int nombrealigne){
    int i;
    int compteur = 0;
    for (i = 0; i < nombrealigne; i++){
        if(membre_case_occupe(resultat_case_occupe,curseur)) 
            compteur++;
        curseur += indentation_du_pas;
    }

    if(compteur == nombrealigne)
        return 1;
    return 0;
}

int check_aligne_verticale(int resultat_case_occupe[], int resultat_finale[], int nombrealigne){
    int i;
    for (i = 0; i <= 3; i ++){ //iter 4 fois + i donne la tete de l'alignement horizontale
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
    for (i = 0; i <= 12; i+=4){ //iter 4 fois + i donne la tete de l'alignement verticale
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
    for (i = 0; i <= 3; i += 3){//iter 2 fois comme il n'y a que 2 possibilite d'alignement
        if(check_aligne_annexe(resultat_case_occupe, i, 5,nombrealigne)){
            resultat_finale[1] = i;
            resultat_finale[2] = pas;
            return 1;
        }
        pas -= 2;// on passe vers l'autre diagonale où le pas est de 3 
    }
    return 0;
}

int check_aligne_second(int resultat_case_occupe[], int resultat_finale[], int nombrealigne, int type_alignement){
    if(nombrealigne == 4){
        check_aligne_honrizontale(resultat_case_occupe, resultat_finale, nombrealigne)?
            :check_aligne_verticale(resultat_case_occupe, resultat_finale, nombrealigne)?
                :check_aligne_diagonale(resultat_case_occupe, resultat_finale, nombrealigne);
    }
    else{
        if(type_alignement==1)
            check_aligne_honrizontale(resultat_case_occupe, resultat_finale, nombrealigne);
        else if(type_alignement==2)
            check_aligne_verticale(resultat_case_occupe, resultat_finale, nombrealigne);
        else if(type_alignement==3)
            check_aligne_diagonale(resultat_case_occupe, resultat_finale, nombrealigne);
        else
            return 0;
    };

    if(resultat_finale[1]>=0 && resultat_finale[1] <=15)
        return 1;
    return 0;
}

/*================= fin fct secondaire  =====================*/

// phase 1 check d'alignement  
int check_phase1_alignement(int resultat_case_occupe[] , int resultat_finale[],int nombrealigne,int type_alignement){
    //retourne 1 si alignement et affecte au tableau_finale les coordonnee d'alignement
    // sinon la fct retoune 0
    resultat_finale[0] = 0;
    resultat_finale[2] = 0;
    if(check_aligne_second(resultat_case_occupe, resultat_finale,nombrealigne,type_alignement)){
        resultat_finale[0] = 1;
        return 1;
    }
    return 0;
}

// phase 2 check des characteristique 
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

void affiche_(int * tab){
    for (int i = 0; i < 5; ++i)
    {
        printf("%d=%d ,",i,tab[i]);
    }
}
/* ======================}== fin fct secondaire ======================*/
int check_intermediaire_forme(struct ttableau *tab, int resultat_finale[],int etat, int nombrealigne){
    //serie de fct entonnoir si on a un alignement de couleur alors on affecte 1 a la case [3] des resultats,et on continue si ce n'est pas le cas
    //a la fin si il n'y a pas d'alignement, la case[3] des resultats prend la valeur 0
    //des lors,la case [4] est affecte de la valeur -1 par la fct check_forme_finale
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
    return resultat_finale[3];
}

int check_forme_finale(struct ttableau *tab, int resultat_finale[], int nombrealigne){
    // on chereche le sous type d'alignement 
    // cad si type = couleur ,sous type = noire ou rouge (0 ou 1);
    // en meme tps il fait appelle a check_intermediaire qui va affecter le type

    if(check_intermediaire_forme(tab, resultat_finale,0,nombrealigne))
        resultat_finale[4] = 0;
    else if(check_intermediaire_forme(tab, resultat_finale,1,nombrealigne))
        resultat_finale[4] = 1;
    else
        resultat_finale[4] = -1;
    //necessaire? a voir;
    return resultat_finale[4];
    
}

int check_horizontale(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int nombrealigne){
    for (int i = 0; i <= 12; i+=4){
        if(check_aligne_annexe(resultat_intermediaire,i, 1, 4)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = 1;
            affiche_(resultat_finale);
            if(check_forme_finale(tab, resultat_finale, nombrealigne >= 0)){
            affiche_(resultat_finale);
                return 1;
            }
        }
    }
    return 0;
}

int check_verticale(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int nombrealigne){
    for (int i = 0; i <= 3; i++){
        if(check_aligne_annexe(resultat_intermediaire,i,4, 4)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = 4;
            affiche_(resultat_finale);

            if(check_forme_finale(tab, resultat_finale, nombrealigne >= 0)){
            affiche_(resultat_finale);

                return 1;
            }
        }
    }
    return 0;
}    

int check_diagonale(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int nombrealigne){
    int pas = 5;
    for (int i = 0; i <=3; i+=3){
        if(check_aligne_annexe(resultat_intermediaire,i, pas, 4)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = pas;
            if(check_forme_finale(tab, resultat_finale, nombrealigne >= 0)){
                return 1;
            }
        pas -=2;
        }
    }   
    return 0;
}

void procedure_de_fermeture_du_jeu(int resultat_intermediaire[],int resultat_finale[]){
    free(resultat_finale);
    free(resultat_intermediaire);
    printf(">>fermeture du jeu en cours...\n");
    exit(1);
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
    int mode_alignement;

    if(check_horizontale(tab, resultat_intermediaire, resultat_finale,4)){
        affiche_table_de_jeu(tab);
        printf("\nLe joueur %d a aligne honrizontalement 4 pieces, il remporte la victoire!!!\n",*nombre_de_coup%2+1 );
        procedure_de_fermeture_du_jeu(resultat_intermediaire,resultat_finale);
    }

    else if(check_verticale(tab, resultat_intermediaire, resultat_finale,4)){
        affiche_table_de_jeu(tab);
        printf("\nLe joueur %d a aligne verticalement 4 pieces, il remporte la victoire!!!\n",*nombre_de_coup%2+1 );
        procedure_de_fermeture_du_jeu(resultat_intermediaire,resultat_finale);
    }

    else if(check_diagonale(tab, resultat_intermediaire, resultat_finale,4)){
        affiche_table_de_jeu(tab);
        printf("\nLe joueur %d a aligne diagonalement 4 pieces, il remporte la victoire!!!\n",*nombre_de_coup%2+1 );
        procedure_de_fermeture_du_jeu(resultat_intermediaire,resultat_finale);
    }
    
    else if(*nombre_de_coup <16){
        printf("\nNous avons pas trouve d'alignement, c'est au joueur %d de jouer\n", *nombre_de_coup%2+1);           
    }
    else if(*nombre_de_coup ==16){
        affiche_table_de_jeu(tab);
        printf("\nToutes pieces ont ete joue, nous avons un match nul\n");
        procedure_de_fermeture_du_jeu(resultat_intermediaire,resultat_finale);
    }
    else
        printf("erreur fermeture \n");
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
            //boucle de confirmation a faire, 
            verrou_etat = 0;
        }
    }

    placer_piece(couleur, taille, type, forme,tab, numero_case);

}

/*===============partie jeu===========*/
void lanceur_de_jeu(struct ttableau* tab){
    int * resultat_intermediaire= malloc(17 * sizeof(int));//case occupe 
    int * resultat_finale= malloc(5 * sizeof(int));
    int nombre_de_coup = 0;
    printf("Bienvenue dans notre jeu d'aligne 4\nLe but du jeu est d'aligner 4 pieces de meme characteristique\nsur une même ligne,colonne ou diagonale\nQuelle mode de jeu voulez vous choisir?\n0 ==> 1 Vs 1\n1 ==> 1 Vs Random\n2 ==> 1 Vs AI Lv1\n");
    int choix_mode =boucle_de_saisie(0,2);
    int verrou_etat = 1;
    if (choix_mode == 0){
        printf("Vous avez choisi le mode 1 vs 1\nLa partie va commencer\n");
        while(verrou_etat){   
            cases_occupe_de_la_table(tab,resultat_intermediaire);
            affiche_table_de_jeu(tab);
            saisie_piece(tab,resultat_intermediaire);
            printf("Le Joueur %d a joue le coup numero %d\n",nombre_de_coup %2+1,nombre_de_coup+1);
            nombre_de_coup++;
            check_finale_aligne4(tab,resultat_intermediaire,resultat_finale,&nombre_de_coup);
        }
    
}}


/*===========boucle joueur contre AI random=======*/
int main(int argc, char const *argv[]){
    initialisation_table(&table);
    //printf("%d\n",table.cases[12].couleur );
    //game_1vsAI_random(&table);
    //saisie_piece(&table,&a);
    //saisie_piece(&table,&a);
    //affiche_table_de_jeu(&table);
    lanceur_de_jeu(&table);
    return 0;
//excetion saisie char;                    1n
}