#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>
#include <mutex>
#include <stdlib.h>
#include <chrono>
#include <condition_variable>

#define SLEEP_TIME 2
#define MAX_POP_TIME 10
#define MAX_PRODUCT 10
#define NB_CUST 10

void producteur(std::vector<int> *v, int* index, int wave);
void consomateur(std::vector<int> *v,int* index, int n);
void consomateurs(std::vector<int> *v,int* index);
std::mutex mymutex;
std::condition_variable cond_var;
bool done = false;
bool notified = false;

void _sleep_for(){
    int t = rand() % SLEEP_TIME + 1; //sleep entre 1 et SLEEP_TIME
    std::cout << "Sleeping for " << t<< " secs\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(t));
}

int main(int argc, char const *argv[]) {
    srand (time(NULL));
    std::vector<int> panier;
    int index = 0;
    std::thread t1(producteur,&panier, &index, 2);
    //std::thread t2(consomateur,&panier, &index, 1);
    std::thread t2(consomateurs,&panier, &index);

    t1.join();
    t2.join();
    return 0;
}


void producteur(std::vector<int>* v, int *index, int wave){
    for (int i = 0; *index < MAX_PRODUCT ; i++) {
        _sleep_for();
        std::unique_lock<std::mutex> lock(mymutex);

        for (int j = 0; j < wave; j++) {
            v->push_back(i);
        }

        *index +=1;
        std::cout << "Prod: pushed <" << i<< "> au panier" <<", c'est la  "<< *index<<" eme vague \n";
        notified = true;
        cond_var.notify_all();
    }
    done = true;
    std::cout << "End of prod" << '\n';
}

void consomateur(std::vector<int>* v,int *index, int n){
    int x;
    int npop = 0;
    std::unique_lock<std::mutex> lock(mymutex);
    //std::cout << "lauched" << n <<'\n';
    while (!done) {
        while(!notified){
            cond_var.wait(lock);
        }

        if(!v->empty()){
            x = v->back();
            v->pop_back();
        //*index -=1;
        std::cout << "Cust "<< n<<" pop <"<< x << "> au panier\n";
        npop++;
        notified = false;
        }
        if (npop == MAX_POP_TIME) {
            std::cout << "MAX_POP_TIME reached" << '\n';
            break;
        }
    }
    notified = true;
    std::cout << "End of cust" << n << '\n';

}

void consomateurs(std::vector<int> *v,int* index){
    std::vector<std::thread> vec_cust;
    for (int i = 0; i < NB_CUST; i++) {
        vec_cust.push_back(std::thread (consomateur, v, index, i));
    }

    for ( auto& cust : vec_cust ) {
        cust.join();
    }
}
