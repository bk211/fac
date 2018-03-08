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

    int resultat;
    char* repr = "00001111000001110000001100000001";
    char* repr2= "11111111111111111111111100101101";
    char* repr3=  "1100011111110110100001001000001";
    char* repr4= "10000000000000000000000000000001";
    float cacahuet;
    char* repr5= "010100001001101110000000000000000";
    char* infinity_pos="01111111100000000000000000000000";
    char* infinity_nega="11111111100000000000000000000000";
    char* nan= "01111111111111111111111111111111";
    char* zero= "0000000000000000000000000000000";
    char* denorma ="00000000001100101001011100011011";
    /*
    bin2mem("00001111000001110000001100000001", &resultat, sizeof(resultat));
    printf("la conversion de %s en entier donne %d\n", repr, resultat);

    bin2mem("11111111111111111111111100101101", &resultat, sizeof(resultat));
    printf("la conversion de %s en entier donne %d\n", repr2, resultat);

    bin2mem("1100011111110110100001001000001", &resultat, sizeof(resultat));
    printf("la conversion de %s en entier donne %d\n", repr3, resultat);

    bin2mem("10000000000000000000000000000001", &resultat, sizeof(resultat));
    printf("la conversion de %s en entier donne %d\n", repr4, resultat);
    
    */
    bin2mem("010100001001101110000000000000000", &resultat, sizeof(resultat));
    printf("la conversion de %s en entier donne %d\n", repr5, resultat);

    bin2mem("01111111100000000000000000000000", &resultat, sizeof(resultat));
    printf("la conversion de %s en entier donne %d\n", infinity_pos, resultat);

    bin2mem("11111111100000000000000000000000", &resultat, sizeof(resultat));
    printf("la conversion de %s en entier donne %d\n", infinity_nega, resultat);

    bin2mem("01111111111111111111111111111111", &resultat, sizeof(resultat));
    printf("la conversion de %s en entier donne %d\n", nan, resultat);

    bin2mem("0000000000000000000000000000000", &resultat, sizeof(resultat));
    printf("la conversion de %s en entier donne %d\n", zero, resultat);

    bin2mem("00000000001100101001011100011011", &resultat, sizeof(resultat));
    printf("la conversion de %s en entier donne %e\n", denorma, resultat);
    return 0;
}
