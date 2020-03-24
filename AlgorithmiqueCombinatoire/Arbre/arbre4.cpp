#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <math.h>
typedef struct arbre arbre; 
struct arbre
{
	int data;
	arbre *gauche ;
	arbre *droit  ;
};

arbre *CreateElement(arbre *Root, int value)
{
	Root= new arbre;
	Root->data=value;
	Root->gauche=NULL;
	Root->droit=NULL;
	return Root;
}


void Largeur(arbre * Racine){
	std::vector<arbre *> file;
	file.push_back(Racine);
	arbre buffer; 
	while (file.empty() == false){
		buffer = *file.front();
		printf("%c ", buffer.data);
		if(buffer.gauche !=NULL){
			file.push_back(buffer.gauche);
		}
		if(buffer.droit != NULL){
			file.push_back(buffer.droit);
		}
		file.erase(file.begin());
	}
	
}

arbre * gen_arbre_parfait(int n){
    arbre * Racine;
    Racine =NULL;
    arbre * r0 = NULL;
    CreateElement(r0, 1);
    printf("%d", r0->data);
    /*
	std::vector<arbre *> file;
	file.push_back(Racine);
    arbre buffer;
    int size;
    for (int i = 1; i < n; i++){//pr chaque niveau
        size = file.size();
        for (int j = 0; j < size; j++){ //pr chaque noeud de ce niveau
            buffer = *file.front();
            CreateElement(buffer.gauche, pow(2, buffer.data)   );
            CreateElement(buffer.gauche, pow(2, buffer.data) +1);
            file.push_back(buffer.gauche);
            file.push_back(buffer.droit);
            file.erase(file.begin());
        }
    }*/
    return  Racine;
}

int main(int argc, char const *argv[])
{

    arbre *parfait = gen_arbre_parfait(1);
    //Largeur(parfait);
    return 0;
}
