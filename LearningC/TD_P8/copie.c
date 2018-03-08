#include <stdio.h>

int main(int argc, const char* argv[]) {
    FILE *original, *copie;
    int car;
    if(argc != 3)
        return 1;
    original = fopen(argv[1], "r");
    copie = fopen(argv[2], "w");
    for(car = fgetc(original); car != EOF; car = fgetc(original)) {
        fprintf(copie, "%c", car);
    }
    return 0;
}
