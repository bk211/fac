#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <queue>

class Trie{
public:
    char lettre;
    std::vector<Trie> noeuds_fils;
    bool fin;

    Trie(char l, bool f){
        lettre = l;
        fin = f;
    }

    bool ajouter(){

    }
    bool ajouter_ann(std::string mots, int curr){
        int size = mots.size();
        if (mots.at(curr) == lettre){
            curr++;
            if (Trie::check_fils(mots.at(curr))){
                
            }

        }


        if (curr < size){

        Trie::ajouter_fils(mots.at(curr), curr == size);
        std::cout << "/* message */" << '\n';
        std::cout << noeuds_fils.back().lettre << '\n';

        }


    }
    bool check_fils(char a){
        for(auto itr: noeuds_fils){
            if(itr.lettre == a) return true;
        }
        return false;
    }

    Trie ajouter_fils(char a , bool end){
        for(auto itr:noeuds_fils){
            if(itr.lettre == a){//cas fils deja present
                itr.fin = end;
                return itr;
            }
        }
        //cas fils non present
        Trie fils = Trie(a, end);
        noeuds_fils.push_back(fils);
        return noeuds_fils.back();

    }

};



int main(int argc, char const *argv[]) {
    Trie foo = Trie('A',true);
    foo.ajouter_ann("Ai",0);
    return 0;
}
