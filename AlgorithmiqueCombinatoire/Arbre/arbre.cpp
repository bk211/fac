#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <math.h>
typedef struct Element Element; 
struct Element
{
	char data;
	Element *gauche ;
	Element *droit  ;
};

//  Cration d'un lment de l'arbre
Element *CreateElement(Element *Root, char value)
{
	Root= new Element;
	Root->data=value;
	Root->gauche=NULL;
	Root->droit=NULL;
	return Root;
}

// 1. Visit the root 2. traverse the left subtree 3. traverse the right subtree
void PreFixe(Element * Racine)
{
	if (Racine!=NULL)
	{
		printf("%c ",Racine->data);
		PreFixe(Racine->gauche);	
		PreFixe(Racine->droit);
	}
}

// 1. traverse the left subtree 2. Visit the root 3. traverse the right subtree 
void Infixe(Element * Racine)
{
	if (Racine!=NULL)
	{
		Infixe(Racine->gauche);	
		printf("%c ",Racine->data);
		Infixe(Racine->droit);
	}
}

// 1. traverse the left subtree 2. traverse the right subtree 3. Visit the root 
void Postfixe(Element * Racine)
{
	if (Racine!=NULL)
	{
		Postfixe(Racine->gauche);	
		Postfixe(Racine->droit);
		printf("%c ",Racine->data);
	}
}

void Largeur(Element * Racine){
	std::vector<Element *> file;//file
	file.push_back(Racine);//mettre dans la file
	Element buffer; 
	while (file.empty() == false){ // tant que la file n'est pas vide
		buffer = *file.front(); // obtiens le premier element de la file
		printf("%c ", buffer.data);// visite
		if(buffer.gauche !=NULL){ // si branche gauche, push vers la file
			file.push_back(buffer.gauche);
		}
		if(buffer.droit != NULL){ // si branche droit, push vers la file
			file.push_back(buffer.droit);
		}
		file.erase(file.begin()); // supprime l'element deja visite 
	}
	
}

int taille_ann(Element * Racine){//retourne le nb de noeud d'un arbre
	if(Racine !=NULL){
		return 1 + taille_ann(Racine->gauche) + taille_ann(Racine->droit); 
	}
	return 0;
}
void taille(Element * Racine){ // affiche le nb de noeud d'un arbre
	printf("taille = %d", taille_ann(Racine));
}


typedef struct Arbre Arbre; // struct pour l'exo 4 pour data de type nombre
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


