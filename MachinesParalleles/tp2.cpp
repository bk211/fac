#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include "md5.h"
#include <string>

#define DEBUT 48 // '0'
#define FIN 122 //'z'

int test(std::string code, std::string compare){// 0 == True
    //return (code.compare(md5(compare)));
    return (code.compare(compare));
}

int loop_over_pos(std::string code, std::string str,int pos, int debut, int fin){
    for (int i = debut; i < fin; i++) {
        str[pos] = i;
        if(!(test(code, str))){
            return 1;
        }
    }
    return 0;
}

int loop_search(std::string code){
    std::string begin ("0");
    for (size_t i = 0; i < begin.size(); i++) {
        std::cout << begin.size() << '\n';
        if(loop_over_pos(code, begin, i, DEBUT,FIN)){
            return 1;
        }
    }
    return 0;
}


int main(int argc, char const *argv[]) {
    std::string a ("45950e8a33255cc2db70cbof67a62d3a");
    //std::cout << test(md5(a),a)<< '\n';
    std::string b (1,48);
    std::string c ("z");
    //std::cout << b << '\n';
//    std::cout << loop_over_pos(b,c,0,DEBUT,FIN)<< '\n';
std::cout <<
loop_search(c)
 << '\n';
    return 0;
}
