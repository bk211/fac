#include "bintree.h"

int comparer(const void *x, const void *y){
	float *a = (float*) x;
	float *b = (float*)y;
	return *a-*b; 
}
void imprimer(const void *a){
	printf("%f\n", *(float*)a );

 }

typedef struct arbre arbre;
struct  arbre
{
	int a;
	int b;
};
void imprimer2(const void *a){
	arbre * temp = (arbre*)a;
	printf("%d\n",temp->a );
	printf("%d\n",temp->b );
}

void imprimer3(const void *a){
	char * temp = (char*)a;
	printf("%s\n",temp );
}
int comparer2(const void *x, const void *y){
	arbre *a = (arbre*) x;
	arbre *b = (arbre*)y;
	return a->a - b->a; 
}
int main(int argc, char const *argv[])
{
	float tab[] = {1.2, 2.2,622, 0,3.3, 4.4,5.5};

	arbre * arbre1 = malloc(sizeof(arbre*));
	arbre1->a = 5;
	arbre1->b = 10;
	arbre * arbre2 = malloc(sizeof(arbre*));
	arbre2->a = 10;
	arbre2->b = 10;
	node_t * pt2 = NULL;
	bt_add_value(&pt2,arbre1,sizeof(arbre*),comparer2);
	bt_add_value(&pt2,arbre2,sizeof(arbre*),comparer2);
	
	bt_print(pt2,imprimer2);

	
	node_t * pt = NULL;
	//assert(pt);

	//float a =5.2555;
	//void * b = &a;
	//a1.a = 22;
	//a1.b = 33 ;
	int i ;
	for (i = 0; i < 7; ++i)
	{
		bt_add_value(&pt,tab+i,sizeof(float*),comparer);
		
	}
//	assert(pt != NULL);
//	assert(pt);
//	bt_add_value(&pt,tab+3,sizeof(float*),comparer);
	bt_print(pt,imprimer);
	bt_free(&pt);
	//assert(pt);

	bt_print(pt,imprimer);

	char msg[] = "12345akdwaoodk6789123456789";
	node_t * pt3=NULL;
	//char * temp = msg;
	//printf("%s\n",temp );
	//printf("%s\n",msg );
	bt_add_value(&pt3,(void*)msg,sizeof(msg),comparer);
	assert(pt3);

	bt_print(pt3,imprimer3);
	
	return 0;
}


/*
Sortie donnée : 
Sortie attendue : 
       (1.40580 17.35112) (3.91916 41.29219) (3.92470 37.86116) (4.07172 40.47247) (4.91610 31.66926) (5.02025 21.03519) (9.13801 20.07958) (11.13101 3.60022) (12.32738 14.90428) (12.69870 10.94369) (13.11764 16.04711) (13.66758 30.57719) (13.90483 30.37178) (14.68558 33.84556) (16.63785 36.07447) (17.76443 14.04554) (18.04440 40.01182) (18.24602 5.82071) (19.18652 14.72965) (19.94041 34.80912) (20.06289 8.93942) (20.41849 46.22673) (21.04967 2.40278) (24.71199 37.28096) (25.73572 49.38330) (26.16384 30.75598) (26.93646 15.31807) (27.69079 17.73930) (28.33363 23.76106) (29.06449 36.67615) (29.61405 5.67369) (30.50798 27.38428) (33.78801 41.80224) (34.81009 9.10289) (35.26948 7.53496) (35.37639 0.64004) (36.45535 28.71915) (36.48717 21.72570) (38.17480 3.14083) (39.06667 10.33966) (39.69539 32.74587) (44.41731 43.09090) (44.78924 14.29598) (44.84139 4.96541) (45.17043 12.79902) (45.67075 27.36715) (46.00114 48.16298) (46.07028 7.99642) (49.10510 48.25101) (49.98552 17.66011)
FIN DU TEST
Echec à l'étape 13 : Différence entre sortie donnée et sortie attendu


L'étape 1 passée : Le fichier bintree-1.0.0.tgz a été enregistré sur le serveur.
L'étape 2 passée : dossier destination créé
L'étape 3 passée : décompression de l'archive
L'étape 4 passée : vérification qu'aucun binaire n'est présent dans l'archive
L'étape 5 passée : structuration mono-répertoire de l'archive vérifiée
L'étape 6 passée : bintree.c/bintree.h sont présents
L'étape 7 passée : récupération du NOM réussie : CHAOLEI
L'étape 8 passée : récupération du NUMERO réussie : 17812776
L'étape 9 passée : récupération de l'EMAIL réussie : CHAOLEICAI@GMAIL.COM
L'étape 10 passée : compilation faite
L'étape 11 passée : l'exécutable bintree a bien été généré
L'étape 12 passée : l'exécutable de comparaison bintree a bien été généré
DEBUT DU TEST
--------------- Pour le paramètre : 3153 ---------------
Sortie donnée : 
Sortie attendue : 
       (0.69843 31.77116) (1.98871 18.23808) (6.31277 10.22368) (7.93810 49.79250) (8.20937 39.38438) (8.66000 32.33961) (8.67707 28.55751) (9.07723 22.28325) (9.42182 43.32997) (10.02363 47.40508) (10.21254 26.26448) (10.85293 0.64292) (11.39554 39.00520) (11.47671 27.64117) (11.56861 30.94167) (16.35915 48.93324) (16.41196 48.11966) (16.72272 35.92612) (17.42863 20.51198) (18.52326 43.23863) (18.53388 26.99643) (19.12992 49.31722) (19.18182 11.76314) (20.05048 41.28775) (20.37563 49.30326) (22.69601 45.51670) (24.40151 25.08903) (24.88152 35.33717) (26.60724 5.18173) (26.67717 15.21017) (27.33427 36.77854) (29.81104 6.77724) (29.96255 25.79995) (31.54664 13.41719) (34.41840 16.82694) (36.69144 4.01144) (37.86485 13.13562) (38.30845 49.30915) (38.68798 9.36792) (39.34861 49.53850) (40.80866 11.60241) (41.10785 29.79745) (41.11543 30.10249) (41.12350 30.75044) (42.63322 41.80628) (42.70482 32.23892) (46.77646 17.78948) (47.54978 11.57296) (48.06127 46.28621) (48.61072 36.76271)
FIN DU TEST
Echec à l'étape 13 : Différence entre sortie donnée et sortie attendu
*/