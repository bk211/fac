#include <stdio.h>

void overflow_char() {
    int  i = 0;
    while (i < i+1 ) {
        i++;
    }
    printf("plus grand char positif : %d\n", i);
    printf("plus grand char négatif : %d\n", i+1);
}


int main(int argc, char* argv[]) {

    overflow_char();

    return 0;
}
