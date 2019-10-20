#include "func.h"
int main(int argc, char const *argv[])
{
    int i,n = 100;
    int tps_init, tps_crt, dtps;
/*
    tps_init = (int) clock();
    for (i = 0; i < n; i++) {
        fib_iter(44);
    }
    printf("Temps pour %u avec %10s :\t", n, "fib_iter");
    tps_crt = (int) clock();
    dtps = tps_crt - tps_init;
    printf(" \t%d\n", dtps );

    printf("Temps pour %u avec %10s :\t", n, "fib_rec");
    tps_init = (int) clock();
    for (i = 0; i < n; i++) {
        //
        //printf(">>i =%d\n",i );
        //fib_rec(44);
    }
    tps_crt = (int) clock();
    dtps = tps_crt - tps_init;
    printf(" \t%d\n", dtps );

    printf("Temps pour %u avec %10s :\t", n, "fib_rec_ter");
    tps_init = (int) clock();
    for (i = 0; i < n; i++) {
        fib_rec_ter(44,1,1);
    }
    tps_crt = (int) clock();
    dtps = tps_crt - tps_init;
    printf(" \t%d\n", dtps );

    printf("Temps pour %u avec %10s :\t", n, "fib_binet");
    tps_init = (int) clock();
    for (i = 0; i < n; i++) {
        fib_binet(44);
    }
    tps_crt = (int) clock();
    dtps = tps_crt - tps_init;
    printf(" \t%d\n", dtps );

*/
    printf("Temps pour %u avec %10s :\t", n, "tri_iter");
    tps_init = (int) clock();
    printf("%d\n",tri_iter(1,1));
    tps_crt = (int) clock();
    dtps = tps_crt - tps_init;
    printf(" \t%d\n", dtps );






















}
