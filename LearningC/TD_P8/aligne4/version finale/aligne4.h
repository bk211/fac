/* Auteur: CAI Chaolei L1 informatique Y  */
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

void effacer_piece_du_tableau(struct ttableau* tab,int numero_case);
void initialisation_table(struct ttableau *tab);
void placer_piece(int couleur, int taille, int type, int forme, struct ttableau* t, int num);
int check_case_occupe(struct ttableau *tab, int num);
void cases_occupe_de_la_table(struct ttableau* tab, int resultat_intermediaire[]);
int test_membre_case_occupe(int resultat_intermediaire[],int elem);
int check_aligne_annexe(int resultat_intermediaire[],int tete, int indentation_du_pas, int nombrealigne);
int check_couleur(struct ttableau *tab, int resultat_finale[], int sous_type, int nombrealigne);
int check_taille(struct ttableau *tab, int resultat_finale[], int sous_type, int nombrealigne);
int check_type(struct ttableau *tab, int resultat_finale[], int sous_type, int nombrealigne);
int check_forme(struct ttableau *tab, int resultat_finale[], int sous_type, int nombrealigne);
void check_intermediaire_forme(struct ttableau *tab, int resultat_finale[],int etat, int nombrealigne);
void check_forme_finale(struct ttableau *tab, int resultat_finale[], int nombrealigne);
int validation(int resultat_finale[]);
void affiche_table_de_jeu(struct ttableau* tab);
int conversion_nb_de_coup_jouer(int nombre_de_coup);
void check_horizontale4(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup);
void check_verticale4(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup);
void check_diagonale4(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup);
void procedure_de_fermeture_du_jeu(int resultat_intermediaire[],int resultat_finale[]);
void check_finale_aligne4(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup);
int boucle_de_saisie(int a, int b);
int comparer_characteristique(int a, int b);
int verifier_piece_utilise(int couleur, int taille, int type, int forme,struct ttableau* tab, int* resultat_intermediaire);
int coin_flip(int a);
int confirmation_saisie(int numero_case,int couleur,int taille,int type,int forme);
void saisie_piece(struct ttableau* tab,int resultat_intermediaire[]);
int tirage(int max);
void saisie_piece_random(struct ttableau* tab,int resultat_intermediaire[]);
int compter_nb_charac_piece_utilise(int couleur, int taille, int type, int forme,struct ttableau* tab, int* resultat_intermediaire);
int numero_case_vide(struct ttableau* tab, int resultat_finale[]);
void generer_et_placer_piece_definie(struct ttableau* tab,int resultat_intermediaire[],int resultat_finale[],int numero_case);
int check_nombre_caracteristique_utilise(struct ttableau *tab , int resultat_intermediaire[], int resultat_finale[]);
int check_forme_AI(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int nombrealigne);
int check_horizontale_AI(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int nombrealigne);
int check_verticale_AI(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int nombrealigne);
int check_diagonale_AI(struct ttableau *tab, int resultat_intermediaire[], int resultat_finale[],int nombrealigne);
void game_mode_joueur(struct ttableau* tab,int resultat_intermediaire[],int resultat_finale[],int * nombre_de_coup);
void game_1vsAI_random(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup);
int recherche_alignement(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[], int nombrealigne);
void game_mode_AI_lv1(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup);
int Deux_alignement_placement_AI(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int permissivite);
int recherche_2alignement_et_placement(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int permissivite);
void game_mode_AI_lv2(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup);
void saisie_piece_antijeu(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[]);
void game_mode_AI_lv3(struct ttableau* tab,int resultat_intermediaire[], int resultat_finale[],int* nombre_de_coup);
void lanceur_de_jeu();
