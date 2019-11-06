#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
void intervertir (float *pa, float *pb){
    *pa += *pb;
    *pb = *pa - *pb;
    *pa = *pa - *pb;
}

float somtf(float t[100], int nb){
    float s, *ptr;
    ptr = t;
    for (s = 0.0; nb--;)
        s+= *ptr++;

    return s;
}

typedef unsigned int Uint;
struct tabf{
    Uint nb;
    float *t;
};
typedef struct tabf tabf;

tabf remplir(Uint nb){
    float v, w, *ptr;
    int i;
    tabf t;

    t.t = (float * )malloc(nb * sizeof (float));
    assert(t.t);
    t.nb = nb;
    v = 1.0;
    w = 0.215;
    ptr = t.t;

    for ( i = 0; i < nb; i++) {
        *ptr++ = v;
        v += w;
        if (v > 2.0)
            w -= 0.3;
        if(v <1.0)
            w+= 0.3;
    }

    return t;
}
void affiche(tabf v){
    for (size_t i = 0; i < v.nb; i++) {
        printf("%f, ", *(v.t+i));
    }
    printf("\n");
}

float somme_vec(tabf v){
    return somtf(v.t, v.nb);
}

float moyenne_vec(tabf v){
    return somme_vec(v)/ v.nb;
}

float plus_gd(tabf v){
    float max = 0.0;
    for (int i = 0; i < v.nb; i++) {
        if (*(v.t+i) > max){
            max = *(v.t+i);
        }
    }
    return max;
}

float second_plus_gd(tabf v){
    float max = 0.0;
    float sec = 0.0;
    for (int i = 0; i < v.nb; i++) {
        if (*(v.t+i) > max){
            sec = max;
            max = *(v.t+i);
        }else if(*(v.t+i)>sec){
            sec = *(v.t+i);
        }
    }
    return sec;
}



int main(int argc, char const *argv[]) {
    tabf vec = remplir(10);
    affiche(vec);
    printf("%f\n",somme_vec(vec) );//1.67499
    printf("%f\n",moyenne_vec(vec) );//1.667500 la magie des calcules avec flotants
    printf("%f\n",plus_gd(vec) );
    printf("%f\n",second_plus_gd(vec) );
    return 0;
}
