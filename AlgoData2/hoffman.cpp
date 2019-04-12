#include <iostream>
#include <vector>
#include <algorithm>
class Node{
    Node *left;
    Node *right;
    int weight;
    char c;
public:
    void zero(){}

};
typedef std::pair<char,int> mypair;
std::vector<mypair> geneseTabChar(std::string s){
    std::vector<mypair> v;
    v.reserve(s.size());

    for (char& c : s){
        bool find = false;
        for (auto&it :v){
            //std::cout << "current it: " <<it.first<< '\n';
            if(it.first == c){
                it.second++;
                find = true;
            }
        }
        //std::cout << "current char: " <<c<< '\n';
        if(!find){
            //std::cout << "pushing new" << '\n';
            v.push_back(std::make_pair(c,1));
            find = false;
        }
        //    v.push_back(std::make_pair('X',1));
        //    used.push_back(c);
    }
//affiche v cree
    for (auto itr: v) {
        std::cout << itr.first << ':'<< itr.second<<std::endl;
    }
    return v;
}


int main(int argc, char const *argv[]) {
    std::string a = "Ceci n'est pas une pipe";
    //std::string a = "abcdc";
    std::cout<<a<<std::endl;
    geneseTabChar(a);
    return 0;
}
