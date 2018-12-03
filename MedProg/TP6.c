/*Revenir à Révision - exos...
Langages de votre choix (vus en cours) :

1. Créer un programme qui dit si un nombre est premier ou non.

2. Créer un programme qui crée un tableau d'entiers et calcule leurs somme.

3. Créer un programme qui donne la factorielle (avec récursivité et avec itérations)*/


#include <stdio.h>


long long factorielle_reccursif_annexe(long long v,long long resultat){
    if(v == 1){

        if(resultat <= 0){
            printf("ERREUR stackoverflow!!!\n");
            return -2;
        }
        return resultat;
    }
    return factorielle_reccursif_annexe(v-1,resultat*v);
}

long long factorielle_reccursif(long long v){
    if(v <= 0)
        return -1;
    return factorielle_reccursif_annexe(v,1);
}

long long factorielle_iteratif(long long v){
    if(v <= 0)
        return -1;
    long long resultat = 1;
    while(v){
        resultat *= v--;
    }
    if(resultat <=0){
        printf("ERREUR stackoverflow!!! \n");
        return -2;
    }
    return resultat;
}


int main(int argc, char const *argv[])
{
    long long a =26;
    printf("%lli\n",factorielle_reccursif(a) );
    printf("%lli\n",factorielle_iteratif(a) );

    return 0;
}