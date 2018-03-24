#include <stdio.h>

int main(int argc, const char* argv[]) {
    FILE* flux;
    int car;
    if(argc != 2)
        return 1;
    flux = fopen(argv[1], "r");
    for(car = fgetc(flux); car != EOF; car = fgetc(flux)) {
        printf("%c", car);
    }
    return 0;
}