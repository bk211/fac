#include <bits/stdc++.h>

using namespace std;
class Country
{
private:
    string name;
    int color;
    vector<Country> neighbourg;
    //vector<Country*> neighbourg;
    
public:
    Country(string n){
        name = n;
        color = 0;
    }

    void print_Country(){
        cout<<"name: "<< name<<endl;
        cout<<"color: "<< color<<endl;
    }
};


int main(int argc, char const *argv[])
{
    Country france("france");
    Country Espagne("Espagne");
    Country Portugale("Portugale");
    Country Andorre("Andorre");
    Country Italie("Italie");
    Country Autriche("Autriche");
    Country Suisse("Suisse");
    Country Allemagne("Allemagne");
    Country Luxembourg("Luxembourg");
    Country Belgique("Belgique");
    Country Pays_bas("Pays_bas");
    
    france.print_Country();

    return 0;
}

