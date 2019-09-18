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

int main(int argc, char const *argv[])
{
/*
    std::thread t1 (count,10,20);
    std::thread t2 (count,50,60);
    t1.join();
    t2.join();
*/ 

//    int a[5] = {1 , 3, 2, 5, 6};

    std::vector<int> v{1, 3, 2, 5, 6};
    std::thread t3 (find,v);
    t3.join();
    //std::cout<<"end";
    return 0;
}

