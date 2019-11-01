#include <vector>
#include <iostream>

class Noeud{
public:
    char letter;
    int count;
    std::vector<noeud> next;

    Noeud(char l){
        letter = l;
    }
};
