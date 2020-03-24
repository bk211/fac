#include <cstdio>
#include <cstdlib>
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

// 1. traverse the left subtree 2. traverse the right subtree 3. Visit the root 
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



int main()
{
	Element *Racine;
	Racine=NULL;
	/*
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
	printf("\n ============================= \n ");
	*/
	
	/*
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
	printf("\n ============================= \n ");
	*/

	/*
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
	printf("\n ============================= \n ");
	*/

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

	
	printf("\n ============================= \n ");
	printf("\n Parcours Postfixe \n ");
	Postfixe(Racine);
	printf("\n ============================= \n ");
    return 0;
}
