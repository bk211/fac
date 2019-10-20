#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <string>

/*
    mots de 2 characteres no need
    pas de nombre

*/
int main(int argc, char const *argv[]) {
    std::string line;
    char c;
    if(argc == 2){
        std::ifstream myfile(argv[1]);
        if(myfile.is_open()){

            while (myfile.get(c)) {
                std::cout << c;
            }
            myfile.close();
        }
    }
    else{
        std::cout << "Usage: ./executable Filename" << '\n';
    }
    return 0;
}
