#include <stdio.h>


void bin2mem(char bin[], void * p, unsigned int size){
    int i, j;
    char mask;
    for (i = 0; i < size; i++) {
        for (j = 0; j < 8; j++) {
            mask = 1 << (7 - j);
            if (bin[i*8 + j] == '1') {
                *(char*)(p + size-1 - i) |= mask; // 1
            } else {
                *(char*)(p + size-1 - i) &= ~mask; // 0
            }
        }
    }
}


int main(int argc, char* argv[]) {

    char c = 'A';

    printf("(char) c = %c\n", c);
    printf("(int) c = %d\n", c);
    printf("c (hexadecimal) = %x\n", c);

    char tab[4];
    int i;
    float f;

    bin2mem("00000000010000110100001001000001", &tab, sizeof(tab));
    bin2mem("00000000010000110100001001000001", &i, sizeof(i));
    bin2mem("00000000010000110100001001000001", &f, sizeof(f));

    printf("(char*) tab = %s\n", tab);
    printf("(int) i = %d,  i (hexadecimal) = %x \n",i,i);
    printf("(float) f = %f, f (notation scientifique) = %.18e\n", f, f);

    return 0;
}