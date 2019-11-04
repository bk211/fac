#include "count_primes.hpp"

//test si un nombre est premier
//remarque, retourne false pour 2 et 3;
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


//Ecrit dans un fichier le contenue du vecteur
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

    //ajoute 2 et 3 car test_prime ne le fait pas
    if (begin < 5 ){
        vec.push_back(2);
        vec.push_back(3);
    }

    for ( nb = begin; nb < end; nb++) {
        if(test_prime(nb)){
            vec.push_back(nb);
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
    //divise le max en morceau et les repartit entre les thread,
    //le premier thread prends plus de nombre, d'ou nb_thread+1
    unsigned long long int slice_size = max / (nb_thread+1);
    unsigned long long int begin = max - slice_size, end = max;

    for (int i = 0; i < nb_thread-1; i++) {
        th_vec.push_back(thread (count_primes, begin, end));
        begin -= slice_size;
        end -= slice_size;
    }
    th_vec.push_back(thread (count_primes, 0, end));

    for ( auto& th : th_vec ) {
        th.join();
    }

    auto t_end = chrono::steady_clock::now();
    auto t_diff = t_end - t_start;
    cout << "Time used:" << duration<double, milli> (t_diff).count()<<"ms"<< '\n';
    return 0;
}
