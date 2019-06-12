#ifndef GRAPH_HPP___
#define GRAPH_HPP___

#include <vector>
#include <list>
#include <utility>


class Graph {
  public:
    typedef std::pair<unsigned int, unsigned int> arete;
    typedef std::list<arete> liste_adjacence;
  public:
    Graph (unsigned int nb_sommets =0);
    void ajouter_arete (unsigned int origine, unsigned int destination, unsigned int poids);
    void afficher ();
    void explorer_branche (arete a, unsigned int destination, liste_adjacence chemin_courant, std::vector<std::pair<liste_adjacence, int>> * chemins);
    void chemins_profondeur (unsigned int origine, unsigned int destination, std::vector<std::pair<liste_adjacence, int>> * chemins);
    void chemins_largeur (unsigned int origine, unsigned int destination, std::vector<std::pair<liste_adjacence, int>> * chemins);
    int dijkstra (unsigned int origine, unsigned int destination, std::vector <arete> * chemins);
    static void charger (Graph *);

    struct comp {
      bool operator() (const arete &a, const arete &b) const {return a.second < b.second;}
    };
  private:
    std::vector<liste_adjacence> graph;
};
#endif // GRAPH_HPP___
 

