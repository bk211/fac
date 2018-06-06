/* Auteur: CAI Chaolei L1 informatique Y Paris8 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

struct pieces{
    int couleur;
    int taille;
    int type;
    int forme;
};

struct ttableau{
    struct pieces cases[16];
    int etat[16];
};



void effacer_piece_du_tableau(struct ttableau* tab,int numero_case){
    tab->etat[numero_case]=0;
    tab->cases[numero_case].couleur =-1;
    tab->cases[numero_case].taille =-1;
    tab->cases[numero_case].type =-1;
    tab->cases[numero_case].forme =-1;
}

void initialisation_table(struct ttableau *tab){
    int i;
    for (i = 0; i < 16; ++i)
        effacer_piece_du_tableau(tab,i);
}

void placer_piece(int couleur, int taille, int type, int forme, struct ttableau* t, int num){
    t->etat[num] = 1;
    t->cases[num].couleur = couleur;
    t->cases[num].taille = taille;
    t->cases[num].type = type;
    t->cases[num].forme = forme;
}

int check_case_occupe(struct ttableau *tab, int num){
    if(tab->etat[num]==1)
        return 1;
    return 0;
}

/*=======================partie vérification====================*/
void cases_occupe_de_la_table(struct ttableau* tab, int resultat_intermediaire[]){
    resultat_intermediaire[0] = 0;
    int i,k=0;
    for (i = 0; i < 16; ++i){
        if(check_case_occupe(tab,i)){
            resultat_intermediaire[k+1] = i;
            k++;
            resultat_intermediaire[0]=k;
        }    
    }
}


int test_membre_case_occupe(int resultat_intermediaire[],int elem){
    int i;
    for (i = 1; i <= resultat_intermediaire[0]; ++i){
        if(elem == resultat_intermediaire[i])
            return 1;
    }
    return 0;
}


int check_aligne_annexe(int resultat_intermediaire[],int tete, int indentation_du_pas, int nombrealigne){
    int i;
    int compteur = 0;
    int curseur = tete;
    for (i = 0; i < 4; i++){
        if(test_membre_case_occupe(resultat_intermediaire,curseur)) 
            compteur++;
        curseur += indentation_du_pas;
    }
    if(compteur == nombrealigne)
        return 1;
    return 0;
}

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

/*============================================================*/
void affiche_table_de_jeu(struct ttableau* tab){
    int i;
    printf("\n");

    for (i = 0; i < 20; ++i)
    {
        printf("=");
    }
    printf("\n");

    for (int j = 0; j < 16; ++j) 
    {   
        if(!(j % 4)){
            printf("\n");
        }

        if(tab->etat[j]){ 
            tab->cases[j].couleur? printf("B") :printf("N");
            tab->cases[j].taille? printf("P") :printf("G");
            tab->cases[j].type? printf("V") :printf("A");
            tab->cases[j].forme? printf("C") :printf("R");
            printf(" ");
        }
        else if(!tab->etat[j]){ 
            printf(".... ");
        }
    }

    printf("\n\n");
    for (i = 0; i < 20; ++i)
    {
        printf("=");
    }

    printf("\n");

}



void procedure_de_fermeture_du_jeu(int resultat_intermediaire[],int resultat_finale[]);

int conversion_nb_de_coup_jouer(int nombre_de_coup){
    if(nombre_de_coup % 2)
        return 2;
    return 1;
}

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




void check_finale_aligne4(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup){
    cases_occupe_de_la_table(tab,resultat_intermediaire);

    check_horizontale4(tab, resultat_intermediaire, resultat_finale,nombre_de_coup);
    check_verticale4(tab, resultat_intermediaire, resultat_finale,nombre_de_coup);
    check_diagonale4(tab, resultat_intermediaire, resultat_finale,nombre_de_coup);
    
    
    if(*nombre_de_coup <15){
        printf("\nNous n'avons pas trouve d'alignement, c'est au joueur %d de jouer\n\n", conversion_nb_de_coup_jouer(*nombre_de_coup+1));           
    }

    else if(*nombre_de_coup ==15){
        affiche_table_de_jeu(tab);
        printf("\nToutes pieces ont ete joue, nous avons un match nul\n\n");
        procedure_de_fermeture_du_jeu(resultat_intermediaire,resultat_finale);
    }

}


