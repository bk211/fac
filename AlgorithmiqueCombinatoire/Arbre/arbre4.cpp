#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <math.h>
typedef struct Arbre Arbre; 
struct Arbre
{
    int data;
    Arbre *gauche ;
    Arbre *droit  ;
};

Arbre *CreateElement(Arbre *Root, int value)
{
    Root= new Arbre;
    Root->data=value;
    Root->gauche=NULL;
    Root->droit=NULL;
    return Root;
}


void Largeur(Arbre * Racine){
    std::vector<Arbre *> file;
    file.push_back(Racine);
    Arbre buffer; 
    while (file.empty() == false){
        buffer = *file.front();
        printf("%d ", buffer.data);
        if(buffer.gauche !=NULL){
            file.push_back(buffer.gauche);
        }
        if(buffer.droit != NULL){
            file.push_back(buffer.droit);
        }
        file.erase(file.begin());
    }
    
}

Arbre * gen_arbre_parfait(int n){
    Arbre *Racine =NULL;
    Racine = CreateElement(Racine, 1);

    std::vector<Arbre *> file;
    file.push_back(Racine);
    Arbre *buffer;
    int size;
    for (int i = 1; i < n; i++){//pr chaque niveau
        size = file.size();
        for (int j = 0; j < size; j++){ //pr chaque noeud de ce niveau
            buffer = file.front();
            buffer->gauche = CreateElement(buffer->gauche, pow(2, buffer->data)   );
            buffer->droit = CreateElement(buffer->droit, pow(2, buffer->data) +1);
            file.push_back(buffer->gauche);
            file.push_back(buffer->droit);
            file.erase(file.begin());
        }
    }
    return  Racine;
}

int main(int argc, char const *argv[])
{
    Arbre *parfait = gen_arbre_parfait(4);
    Largeur(parfait);
    return 0;
}
