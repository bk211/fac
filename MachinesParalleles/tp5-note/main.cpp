#include <vector>
#include <iostream>

#include <math.h>
#define NB_MAX = 1000
using namespace std;

#include <sstream>

using namespace std;

vector<bool> vec;
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

void set_false(unsigned long long int nb, unsigned long long int max){//
    unsigned long long int i;
    bool tmp;

    for ( i = nb+1; i < max; i++) {
//        cout <<"testing i = " <<i << '\n';
        tmp = vec[i];
        if (!tmp){
//            cout << "pass for i = " <<i<< '\n';
            continue;
        }
        if( i % nb == 0){
//            cout << "set false for i = "<<i << '\n';
            vec[i] = false;
        }
    }
}


int main(int argc, char const *argv[]) {

    if( argc == 3){
    long max;
    int nb_thread=3;
    istringstream ss(argv[1]);
    ss >> max;
    //cout << max << '\n';


    //cout << vec.max_size() << '\n';
    vec.assign(1000000000, true);
    cout << vec.capacity() << '\n';
    vec[0] = false;
    vec[1] = false;

    set_false(2,max);
    int* task_tab = new int[nb_thread];


    }
    else{
    cout << "Usage:./executable N X" << '\n';
    }

    //TODO  export output to file
    return 0;
}
