#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>

std::mutex mymutex;
void count(int x,int y)
{
    mymutex.lock();
    for (int i = x; i < y; ++i)
    {
        std::cout<<i<<std::endl;
    }

    mymutex.unlock();

}


void find(std::vector<int> tab){
    mymutex.lock();
    std::cout<<"end";
    int max =tab[0];

    for(auto x : tab){
        if (x > max){
            max = x;
        }
    }
    std::cout<<max;
//    std:: remove (tab.begin(), tab.end(), max);
    mymutex.unlock();
}

void max(int tab[], int begin, int end){// [begin,end]
    int max = tab[begin];
    for (int i = begin; i <= end; i++) {
        if (tab[i]>max) {
            max=tab[i];
        }
    }
    std::cout << "Entre la position " << begin<<" et "<< end<<'\n';
    std::cout << "le max vaut " <<max <<'\n';
}

void search(int tab[], int t, int intervalle){
    std::vector<std::thread> v;
    int i;
    for (i = 0; i < t; i+=intervalle) {
        if(i+intervalle<t){
            v.push_back(std::thread(max, tab, i, i+intervalle-1));
        }
    }
    v.push_back(std::thread(max, tab, i-intervalle,t-1));
    for ( auto &i: v) {
        if( i.joinable())
            i.join();
    }
}

int main(int argc, char const *argv[])
{
/*
    std::thread t1 (count,10,20);
    std::thread t2 (count,50,60);
    t1.join();
    t2.join();
*/

    int a[] = {1 , 3, 2, 5, 6, 7,-1};
    for (auto i : a) {std::cout << i << ", " ;} // affiche
    std::cout << '\n';
    int taille = 2;
    //int nbt = 3;
    //float p = nbt/ taille;
    search(a, taille, 2);
    //max(a,0, 4);


    //std::cout<<"end";
    return 0;
}

/*
http://www.zedwood.com/article/cpp-md5-function
*/