void Largeur(Arbre * Racine){// parcous largeur, mais pour mon struct 
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

Arbre * gen_arbre_parfait(int n){// cree un arbre parfait
    Arbre *Racine =NULL;
    Racine = CreateElement(Racine, 1);

    std::vector<Arbre *> file;
    file.push_back(Racine); 
    Arbre *buffer;
    int size;
    for (int i = 1; i < n; i++){//pr chaque niveau
        size = file.size();
        for (int j = 0; j < size; j++){ //pr chaque noeud de ce niveau
            buffer = file.front(); // obtiens le premier element du file 
            buffer->gauche = CreateElement(buffer->gauche, pow(2, buffer->data)   ); // cree son branche gauche 
            buffer->droit = CreateElement(buffer->droit, pow(2, buffer->data) +1); //cree son branche droit

            file.push_back(buffer->gauche); // push back dans la file
            file.push_back(buffer->droit); // push back dans la file
            file.erase(file.begin()); // supprime du file le noeud traité
        }
    }
    return  Racine;// retourne la racine de l'arbre
}


std::string MaxChemin_ann(Element *Racine, std::string chemin){
    std::string g = "",d = "";
    if(Racine != NULL){//si pas de fils gauche ni fils droit, c'est une feuille
        if(Racine->gauche == NULL && Racine->droit == NULL){
            return chemin + Racine->data; // retourne le chemin vers cette feuille
        }
        if(Racine->gauche){ // si chemin gauche existe, appel recursive 
//            std::cout<<">>>>> "<< chemin + Racine->data<<std::endl;
            g = MaxChemin_ann(Racine->gauche, chemin + Racine->data);
        }
        if(Racine->droit){ // si chemin droit existe, appel recursive
            d = MaxChemin_ann(Racine->droit, chemin + Racine->data);
        }
    }else{// si l'arbre est NULL, retourner le chemin 
        return chemin;
    }

    if(g.size() >= d.size()){ // si un chemin à gauche est plus longue 
        chemin = g; // prendre la gauche
    }else{
        chemin = d;//sinon prendre la droite
    }
    //std::cout<<chemin<<std::endl;
    return chemin; // retourne le plus long chemin sous forme de string
}

void MaxChemin(Element *Racine){// affiche le plus long chemin d'un arbre
    if(Racine == NULL){
        return;
    }
    std::string s = MaxChemin_ann(Racine, std::string(""));
    std::cout<<"R = " <<s<<std::endl;

}



int main()
{
	Element *Racine;
	Racine=NULL;
	
	Element *e1 = NULL; e1 = CreateElement(e1,'A');
	Element *e2 = NULL; e2 = CreateElement(e2,'B');
	Element *e3 = NULL; e3 = CreateElement(e3,'C');
	Element *e4 = NULL; e4 = CreateElement(e4,'D');
	Element *e5 = NULL; e5 = CreateElement(e5,'E');
	Element *e6 = NULL; e6 = CreateElement(e6,'F');
	Element *e7 = NULL; e7 = CreateElement(e7,'G');
	Element *e8 = NULL; e8 = CreateElement(e8,'H');
	Element *e9 = NULL; e9 = CreateElement(e9,'I');
	Element *e10 = NULL;e10 = CreateElement(e10,'J');
	
	e1->gauche = e2;
	e1->droit = e9;
	e2->gauche = e4;
	e2->droit = e5;
	e4->gauche = e7;
	e4->droit = e8;
	e9->gauche = e3;
	e9->droit = e10;
	e3->gauche = e6;
	Racine = e1;
	printf("\n ============================= \n ");
	printf("\n Parcours PreFixe \n ");
	PreFixe(Racine);
	printf("\n Taille arbre E \n ");
	taille(Racine);
	printf("\n ============================= \n ");
	
	
	
    Element *f1  = NULL; f1 = CreateElement(f1,'A');
	Element *f2  = NULL; f2 = CreateElement(f2,'B');
	Element *f3  = NULL; f3 = CreateElement(f3,'C');
	Element *f4  = NULL; f4 = CreateElement(f4,'D');
	Element *f5  = NULL; f5 = CreateElement(f5,'E');
	Element *f6  = NULL; f6 = CreateElement(f6,'F');
	Element *f7  = NULL; f7 = CreateElement(f7,'G');
	Element *f8  = NULL; f8 = CreateElement(f8,'H');
	Element *f9  = NULL; f9 = CreateElement(f9,'I');
	Element *f10 = NULL; f10= CreateElement(f10,'J');
	Element *f11 = NULL; f11= CreateElement(f11,'K');
	
	f8->gauche = f4;
	f8->droit = f10;
	f10->gauche = f9;
	f10->droit = f11;
	f4->gauche = f2;
	f4->droit = f6;
	f2->gauche = f1;
	f2->droit =f3;
	f6->gauche = f5;
	f6->droit = f7;
	
	Racine = f8;
	printf("\n ============================= \n ");
	printf("\n Parcours Infixe \n ");
	Infixe(Racine);
	printf("\n Taille arbre F \n ");
	taille(Racine);
	printf("\n ============================= \n ");
	

	
	Element *g1  = NULL; g1 = CreateElement(g1,'A');
	Element *g2  = NULL; g2 = CreateElement(g2,'B');
	Element *g3  = NULL; g3 = CreateElement(g3,'C');
	Element *g4  = NULL; g4 = CreateElement(g4,'D');
	Element *g5  = NULL; g5 = CreateElement(g5,'E');
	Element *g6  = NULL; g6 = CreateElement(g6,'F');
	Element *g7  = NULL; g7 = CreateElement(g7,'G');
	Element *g8  = NULL; g8 = CreateElement(g8,'H');
	Element *g9  = NULL; g9 = CreateElement(g9,'I');
	Element *g10 = NULL; g10= CreateElement(g10,'J');
	Element *g11 = NULL; g11= CreateElement(g11,'K');
	Element *g12 = NULL; g12= CreateElement(g12,'L');
	

	g5->gauche = g10;
	g5->droit = g11;
	g4->gauche = g8;
	g4->droit = g9;
	g2->gauche = g4;
	g2->droit = g5;
	g1->gauche = g2;
	g1->droit = g3;
	g3->gauche = g6;
	g3->droit = g7;
	g6->gauche = g12;
	Racine = g1;

	
	printf("\n ============================= \n ");
	printf("\n Parcours Postfixe \n ");
	Postfixe(Racine);
	printf("\n Taille arbre G \n ");
	taille(Racine);
	printf("\n ============================= \n ");
	

	Element *h1  = NULL; h1 = CreateElement(h1,'A');
	Element *h2  = NULL; h2 = CreateElement(h2,'B');
	Element *h3  = NULL; h3 = CreateElement(h3,'C');
	Element *h4  = NULL; h4 = CreateElement(h4,'D');
	Element *h5  = NULL; h5 = CreateElement(h5,'E');
	Element *h6  = NULL; h6 = CreateElement(h6,'F');
	Element *h7  = NULL; h7 = CreateElement(h7,'G');
	Element *h8  = NULL; h8 = CreateElement(h8,'H');
	Element *h9  = NULL; h9 = CreateElement(h9,'I');
	Element *h10 = NULL; h10= CreateElement(h10,'J');
	Element *h11 = NULL; h11= CreateElement(h11,'K');
	Element *h12 = NULL; h12= CreateElement(h12,'L');

	h8->gauche = h9;
	h8->droit = h4;

	h9->gauche = h10;
	h9->droit = h11;
	h4->gauche = h5;
	h4->droit = h2;

	h10->gauche =h12;
	h10->droit = h6;
	h11->gauche = h7;
	h11->droit = h3;
	h5->gauche = h1;

	Racine = h8;
	printf("\n ============================= \n ");
	printf("\n Parcours en largeur \n ");
	Largeur(Racine);
	printf("\n Taille arbre H \n ");
	taille(Racine);
	printf("\n ============================= \n ");
	
    /*
    Element *k1  = NULL; k1 = CreateElement(k1,'A');
	Element *k2  = NULL; k2 = CreateElement(k2,'B');
	Element *k3  = NULL; k3 = CreateElement(k3,'C');
	
    k1->gauche = k2;
    k1->droit = k3;
    
    Racine = k1;*/
    MaxChemin(Racine);

    Arbre *parfait = gen_arbre_parfait(4);
    Largeur(parfait);

	
	return 0;
}
