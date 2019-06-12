#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <queue>
typedef std::pair<uint, uint> arete;
typedef std::list<arete> liste_adjacentes;


void printPair(arete x){
	std::cout<<"("<< x.first << "," << x.second<<")";
}

class Graph{
	arete arr;
	liste_adjacentes liste;
	std::vector<liste_adjacentes> aretes;
	std::vector<liste_adjacentes> aretesParents;
	int taille;


public:

	Graph(int nb_sommet){//constructor
		aretes.resize(nb_sommet);
		aretesParents.resize(nb_sommet);
		taille = nb_sommet;
	}

	void ajouterArete(uint sommetDepart, uint sommetArrive, uint poids){
		aretes.at(sommetDepart-1).push_back(std::make_pair(sommetArrive, poids));
		std::cout<< "Add successfull (" << aretes.at(sommetDepart-1).back().first
		<<": "<<aretes.at(sommetDepart-1).back().second<< ")"<<std::endl;

		ajouterAreteParent(sommetDepart, sommetArrive, poids);
	}

	void ajouterAreteParent(uint sommetDepart, uint sommetArrive, uint poids){
		aretesParents.at(sommetArrive-1).push_back(std::make_pair(sommetDepart,poids));
		std::cout<< "Add successfull parent (" << aretesParents.at(sommetArrive-1).back().first
		<<": "<<aretesParents.at(sommetArrive-1).back().second<< ")"<<std::endl;

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
		std::cin>>nb_saisit;
		for (int i = 0; i < nb_saisit; ++i)
			{
				int sD,sA,p;
				std::cout<< "merci de saisir l'arrete numero "<<i<<std::endl;
				std::cin >> sD>>sA>>p;
				Graph::ajouterArete(sD,sA,p);

			}
	}


	void DFS_all(uint depart, uint arrive){

		std::vector<uint> v;
		uint cumm_poids = 0;
		Graph::DFS_traversal_aux(v, depart, arrive,cumm_poids);

	}
	void DFS_traversal_aux(std::vector<uint> chemin,uint depart, uint arrive, uint cumm_poids){
		chemin.push_back(depart);
		if (depart == arrive){
			for (auto itr : chemin)
			{
				std::cout<< itr <<" ,";
			}
			std::cout<< "|| poids total du chemin :"<<cumm_poids;
			std::cout<<std::endl;
		}

		for (auto itr : aretes.at(depart-1))
		{
			//std::cout<<"debug"<<itr.first;
			if(find(chemin.begin(), chemin.end(), itr.first) == chemin.end())//non parcourue

				DFS_traversal_aux(chemin, itr.first ,arrive, cumm_poids+ itr.second );
		}

	}



	void BFS_all(uint depart, uint arrive){
		std::list<std::list <uint> > visited;//pas de cycle
		std::queue<uint> Q;

		Q.push(depart);//init
		std::list<uint> empty;
		empty.push_back(depart);
		visited.push_back(empty);
		while (!Q.empty()){//tant que la queue n'est pas vide

			int size = Q.size();

			for(int i = 0; i < size; ++i){
				uint current = Q.front();

				if (current== arrive){
					/*for(auto itr : visited){
						std::cout<<itr<<" ,";
					}*/
					std::cout<<"\n";
					return ;// backtracking a faire
				}

				for(auto itr : aretes.at(current-1)){
					Q.push(itr.first);
				}

				Q.pop();
				//visited.back().insert(current);
			}
		}
		return ;
	}

	void BFS_traversal_aux(uint depart, uint arrive){

	}

};


int main(int argc, char const *argv[])
{
	Graph foo(8);
	foo.ajouterArete(1,2,10);
	foo.ajouterArete(2,5,10);
	foo.ajouterArete(2,4,10);

	//foo.ajouterArete(4,6,10);
	//foo.ajouterArete(4,2,10);
	//foo.ajouterArete(4,3,10);
	//foo.ajouterArete(4,2,10);
	//foo.ajouterArete(6,5,10);

	//foo.ajouterArete(5,3,10);
	//foo.affichage();
	//foo.remplirGraph();
//	foo.DFS_all(1,5);
	foo.BFS_all(1,5);
	return 0;
}
