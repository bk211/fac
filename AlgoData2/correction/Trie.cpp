#include <fstream>
#include <iostream>
#include <algorithm>
#include <codecvt>
#include "Trie.hpp"

using namespace std;

string UTF8 (const u32string &s)
{
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    return conv.to_bytes(s);
}

u32string UTF32 (const string &s)
{
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    return conv.from_bytes(s);
}

Noeud::Noeud  (): lettre('\0'), fils (), finMot(false) 
{}

Noeud::Noeud  (char32_t l, bool fm): lettre (l), fils (), finMot (fm)
{}

Noeud::~Noeud (){}


Trie::Trie  (): dictionnaire (){}

Trie::Trie  (const string & fichier){
  ifstream ifs (fichier);
  string mot;
  ifs.imbue(locale("fr_FR.UTF-8"));
  cout.imbue(locale("fr_FR.UTF-8"));
  while (ifs>>mot){
    ajouterMot (mot);
  }
}
Trie::~Trie (){}

void Trie::ajouterMot (const string & mot8) {
  u32string mot = UTF32 (mot8);
  Noeud * courant = &dictionnaire;
  for (int i=0; i<mot.length(); ++i){
    vector <Noeud> & fils = courant->fils;
    char32_t c = mot[i];
    bool fin = (i+1==mot.length());
    auto it = find_if(fils.begin(), fils.end(), [c](const Noeud & n){return n.lettre==c;});
    if (it != fils.end()){
      courant=&(*it);
      courant->finMot |= fin;
    }
    else{
      courant=&(fils.emplace_back(c, fin));
    }
  }
}

const Noeud * Trie::fin_prefixe (const u32string & prefixe) const {
  const Noeud * courant = &dictionnaire;
  for (int i=0; i<prefixe.length(); i++){
    const vector<Noeud> & fils =courant->fils;
    char32_t c = prefixe[i];
    auto it = find_if(fils.begin(), fils.end(), [c](const Noeud & n){return n.lettre==c;});
    if (it != fils.end()){
      courant=&(*it);
    } 
    else { return NULL; }
  }
  return courant;
}

void Trie::explorer (vector<string> * propositions, const Noeud * n, const u32string & prefixe) const{
  for (Noeud n : n->fils){
    u32string proposition = prefixe + n.lettre;
    if (n.finMot) propositions->push_back (UTF8(proposition));
    explorer (propositions, &n, proposition);
  }
}

vector<string> Trie::chercher (const string & prefixe)const {
  vector<string> propositions;
  u32string pref =UTF32(prefixe);
  const Noeud *courant = fin_prefixe (pref);
  if (courant==NULL) return propositions;
  explorer (&propositions, courant, pref);
  return propositions;
}

int main (){
  Trie t ("liste_mots.txt");
  vector<string> propo = t.chercher (u8"élé");
  cout<<"Nb propositions : "<<propo.size ()<<endl;
  for (auto s : propo){
    cout<<s<< "    \n";
  }
}

