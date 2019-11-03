#include <vector>
#include <iostream>

#include <math.h>
#define NB_MAX = 1000
using namespace std;
#include <thread>
#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool test_prime(unsigned long long int nb){
    if (nb & 1) {// si nb est impair

        if (!(nb % 3))// si nb est divisible par 3
            return false;

        unsigned long long int sq = sqrt(nb);// calcule la racine du nombre
//        cout << sq << '\n';

        for (unsigned long long int i = 5; i <= sq ; i += 6) {
        // verifie si le nombre peut etre diviser par les nombre allant de 5 a sa racine
        //
            if ( (nb % i) ==0 || (nb % (i+2)) == 0 )
                return false;
        }
        return true;
    }
    return false;

}

void write_file(vector<unsigned long long int> vec, unsigned long long int begin, unsigned long long int end){
    ofstream f;
    string filename;
    filename =  "Resultat_17812776_" + to_string(begin)+"_"+to_string(end);

    f.open(filename);
    for (auto nb : vec) {
        f << nb << '\n';
    }
    f.close();
}

void count_primes(unsigned long long int begin, unsigned long long int end){
    unsigned long long int nb, i;
    vector<unsigned long long int > vec;

    if (begin < 5 ){
        vec.push_back(2);
        vec.push_back(3);
    }

    for ( nb = begin; nb < end; nb++) {
        if(test_prime(nb)){
            vec.push_back(nb);
    //        cout<<nb<<'\n';
        }
    }

    write_file(vec, begin, end);
}

int main(int argc, char const *argv[]) {

    if( argc != 3){
        cout << "Usage:./executable N X" << '\n';
        return 0;
    }

    auto t_start = steady_clock::now();
    long max;
    int nb_thread;
    istringstream s1(argv[1]);
    s1 >> max;
    istringstream s2(argv[2]);
    s2 >> nb_thread;

    vector<thread> th_vec;
    unsigned long long int slice_size = max / nb_thread;
    unsigned long long int begin = 0, end = slice_size;
    for (int i = 0; i < nb_thread; i++) {
        th_vec.push_back(thread (count_primes, begin, end));
        begin += slice_size;
        end += slice_size;
    }
    for ( auto& th : th_vec ) {
        th.join();
    }

    auto t_end = chrono::steady_clock::now();
    auto t_diff = t_end - t_start;
    cout << "Time used:" << duration<double, milli> (t_diff).count()<<"ms"<< '\n';
    return 0;
}
