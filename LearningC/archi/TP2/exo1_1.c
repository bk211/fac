#include <stdio.h>

void overflow_char() {
    int i = 0;
    while (i < (i+1)) {
        i++;
        printf("%d\n",i  );
    }
    printf("plus grand char positif : %d\n", i);
    printf("plus grand char négatif : %d\n", (i+1));
}


int main(int argc, char* argv[]) {

    printf("taille d'un int :%hi \n",3276 );

    return 0;
}