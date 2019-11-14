#include "trafic.hpp"

typedef struct node node_t;
struct node{
    bool status;
    string name;
    int nbf;//nombre de fils
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

void _sleep(){
    int t = rand() % SLEEP_TIME + 1; //sleep entre 1 et SLEEP_TIME
    cout << "Sleeping for " << t<< " secs\n\n";
    this_thread::sleep_for(chrono::seconds(t));
}

class Voiture{
public:
    mutex m;
    int id;
    int nb_trajet =0;
    node_t * current_node;//ptr vers le noeu ou se situe la voiture

    Voiture(int s, node_t * node){
        id = s;
        current_node = node;
        current_node->status = true;
        affiche_location();
    }

    bool next(){
        int i = rand() % current_node->nbf;
    //    cout <<"next target = "<< i << '\n';
        for (int j = 0; j < NB_TRY ; j++) {
            if(m.try_lock()){
                //cout<<"try_lock successful\n";
                if(current_node->fils[i]->status == false){
                current_node->fils[i]->status = true;//met le destination a true/occupe
                _sleep();//fait le chemin
                current_node->status = false;//quitte officiellement le noeud precedent
                current_node = current_node->fils[i];
                affiche_location();
                m.unlock();
                return true;//la voiture est arriver au noeud suivant, la fct est terminee
                }else{
                    m.unlock();
                    // l'emplacement est occupe, la voiture prends une pause et retente le trajet
                    //cout<<current_node->fils[i]->name<<" occupied\n";
                    _sleep();
                }
            }else{
            //cout<<"try lock failed\n";
            _sleep();
            }
        }

        //echec des 5 tentatives, la fct retourne false
        cout<<"<<"<< id<<">> failed to reach:" << current_node->fils[i]->name <<endl;
        return false;
    }

    void affiche_location(){
    cout<<"<<"<< id<<">>" <<" occupe actuellement "<<current_node->name<<endl;
    }

    void trajet(){
        int i = 0, j = 0;
        while(i< NB_TRAJET){
            if(next()){
                ++i;
                j = 0;
            }else{
                ++j;
            }

            if(j > NB_ECHEC){
                break;
            }
        }

        if(i == NB_TRAJET){//la voiture a fait ses 5 trajets correctement
            cout<<"End successful\n";
            current_node->status = false;//la voiture quitte le circuit
            return;
        }
        cout<<"End unsucessful\n";
        current_node->status = false;//la voiture quitte le circuit
        return;
    }

    thread start_trajet(){
        return thread([=] {trajet();} );
    }


};




int main(int argc, char const *argv[]) {
    srand(time(NULL));
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
    //cout<<a.nbf;;
    Voiture vehi1(1,&a);
    Voiture vehi2(2,&b);
    Voiture vehi3(3,&d);



    vehi1.affiche_location();
    //vehi1.affiche_location();
    //run(vehi1);
    thread t1 = vehi1.start_trajet();
    thread t2 = vehi2.start_trajet();
    thread t3 = vehi3.start_trajet();
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
