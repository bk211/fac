#include "direct.h"

unsigned long long int fibiter(int n){
    if(n < 2)
        return 1;
    int i;
    unsigned long long int j = 1,k =1;
    for (i = 0; i < n; i++) {
        k += j;
        j = k - j;
    }
    return j;

}
