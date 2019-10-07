#include <stdio.h>

typedef struct foo_t foo_t;
struct foo_t{
    unsigned long long int quotient, reste;
};

foo_t my_div(int a, int b){
    foo_t resultat;
    resultat.quotient = a / b;
    resultat.reste = a % b;
    return resultat;
}

void afficher(foo_t boo){
    printf("quotient = %lld\n", boo.quotient );
    printf("reste = %lld\n", boo.reste );

}

int main(int argc, char const *argv[]) {
    int x = -12, y = 5;
    printf("resultat attendu: %d, %d\n", x/y, x%y);
    foo_t bar;
    bar = my_div(x,y);
    afficher(bar);
    return 0;
}
