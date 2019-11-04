#include <vector>
#include <iostream>

#include <math.h>
#define NB_MAX = 1000
using namespace std;

#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<bool> vec;
bool test_prime(unsigned long long int nb){
    if (nb == 2 || nb == 3){
        return true;
    }
    if (nb & 1) {// si nb est impair

        if (!(nb % 3))// si nb est divisible par 3
            return false;

        unsigned long long int sq = sqrt(nb);
//        cout << sq << '\n';

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
        cout <<"testing i = " <<i << '\n';
        if (!vec[i]){
            cout << "pass for i = " <<i<< '\n';
            continue;
        }
        if( i % nb == 0){
            cout << "set false for i = "<<i << '\n';
            vec[i] = false;
        }
    }
}

void erasto(vector<bool> &vec, unsigned long long max){

    for (auto i = 2; i < max; i++) {
        cout<<i;
        cout << "doing for ="<<i << '\n';
        if(vec[i]){

            set_false(i,max);
        }
    }
}

void write_file(vector<bool> vec, unsigned long long int begin, unsigned long long int end){
    ofstream f;
    string filename;
    filename =  "Resultat_17812776_" + to_string(begin)+"_"+to_string(end);

    f.open(filename);
    for (unsigned long long int i = begin; i < end; i++) {
        //f << vec[i]<<'\n';
        if(vec[i])
            f << i << '\n';
    }
    f.close();
}

int main(int argc, char const *argv[]) {
    auto start = steady_clock::now();
    if( argc == 3){
    unsigned long long int max;
    int nb_thread;
    istringstream s1(argv[1]);
    s1 >> max;
    istringstream s2(argv[2]);
    s2 >> nb_thread;
//    cout << vec.max_size() << '\n';
    vec.assign(max, true);
//    cout <<"current_vec capacity :"<< vec.capacity() << '\n';
    cout << "max:"<< max;
    vec[0] = false;
    vec[1] = false;


    erasto(vec,max);

    }
    else{
    cout << "Usage:./executable N X" << '\n';
    return 0;
    }

    write_file(vec,2, vec.size());
    for (auto v:vec){
        cout<< v<<" ,";
    }

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Time used:" << duration<double, milli> (diff).count()<<"ms"<< '\n';
    return 0;
}
