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
    if(!m ||n == m  )
        return 1;

    printf("m = %d\n",m );
    if(m > n/2)
        m = (m & 1)? m/2 :m/2+1 ;
    printf("m = %d\n",m );



    int *tab = malloc( (m+1) * sizeof(int));
    tab[0] = 1;
    tab[1] = 1;
    int i,j;
    int tmp,tmp2;
    for (i = 1; i < n; i++) {
        tmp = 1;
        for(j = 1; j <= i; j++){
            tmp2 = tab[j];
            tab[j] = tmp + tab[j];
            tmp = tmp2;
        }
    }
    int resultat = tab[m];
    free(tab);
    return resultat;
}

int tri_rec(int n, int m){
    if(!m ||n == m  )
        return 1;
    return tri_rec(n-1, m-1) + tri_rec(n-1, m);
}


/* 0 1 2 3
0  1
1  1 1
2  1 2 1
3  1 3 3 1
4  1 4 6 4 1
5  1 5 10 10 5 1
*/
