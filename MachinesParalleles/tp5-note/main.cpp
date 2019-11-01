#include <vector>
#include <iostream>

#include <math.h>


#define NB_MAX = 1000
using namespace std;

bool test_prime(unsigned long long int nb){
    if (nb & 1) {// si nb est impair

        if (!(nb % 3))// si nb est divisible par 3
            return false;

        unsigned long long int sq = sqrt(nb);
        cout << sq << '\n';

        for (unsigned long long int i = 5; i <= sq ; i += 6) {
            if ( (nb % i) ==0 || (nb % (i+2)) == 0 )
                return false;
        }
        return true;
    }
    return false;

}

void set_false(unsigned long long int nb){//
    unsigned long long int i;
    for ( i = nb; i < NB_MAX; i++) {
        
    }
}


vector<bool> vec;
int main(int argc, char const *argv[]) {

    if( argc == 3){
    //cout << vec.max_size() << '\n';
    vec.assign(1000000000, true);
    cout << vec.capacity() << '\n';
    vec[0] = false;
    vec[1] = false;

    cout << test_prime(100003559) << '\n';
    }
    else{
    cout << "Usage:./executable N X" << '\n';
    }

    //TODO  export output to file
    return 0;
}
