#include <iostream>
#include <string>
using namespace std;

string & myreplace(string src,string::size_type pos, string::size_type count, const string& str){
    for(string::size_type i = 0; i< src.size(); ++i){
    	if(pos) pos--;
   		else{
   			src[i] = 

   		}
    }
}
int main()
{
    string str("The quick brown fox jumps over the lazy dog.");
    myreplace(str,0,5,"dddd");
 /*
    str.replace(10, 5, "red"); // (4)
 
    str.replace(str.begin(), str.begin() + 3, 1, 'A'); // (5)
*/ 
    std::cout << str << '\n';
}