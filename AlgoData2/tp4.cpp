#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

typedef std::pair<uint, uint> arete;
typedef std::list<arete> liste_adjacentes;

void printPair(arete x){
	std::cout<<"("<< x.first << "," << x.second<<")"; 
}

class Graph{
public:
	arete arr;
	liste_adjacentes liste;
	std::vector<liste_adjacentes> aretes;
	int taille;
	Graph(int nb_sommet){//constructor
		aretes.resize(nb_sommet);
		taille = nb_sommet;
	}

	void ajouterArete(uint sommetDepart, uint sommetArrive, uint poids){
		aretes.at(sommetDepart-1).push_back(std::make_pair(sommetArrive, poids));
		std::cout<< "Add successfull (" << aretes.at(sommetDepart-1).back().first
		<<": "<<aretes.at(sommetDepart-1).back().second<< ")"<<std::endl;
	}

	void affichage(){
		for (int i = 0; i < taille; ++i)
		{
			std::cout<< "Sommet:" << i+1 << std::endl;

			for (auto arete : aretes.at(i)){
				printPair(arete);
				std::cout<<", ";
			}
			std::cout<<std::endl;

		}
	}

	void remplirGraph(){
		int nb_saisit=0;
		std::string input;
		std::cout<< "merci de saisir le nombre d'arrete a ajouter\n";
		getline(std::cin, input);

	}
};

int main(int argc, char const *argv[])
{
	Graph foo(8);
	foo.ajouterArete(1,2,10);
	foo.ajouterArete(2,5,10);
	foo.ajouterArete(1,2,10);
	foo.affichage();
	return 0;
}