/*=====================================================*/
int boucle_de_saisie(int a, int b){
    int i;
    do{
        fflush(stdin);
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

int verifier_piece_utilise(int couleur, int taille, int type, int forme,struct ttableau* tab, int* resultat_intermediaire){
    int i;
    for (i = 1; i <= resultat_intermediaire[0]; ++i){
        if(comparer_characteristique(tab->cases[resultat_intermediaire[i]].couleur,couleur)
        && comparer_characteristique(tab->cases[resultat_intermediaire[i]].taille,taille)
        && comparer_characteristique(tab->cases[resultat_intermediaire[i]].type,type)
        &&comparer_characteristique(tab->cases[resultat_intermediaire[i]].forme,forme))
            return 1;
    }
    return 0;
};


int coin_flip(int a){
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

void saisie_piece(struct ttableau* tab,int resultat_intermediaire[]){
    int numero_case, couleur, taille, type, forme ;
    int verrou_etat=1;

    cases_occupe_de_la_table(tab, resultat_intermediaire);
    while(verrou_etat){
        
        do{
            printf("\ncase de jeu? ");
            numero_case = boucle_de_saisie(0,15);
        }while(check_case_occupe(tab,numero_case));

        printf("couleur? (0 pour Noire, 1 pour Blanche) ");
        couleur = boucle_de_saisie(0,1);

        printf("taille? (0 pour Grande, 1 pour Petite)  ");
        taille = boucle_de_saisie(0,1);

        printf("type? (0 pour Animal, 1 pour Vegetal)   ");
        type = boucle_de_saisie(0,1);

        printf("forme? (0 pour Ronde, 1 pour Carre)     ");
        forme = boucle_de_saisie(0,1);

        if(verifier_piece_utilise(couleur, taille, type, forme, tab, resultat_intermediaire))
            printf("piece deja utilise, merci de recommencer la saisie des characteristique\n");
        else{
            verrou_etat = confirmation_saisie(numero_case,couleur, taille, type, forme);
            
        }
    }

    placer_piece(couleur, taille, type, forme,tab, numero_case);

}

/*=======================================================================*/


int tirage(int max){
    rand();
    return (double)(rand()/(double)(RAND_MAX) * (max+1));
}

void saisie_piece_random(struct ttableau* tab,int resultat_intermediaire[]){
    int numero_case, couleur, taille, type, forme ;

    srand((unsigned)time(NULL));
        
    do{

        do{
        numero_case = tirage(15);
        }while(check_case_occupe(tab,numero_case));

        couleur = tirage(1);

        taille = tirage(1);

        type = tirage(1);

        forme = tirage(1);

    }while(verifier_piece_utilise(couleur, taille, type, forme, tab, resultat_intermediaire));

    

    placer_piece(couleur, taille, type, forme,tab, numero_case);
    
}

/*========================================================saisie_piece_random*/
int compter_nb_charac_piece_utilise(int couleur, int taille, int type, int forme,struct ttableau* tab, int* resultat_intermediaire){
    int i;
    int compteur = 0;
    for (i = 1; i <= resultat_intermediaire[0]; ++i){
        if(comparer_characteristique(tab->cases[resultat_intermediaire[i]].couleur,couleur)
        || comparer_characteristique(tab->cases[resultat_intermediaire[i]].taille,taille)
        || comparer_characteristique(tab->cases[resultat_intermediaire[i]].type,type)
        || comparer_characteristique(tab->cases[resultat_intermediaire[i]].forme,forme))
            compteur++;

    }
    return compteur;

}

int numero_case_vide(struct ttableau* tab, int resultat_finale[]){
    int i;
    int reponse;
    for (i = 0; i < 4; ++i){
        if(!tab->etat[ resultat_finale[1]+ i * resultat_finale[2]])
            reponse = resultat_finale[1]+ i * resultat_finale[2];
    }
    return reponse;
}



void generer_et_placer_piece_definie(struct ttableau* tab,int resultat_intermediaire[],int resultat_finale[],int numero_case){
    int compteur;
    int couleur, taille, type, forme ;
    int verrou_etat =1;
    while(verrou_etat){
        srand((unsigned)time(NULL));
        compteur = 1;

        couleur = tirage(1);
        if (compteur == resultat_finale[3])
            couleur = resultat_finale[4];

        compteur ++;
        
        taille = tirage(1);
        if (compteur == resultat_finale[3])
            taille = resultat_finale[4];

        compteur ++;

        type = tirage(1);
        if (compteur == resultat_finale[3])
            type = resultat_finale[4];

        compteur ++;

        forme = tirage(1);
        if (compteur == resultat_finale[3])
            forme = resultat_finale[4];
        

        if(!verifier_piece_utilise(couleur, taille, type, forme, tab, resultat_intermediaire))
            verrou_etat = 0;
    }

    placer_piece(couleur, taille, type, forme,tab, numero_case);
}

int check_nombre_caracteristique_utilise(struct ttableau *tab , int resultat_intermediaire[], int resultat_finale[]){
    int compteur = 1;
    if (compteur == resultat_finale[3] 
        &&compter_nb_charac_piece_utilise(resultat_finale[4], -2, -2, -2, tab, resultat_intermediaire) <8 )
        return 1;
    compteur++;

    if (compteur == resultat_finale[3] 
        && compter_nb_charac_piece_utilise(-2, resultat_finale[4], -2, -2, tab, resultat_intermediaire) <8)
        return 1;

    compteur++;
    if (compteur == resultat_finale[3] 
        &&compter_nb_charac_piece_utilise(-2,-2,resultat_finale[4], -2, tab, resultat_intermediaire) <8 )
        return 1;
    compteur++;
    if (compteur == resultat_finale[3] 
        &&compter_nb_charac_piece_utilise(-2, -2, -2,resultat_finale[4],tab, resultat_intermediaire) <8 )
        return 1;
    return 0;
    
}

int check_forme_AI(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int nombrealigne){
    int i;
    for (i = 0; i < 2; ++i){
        if(check_couleur(tab, resultat_finale, i, nombrealigne)
            &&check_nombre_caracteristique_utilise(tab , resultat_intermediaire, resultat_finale)){
            resultat_finale[3] = 1;
            resultat_finale[4] = i;
            return 1;
        }

        else if(check_taille(tab, resultat_finale, i, nombrealigne)
            &&check_nombre_caracteristique_utilise(tab , resultat_intermediaire, resultat_finale)){
            resultat_finale[3] = 2;
            resultat_finale[4] = i;
            return 1;      }

        else if(check_type(tab, resultat_finale, i, nombrealigne)
            &&check_nombre_caracteristique_utilise(tab , resultat_intermediaire, resultat_finale)){
            resultat_finale[3] = 3;
            resultat_finale[4] = i;
            return 1;
        }

        else if(check_forme(tab, resultat_finale, i, nombrealigne)
            &&check_nombre_caracteristique_utilise(tab , resultat_intermediaire, resultat_finale)){
            resultat_finale[3] = 4;
            resultat_finale[4] = i;
            return 1;
        }
    }
    return 0;
}


int check_horizontale_AI(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int nombrealigne){
    int i;
    for (i = 0; i <= 12; i+=4){
        if(check_aligne_annexe(resultat_intermediaire,i, 1, nombrealigne)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = 1;
            if(check_forme_AI(tab, resultat_intermediaire, resultat_finale,nombrealigne))
                return 1;
            
        }
    }
    return 0;
}

int check_verticale_AI(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int nombrealigne){
    int i;
    for (i = 0; i <= 3; i++){
        if(check_aligne_annexe(resultat_intermediaire,i, 4, nombrealigne)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = 4;
            if(check_forme_AI(tab, resultat_intermediaire, resultat_finale,nombrealigne))
               
                return 1;
            
        }
    }
    return 0;
}

int check_diagonale_AI(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int nombrealigne){
    int i;
    int pas = 5;
    for (i = 0; i <= 3; i+=3){
        if(check_aligne_annexe(resultat_intermediaire,i, pas, nombrealigne)){
            resultat_finale[0] = 1;
            resultat_finale[1] = i;
            resultat_finale[2] = pas;
            if(check_forme_AI(tab, resultat_intermediaire, resultat_finale,nombrealigne))
                return 1;
            
        }
        pas -= 2;
    }
    return 0;
}


void game_mode_joueur(struct ttableau* tab,int resultat_intermediaire[],int resultat_finale[],int * nombre_de_coup){
    cases_occupe_de_la_table(tab,resultat_intermediaire);
    saisie_piece(tab,resultat_intermediaire);
    affiche_table_de_jeu(tab);
    printf("\n>>Le Joueur %d a joue le coup numero %d\n",conversion_nb_de_coup_jouer(*nombre_de_coup),*nombre_de_coup+1);
    check_finale_aligne4(tab,resultat_intermediaire,resultat_finale,nombre_de_coup);
    (*nombre_de_coup)++;
        
}


void game_1vsAI_random(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup){
    cases_occupe_de_la_table(tab,resultat_intermediaire);
    saisie_piece_random(tab, resultat_intermediaire);
    affiche_table_de_jeu(tab);
    printf("\n>>Le Joueur %d a joue le coup numero %d\n",conversion_nb_de_coup_jouer(*nombre_de_coup),*nombre_de_coup+1);
    check_finale_aligne4(tab,resultat_intermediaire,resultat_finale,nombre_de_coup);
    (*nombre_de_coup)++;
}

int recherche_alignement(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[], int nombrealigne){
    if(check_horizontale_AI(tab,resultat_intermediaire,resultat_finale,nombrealigne)
    ||(check_verticale_AI(tab,resultat_intermediaire,resultat_finale,nombrealigne))
    ||(check_diagonale_AI(tab,resultat_intermediaire,resultat_finale,nombrealigne)))
        return 1;
    return 0;
}

void game_mode_AI_lv1(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup){
    cases_occupe_de_la_table(tab,resultat_intermediaire);

    if(recherche_alignement(tab,resultat_intermediaire,resultat_finale,3)){   
        int case_vide = numero_case_vide(tab, resultat_finale);
        generer_et_placer_piece_definie(tab, resultat_intermediaire, resultat_finale,case_vide);
    }
    else
        saisie_piece_random(tab, resultat_intermediaire);

    affiche_table_de_jeu(tab);
    printf("\\n>>Le Joueur %d a joue le coup numero %d\n",conversion_nb_de_coup_jouer(*nombre_de_coup),*nombre_de_coup+1);
    check_finale_aligne4(tab,resultat_intermediaire,resultat_finale,nombre_de_coup);
    (*nombre_de_coup)++;
}


int Deux_alignement_placement_AI(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int permissivite){
    int verrou_etat;
    int case_temporaire = numero_case_vide(tab, resultat_finale);
    resultat_finale[4]= coin_flip(resultat_finale[4]);
    for(;permissivite >0;permissivite--){
        generer_et_placer_piece_definie(tab, resultat_intermediaire, resultat_finale,case_temporaire);
        cases_occupe_de_la_table(tab,resultat_intermediaire);
        if(!recherche_alignement(tab,resultat_intermediaire,resultat_finale,3))
            break;
    }
    if (permissivite > 0)
        return 1;
    effacer_piece_du_tableau(tab,case_temporaire);
    cases_occupe_de_la_table(tab,resultat_intermediaire);
    return 0;

}



int recherche_2alignement_et_placement(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int permissivite){
    int * tableau_intermediaire= malloc(16 * sizeof(int));
    if(check_horizontale_AI(tab, resultat_intermediaire, resultat_finale,2) && Deux_alignement_placement_AI(tab,resultat_intermediaire,resultat_finale,permissivite) 
    ||(check_verticale_AI(tab, resultat_intermediaire, resultat_finale,2) && Deux_alignement_placement_AI(tab,resultat_intermediaire,resultat_finale,permissivite))
    ||(check_diagonale_AI(tab, resultat_intermediaire, resultat_finale,2) && Deux_alignement_placement_AI(tab,resultat_intermediaire,resultat_finale,permissivite)))
        return 1;
    return 0;
}

void game_mode_AI_lv2(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup){
    cases_occupe_de_la_table(tab,resultat_intermediaire);

    if(recherche_alignement(tab,resultat_intermediaire,resultat_finale,3)){
        int case_vide = numero_case_vide(tab, resultat_finale);
        generer_et_placer_piece_definie(tab, resultat_intermediaire, resultat_finale,case_vide);
    }    
    else if(!recherche_2alignement_et_placement(tab,resultat_intermediaire,resultat_finale,8))
        saisie_piece_random(tab, resultat_intermediaire);

    affiche_table_de_jeu(tab);
    printf("\n>>Le Joueur %d a joue le coup numero %d\n",conversion_nb_de_coup_jouer(*nombre_de_coup),*nombre_de_coup+1);
    check_finale_aligne4(tab,resultat_intermediaire,resultat_finale,nombre_de_coup);
    (*nombre_de_coup)++;
}

void saisie_piece_antijeu(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[]){
    int numero_case, couleur, taille, type, forme ;
    int i;
    for (i = 32; i > 0; i--){
        srand((unsigned)time(NULL));

        do{
        numero_case = tirage(15);
        }while(check_case_occupe(tab,numero_case));

        couleur = tirage(1);

        taille = tirage(1);

        type = tirage(1);

        forme = tirage(1);

        if(!verifier_piece_utilise(couleur, taille, type, forme, tab, resultat_intermediaire)){
            placer_piece(couleur, taille, type, forme,tab, numero_case);
            if(recherche_alignement(tab,resultat_intermediaire,resultat_finale,3))
                effacer_piece_du_tableau(tab,numero_case);
            else
            break;
                
        } 
            
    }
    if (!i)
        saisie_piece_random(tab, resultat_intermediaire);
}

void game_mode_AI_lv3(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup){
    cases_occupe_de_la_table(tab,resultat_intermediaire);

    if(recherche_alignement(tab,resultat_intermediaire,resultat_finale,3)){
        int case_vide = numero_case_vide(tab, resultat_finale);
        generer_et_placer_piece_definie(tab, resultat_intermediaire, resultat_finale,case_vide);
    }    
    else if(!recherche_2alignement_et_placement(tab,resultat_intermediaire,resultat_finale,32))
        saisie_piece_antijeu(tab, resultat_intermediaire, resultat_finale);

    affiche_table_de_jeu(tab);
    printf("\n>>Le Joueur %d a joue le coup numero %d\n",conversion_nb_de_coup_jouer(*nombre_de_coup),*nombre_de_coup+1);
    check_finale_aligne4(tab,resultat_intermediaire,resultat_finale,nombre_de_coup);
    (*nombre_de_coup)++;
}


void lanceur_de_jeu(){
    struct ttableau tab;
    initialisation_table(&tab);
    int * resultat_intermediaire= malloc(17 * sizeof(int));
    int * resultat_finale= malloc(5 * sizeof(int));
    int nombre_de_coup = 0;
    printf("Bienvenue dans notre jeu d'aligne 4\nLe but du jeu est d'aligner 4 pieces de meme characteristique\nsur une meme ligne,colonne ou diagonale\n");
    printf("Quelle mode de jeu voulez vous choisir?\n0 ==> 1 Vs 1\n");
    printf("1 ==> 1 Vs Random\n2 ==> 1 Vs AI Lv1\n3 ==> 1 Vs AI Lv2\n");
    printf("4 ==> 1 Vs AI Lv3\n5 ==> AI Vs AI \n");
    int choix_mode = boucle_de_saisie(0,5);

    if (choix_mode == 0){
        printf("Vous avez choisi le mode 1 vs 1\nLa partie va commencer\n");
        affiche_table_de_jeu(&tab);
        while(1){   
            game_mode_joueur(&tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
        }   
    }
    if (choix_mode == 1){
        printf("Vous avez choisi le mode 1 vs random\nLa partie va commencer\n");
        affiche_table_de_jeu(&tab);
        while(1){
            game_mode_joueur(&tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
            game_1vsAI_random(&tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
        
        }
    }
    if (choix_mode == 2){
        printf("Vous avez choisi le mode 1 vs AI Lv1\nLa partie va commencer\n");
        affiche_table_de_jeu(&tab);
        while(1){
                game_mode_joueur(&tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
                game_mode_AI_lv1(&tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
        }
    }
    
    if (choix_mode == 3){
        printf("Vous avez choisi le mode 1 vs AI Lv2\nLa partie va commencer\n");
        affiche_table_de_jeu(&tab);
        while(1){
                game_mode_joueur(&tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
                game_mode_AI_lv2(&tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
        }
    }
    if (choix_mode == 4){
        printf("Vous avez choisi le mode 1 vs AI Lv3\nLa partie va commencer\n");
        affiche_table_de_jeu(&tab);
        while(1){
                game_mode_joueur(&tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
                game_mode_AI_lv3(&tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
        }
    }
    if (choix_mode == 5){
        printf("Vous avez choisi le mode AI vs AI \nLa partie va commencer\n");
        affiche_table_de_jeu(&tab);
        while(1){
                game_mode_AI_lv2(&tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
                game_mode_AI_lv3(&tab,resultat_intermediaire, resultat_finale, &nombre_de_coup);
        }
    }



}  



int main(int argc, char const *argv[]){
    lanceur_de_jeu();
    exit(EXIT_FAILURE);
    return 0;
}

    