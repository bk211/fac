#include "func.h"


int fib_iter(int n ){
    int a = 1, b =1;
    while (--n){
        a += b;
        b = a - b;
    }
    return a;
}

int fib_rec(int n){
    if(n < 2)
        return 1;
    return fib_rec(n-1) + fib_rec(n-2);
}

int fib_rec_ter(int n, int a, int b){
    if(n < 2)
        return a;
    return fib_rec_ter(--n,a+b, a);
}

int fib_binet(int n){
    double phi1 = (1 + sqrt(5))/ 2;
    double phi2 = (1 - sqrt(5))/ 2;
    return (int) (1.0/sqrt(5.0) * (pow(phi1, n) - pow(phi2, n) ) + 0.5);
}

int tri_iter(int n, int m){
    if(n <2 || m == 1||n == m  )
        return 1;
    int* tab = malloc(m * sizeof(int));
    tab[0] = 1;
    while (--n) {

    }

    return tab[m];
}
