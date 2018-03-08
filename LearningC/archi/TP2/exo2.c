#include <stdio.h>

void mem2bin(void * p, unsigned int size) {
    char mask;
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 7; j >= 0; j--) {
            mask = 1 << j;
            if (*(char*)(p + i) & mask) printf("1");
            else  printf("0");
        }
        printf(" ");
    }
    printf("\n");
}

void mem2bin_Gauche(void * p, unsigned int size) {
    char mask;
    int i, j;
    for (i = size-1; i >=0; i--) {
        for (j = 7; j >= 0; j--) {
            mask = 1 << j;
            if (*(char*)(p + i) & mask) printf("1");
            else  printf("0");
        }
        printf(" ");
    }
    printf("\n");
}
int main(int argc, char* argv[]) {

    int mavariable = 252117761;
    float f = -211;
    mem2bin(&f, sizeof(f));
    mem2bin_Gauche(&f, sizeof(f));


    return 0;
}

