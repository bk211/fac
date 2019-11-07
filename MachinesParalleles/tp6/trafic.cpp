#include "trafic.hpp"

typedef struct node node_t;
struct node{
    bool status;
    string name;
    int nbf;
    node_t * fils[4];
};

node_t create_node(string name){
    node_t res;
    res.status = false;
    res.name = name;
    res.nbf = 0;
    return res;
}

void affiche_node(node_t a){
    cout<<"La station <"<<a.name<<"> :\n";
    for (size_t i = 0; i < a.nbf; i++) {
        cout<<"\t>"<<a.fils[i]->name<<endl;
    }
    cout<<endl;
}

void create_road(node_t * a, node_t * b){
    a->fils[a->nbf++] = b;
    b->fils[b->nbf++] = a;
}

class voiture{
    mutex m;
    string id;
};

void run(voiture v, node_t * start){
    
}

int main(int argc, char const *argv[]) {
    node_t a = create_node("Alpha");
    node_t b = create_node("Bravo");
    node_t c = create_node("Charlie");
    node_t d = create_node("Delta");
    node_t e = create_node("Echo");
    create_road(&a, &b);
    create_road(&b, &c);
    create_road(&c, &d);
    create_road(&d, &a);
    create_road(&e, &a);
    create_road(&e, &b);
    create_road(&e, &c);
    create_road(&e, &d);

    //cout<<a.fils[0]->name;
    affiche_node(a);
    affiche_node(b);
    affiche_node(c);
    affiche_node(d);
    affiche_node(e);
    return 0;
}
