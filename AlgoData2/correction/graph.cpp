#include "graph.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

Graph::Graph (unsigned int nb_sommets) {
  graph.resize(nb_sommets); 
}

void Graph::ajouter_arete (unsigned int origine, unsigned int destination, unsigned int poids) {
  graph[origine].emplace_front(destination, poids); 
}

void Graph::afficher () {
  liste_adjacence::iterator it;
  for (uint v = 0; v < graph.size(); ++v) {
    cout<<"Sommet "<<v<<"\n";
    cout<<"  Aretes : \n";
    for (it = graph[v].begin(); it != graph[v].end(); ++it) {
      cout << "    "<< v <<" -- (" << it->second << ")--> " << it->first << "\n";
    }
   cout << "\n"; }
}

void Graph::charger (Graph *g){
  int nb_sommets, nb_aretes;
  ifstream ifs;
  ifs.open ("graph.txt", ifstream::in);
  ifs >>  nb_sommets;
  g->graph.resize(nb_sommets);
  for (int i = 0; i<nb_sommets; ++i){
    ifs >> nb_aretes;
    for (int j=0; j<nb_aretes;++j){
      unsigned int s, p;
      ifs >> s;
      ifs >> p;
      g->ajouter_arete (i, s, p); 
    }
  }
  ifs.close();
}
void Graph::explorer_branche (arete a, unsigned int destination, liste_adjacence chemin_courant, vector<pair<liste_adjacence, int>> * chemins){
   if ((find (chemin_courant.begin(), chemin_courant.end(), a)) !=  chemin_courant.end()) return;//FIXME
   chemin_courant.emplace_back (a);
   if (a.first==destination){
     int poids=0;
     for (auto e : chemin_courant) poids+=e.second;
     chemins->emplace_back (chemin_courant, poids);
     return;
   }
   for (arete i : graph[a.first])
     explorer_branche (i, destination, chemin_courant, chemins);
}

void Graph::chemins_profondeur (unsigned int origine, unsigned int destination, vector<pair<liste_adjacence, int>> * chemins){
  liste_adjacence chemin_courant;
  chemin_courant.emplace_back (origine, 0);
  for (arete a : graph[origine]){
    explorer_branche (a, destination, chemin_courant, chemins);
  }  
}
  
void Graph::chemins_largeur (unsigned int origine, unsigned int destination, vector<pair<liste_adjacence, int>> * chemins){
  queue<pair<arete, liste_adjacence>> a_suivre;
  a_suivre.emplace(make_pair(origine, 0), liste_adjacence ());
  while (!a_suivre.empty()){
    auto[a,chemin_courant]=a_suivre.front (); a_suivre.pop ();
    if ((find (chemin_courant.begin(), chemin_courant.end(), a)) !=  chemin_courant.end()) continue;//FIXME
    chemin_courant.emplace_back (a);
    if (a.first==destination){
      int poids=0;
      for (auto e : chemin_courant) poids+=e.second;
      chemins->emplace_back (chemin_courant, poids);
      continue;
    }
    for (arete i : graph[a.first])
      a_suivre.emplace (i, chemin_courant);
  } 
}

int Graph::dijkstra (unsigned int origine, unsigned int destination, vector <arete> * chemin){
  vector <bool>  visites    (graph.size (), false);
  vector <int>   distances  (graph.size (), INT_MAX);
  vector <arete> precedents (graph.size ());
  priority_queue <arete, vector<arete>, comp> a_suivre;

  distances[origine]=0;
  a_suivre.emplace (make_pair (origine, 0));
  while (!a_suivre.empty()){
    arete suivant = a_suivre.top (); a_suivre.pop ();
    unsigned int suiv = suivant.first;
    if (visites[suiv]) continue;
    else visites[suiv]=true;
    for (arete a : graph[suiv]){
      int d = distances [suiv] + a.second;
      if (distances[a.first] > d){
        distances[a.first]=d;
        precedents[a.first]=make_pair (suiv, a.second);
	a_suivre.emplace (make_pair (a.first, d));
      }
    }

  }
  int distance = distances[destination];
  while (destination != origine){
    chemin->emplace_back(make_pair (destination, precedents[destination].second));
    destination=precedents[destination].first;
  } 
  chemin->emplace_back(make_pair (origine, 0));
  return distance;
}

int main (){
  Graph g (0);
  Graph::charger (&g);
  g.afficher ();
  vector<pair<Graph::liste_adjacence, int>> chemins;
  g.chemins_profondeur (0, 5, &chemins);
  for (int i=0; i<chemins.size(); ++i){
    cout<<"Chemin profondeur"<<i<<", poids :  "<<chemins[i].second<<endl;
    for (Graph::arete a : chemins[i].first){
      cout<<a.first<<"  ";	  
    }
    cout<<endl;
  }
  chemins.clear();
  g.chemins_largeur (0, 5, &chemins);
  for (int i=0; i<chemins.size(); ++i){
    cout<<"Chemin largeur"<<i<<", poids :  "<<chemins[i].second<<endl;
    for (Graph::arete a : chemins[i].first){
      cout<<a.first<<"  ";	  
    }
    cout<<endl;
  }
   
  vector <Graph::arete> c;
  int d = g.dijkstra (0, 5, &c);
  reverse (c.begin(), c.end());
  cout<<"Dijkstra, distance == "<<d<<endl;
  for (Graph::arete a : c){
      cout<<a.first<<"  " ;	  
    }
    cout<<endl;


}
