#include <cstdio>
#include <cstdlib>

typedef struct Element Element; 
struct Element
{
	char data;
	Element *gauche ;
	Element *droit  ;
};
/* Parcours en largeur :
*/


Element *CreateElement(Element *Root, char value)
{
	Root=new Element;
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

// Fonction de recherche d'un élément dans l'arbre - Exo 
int rechercher(Element *Racine, char V)
{
	if (Racine!=NULL)
	{
		if (Racine->data == V) 
			return 1;
	    else
		{
			if (Racine->data < V) 
				return (rechercher(Racine->gauche, V));
			else 
				return (rechercher(Racine->droit, V));
		}
	}
	else 
		return 0;
}		    

void insert(Element * Root, Element * V){
    if(Root == NULL){
        Root = V;
    }
    if(V->data <= Root->data){
        if(Root->gauche == NULL){
            Root->gauche = V;
        }else{
            insert(Root->gauche,V);
        }
    }else{
        if(Root->droit == NULL){
            Root->droit = V;
        }else{
            insert(Root->droit,V);
        }
    }
}

Element * get_max_left(Element * Root){
	if(Root->droit)
		return get_max_left(Root->droit);
	return Root;
}

Element * suppress(Element * Root, char v){
	if(Root == NULL)
		return NULL;
	if(Root->data != v){
		if(v < Root->data){
			Root->gauche = suppress(Root->gauche, v);
		}else{
			Root->droit = suppress(Root->droit, v);
		}
		
	}else{
		if(Root->gauche == NULL && Root->droit == NULL){
			return NULL;
		}else if(Root->gauche == NULL){
			return Root->droit;
		}else if(Root->droit == NULL){
			return Root->gauche;
		}else{
			Element * new_Root = get_max_left(Root->gauche);
			new_Root->gauche = suppress(Root->gauche, new_Root->data);
			new_Root->droit = Root->droit;
			return new_Root;
		}
	}
	
	return Root;
}

Element * suppress_greatest(Element * Root){
	if(Root == NULL)
		return NULL;
	
	if(Root->droit){
		Root->droit = suppress_greatest(Root->droit);
	}else{
		Root = Root->gauche;
	}

	return Root;
}

Element * suppress_smallest(Element * Root){
	if(Root == NULL)
		return NULL;
	
	if(Root->gauche){
		Root->gauche = suppress_greatest(Root->gauche);
	}else{
		Root = Root->droit;
	}

	return Root;
}

int compare(Element * r1, Element * r2){
	if(r1 == NULL && r2 == NULL)
		return 1;
	
	if(r1 != NULL && r2 == NULL)
		return 0;

	if(r1 == NULL && r2 != NULL)
		return 0;
	
	if(r1->data != r2->data)
		return 0;
	
	if(r1->data == r2->data)
		return compare(r1->gauche, r2->gauche) && compare(r1->droit, r2->droit);
	
	return 0;

}

// cheche l'arbre contient un valeur superieur a v
int lesser(Element * Root, char v){
	if(Root == NULL)
		return 0;
	if(Root->data > v)
		return 1;
	return lesser(Root->gauche, v) && lesser(Root->droit, v);
}

// cheche l'arbre contient un valeur inferieur a v
int greater(Element * Root, char v){
	if(Root == NULL)
		return 0;
	if(Root->data < v)
		return 1;
	return greater(Root->gauche, v) && greater(Root->droit, v);
}

int verify(Element * Root){
	if(Root == NULL)
		return 1;
	
	if(lesser(Root->gauche, Root->data) || greater(Root->droit, Root->data))//pas de valeur superieur a gauche, inferieur a droite par rapport a root->data
		return 0;
	return verify(Root->gauche) && verify(Root->droit);
}


int main()
{
	 Element *Racine;
	 Racine=NULL;
	 
	 Element *e1; e1 = CreateElement(e1,'A');
	 Element *e2; e2 = CreateElement(e2,'B');
	 Element *e3; e3 = CreateElement(e3,'C');
	 Element *e4; e4 = CreateElement(e4,'D');
	 Element *e5; e5 = CreateElement(e5,'E');
	 Element *e6; e6 = CreateElement(e6,'F');
	 Element *e7; e7 = CreateElement(e7,'G');
	 Element *e8; e8 = CreateElement(e8,'H');
	 Element *e9; e9 = CreateElement(e9,'I');
	 Element *e10;e10 = CreateElement(e10,'J');
	 Element *e11;e11 = CreateElement(e10,'K');
	 
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
	printf("\n Parcours préfixe \n ");
	PreFixe(Racine);
	printf("\n ============================= \n ");

	if (rechercher(Racine, 'Y')==1)
		printf("\n L'element recherche existe \n \n ");
	else {
		printf("\n L'element recherche n'existe pas\n \n");
	}
	printf("\n Apres l'insertion de K \n ");
	printf("============================= \n ");
	insert(Racine, e11);
	PreFixe(Racine);

	printf("\n Apres suppression de J \n ");
	printf("============================= \n ");
	Racine = suppress(Racine,'J');
	PreFixe(Racine);
	
	printf("\n Apres suppression du plus grand (le plus a droite e11 ou K) \n ");
	printf("============================= \n ");
	Racine = suppress_greatest(Racine);
	PreFixe(Racine);
	
	printf("\n Apres suppression du plus grand (le plus a droite e7 ou G) \n ");
	printf("============================= \n ");
	Racine = suppress_smallest(Racine);
	PreFixe(Racine);
	
	Element *f1; f1 = CreateElement(f1,'A');
	Element *f2;f2 = CreateElement(f2,'B');
	Element *f3;f3 = CreateElement(f3,'C');
	 
	f2->gauche = f1;
	f2->droit = f3;
	

	printf("\n arbre bis :\n ");
	PreFixe(f2);	

	if (compare(Racine, f2)==1)
		printf("\n Les 2 arbres sont egaux \n \n ");
	else {
		printf("\n Les 2 arbres ne sont pas egaux\n \n");
	}
	
	if (compare(Racine, Racine)==1)
		printf("\n comparaison avec lui meme == 1 \n \n ");
	
	if (verify(Racine)==0){
		printf("\n L'arbre e n'est pas ABR\n ");
	}
	
	
	if (verify(f2)==1){
		printf("\n L'arbre f est ABR\n \n");
	}

	
	return 0;	
}
