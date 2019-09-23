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

void max(std::vector<int> p, int begin, int end){
    int max = p[begin];


    std::cout << "Max entre emplacement " << begin <<" et "<<end <<" = "<<max<<'\n';
}

void split(std::vector<int> v, int taille, int nb){
    for (int i = 0; i < taille; i+=nb) {
        std::thread (max, i, i+nb);
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

//    int a[5] = {1 , 3, 2, 5, 6};

    std::vector<int> v{1, 3, 2, 5, 6, 7, 9, 11,-2, -89};
    for (auto i : v) {std::cout << i << '\n';} // affiche
    int taille = v.size();
    int nbt = 3;
    float p = nbt/ taille;
    max(v,0, 9);


    //std::cout<<"end";
    return 0;
}

/*
http://www.zwood.com/article/cpp-md5-function

*/
