#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>
#include <mutex>
#include <stdlib.h>

std::mutex mymutex;

#define SLEEP_TIME 2
#define MAX_POP_TIME 10

void producteur(std::vector<int> *v, int* index);
void consomateur(std::vector<int> *v,int* index);

void _sleep_for(){
    int t = rand() % SLEEP_TIME + 1; //sleep entre 1 et SLEEP_TIME
    std::cout << "Sleeping for " << t<< " secs\n";
    sleep(t);
}


int main(int argc, char const *argv[]) {
    srand (time(NULL));
    std::vector<int> panier;
    int index = 0;
    std::thread t1(producteur,&panier, &index);
    std::thread t2(consomateur,&panier, &index);

    t2.join();
    t1.join();
    return 0;
}


void producteur(std::vector<int>* v, int *index){
    for (int i = 0; *index <10 ; i++) {
        mymutex.lock();
        v->push_back(i);
        *index +=1;
        std::cout << "Prod: pushed " << i<< " au panier" <<", Il contient "<< *index<<" elements \n";
        //for(auto k: *v){ std::cout << k << " ,";}
        //std::cout << '\n';
        mymutex.unlock();
        _sleep_for();
    }
    std::cout << "End of prod" << '\n';
}

void consomateur(std::vector<int>* v,int *index){
    int x;
    int npop = 0;
    sleep(1);
    //std::cout << "wake up" << '\n';
    while (*index>0) {
        mymutex.lock();
        x = v->back();
        v->pop_back();
        *index -=1;
        std::cout << "Cust: pop " << x << " au panier"<<", Il contient "<< *index<<" elements \n";
        //for(auto k: *v){ std::cout << k << " ,";}
        mymutex.unlock();
        npop++;
        if (npop == MAX_POP_TIME) {
            std::cout << "MAX_POP_TIME reached" << '\n';
            break;
        }
        _sleep_for();
    }
    std::cout << "End of cust" << '\n';

}
