#include <fstream>
#include <iostream>
#include <codecvt>
#include <queue>
#include <algorithm>
#include <iterator>
#include "Huffman.hpp"

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

NoeudH::NoeudH (wchar_t c, unsigned int p):c(c),gauche(nullptr),droit(nullptr), poids (p){}

NoeudH::NoeudH (unique_ptr <NoeudH> f1, unique_ptr <NoeudH> f2):c(-1),
	gauche (move (f1)), droit (move(f2)),
	poids(gauche->poids+droit->poids) {}

void ArbreH::majF (const std::string & fichier){
  wifstream ifs (fichier);
  ifs.imbue(locale("fr_FR.UTF-8"));
  cout.imbue(locale("fr_FR.UTF-8"));
  for(wchar_t c; ifs>>c; ){
    frequences[c]++;
  }
}

void ArbreH::majA (){
  vector <unique_ptr <NoeudH>> file;
  NoeudH::comp comp;
  for (auto [c, f] : frequences){
    auto upper = std::upper_bound(file.begin(), file.end(), f, comp);
    file.emplace (upper, make_unique<NoeudH> (c,f));
  }
  if (!file.empty()){
    while (file.size ()>1){
      unique_ptr <NoeudH> min1 (move(file.back())); file.pop_back(); 
      unique_ptr <NoeudH> min2 (move(file.back())); file.pop_back(); 
      auto upper = std::upper_bound(file.begin(), file.end(), min1->poids + min2->poids, comp);
      file.emplace (upper, make_unique <NoeudH> (move (min1), move (min2)));
    }
    racine=move(file.back());file.pop_back();
  }
}

void ArbreH::majC (){
  queue < pair <vector <bool>, NoeudH*> > a_suivre;
  a_suivre.emplace (make_pair (vector <bool> (), racine.get()));
  while (!a_suivre.empty()){
    auto [v, n] = a_suivre.front (); a_suivre.pop ();
    if (n->c != -1) 
      codes[n->c]=v;
    else { 
      v.push_back (0);
      a_suivre.emplace (make_pair (v, n->gauche.get ()));
      v.pop_back ();
      v.push_back (1);
      a_suivre.emplace (make_pair (v, n->droit.get()));
      v.pop_back ();
    }
  }
  for (auto & [c, v] : codes){
    cout << UTF8 (u32string () + (char32_t) c) << " : ";
    copy (v.begin (), v.end (), ostream_iterator<bool> (cout));
    cout << endl;
  }
}


ArbreH::ArbreH (const string & fichier):racine(nullptr){
  majF(fichier);
  majA();
  majC();
}	

void ArbreH::coder (const string &s, vector<bool> *v){
  if (v != nullptr){
    u32string s32 = UTF32 (s);
    for (char32_t c32 : s32) {
       const vector<bool> & c = codes [c32];
       copy (c.begin (), c.end (), back_inserter (*v));
    }
  }
}

void ArbreH::decoder (const vector <bool> &v, string * s){
  if (s != nullptr){
  u32string s32;
    NoeudH * courant = racine.get ();
    for (bool b : v){
      courant = b ? courant->droit.get () : courant->gauche.get ();
      if (courant->c != -1){
        s32 += courant->c;
	courant = racine.get ();
      }
    }
  *s=UTF8(s32);
  }
}

int main (){
  ArbreH h ("test.txt");
  vector <bool> v;
  h.coder ("Huffman", &v);
  copy (v.begin (), v.end (), ostream_iterator <bool> (cout));
  cout << endl;
  string s;
  h.decoder (v, &s);
  cout<<s<<endl;
}



