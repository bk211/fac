#include <cstdio>
#include <cstdlib>

typedef struct element
{
	char data;
	int balance;
    struct element *gauche;
	struct element *droite;
}Element;
Element *createElement(char a)
{
	Element *newElement;
	newElement = new Element;
	newElement->data = a;
	newElement->balance = 0;
	newElement->gauche = NULL;
	newElement->droite = NULL;
	return newElement;
}
//Rotation droite
Element *rRot(Element  *A) 
{
	Element *B; 
	B = A->gauche;
	A->gauche = B->droite; 
	B->droite = A; // rotation 
	return B;
}
//Rotation Gauche
Element *lRot(Element *A) 
{
	Element  *B; 
	B = A->droite;
	A->droite = B->gauche; 
	B->gauche = A; // rotation 
	return B;
}
//Rotation droite puis gauche

Element *rlRot(Element *A) 
{
	A->droite = rRot(A->droite);
	return lRot(A);
}
//Rotation gauche puis droite
Element *lrRot(Element *A) 
{
	A->gauche = lRot(A->gauche);
	return rRot(A);
}


void PreFixe(Element * BT)
{
	if (BT!=NULL)
	{
		printf("%c[%d], ",BT->data, BT->balance);
		PreFixe(BT->gauche);	
		PreFixe(BT->droite);
	}
}

void insert(Element * Root, Element * V){
    if(Root == NULL){
        Root = V;
    }
    if(V->data < Root->data){
        if(Root->gauche == NULL){
            Root->gauche = V;
        }else{
            insert(Root->gauche,V);
        }
    }else{
        if(Root->droite == NULL){
            Root->droite = V;
        }else{
            insert(Root->droite,V);
        }
    }
}

int deep(Element * Root, int res){
    if(Root == NULL)
        return res;
	
	int g = deep(Root->gauche, res + 1);
	int d = deep(Root->droite, res + 1);
    return g > d? g : d;
}

void balance(Element * Root){
	if(Root == NULL)
		return;
	Root->balance = deep(Root->gauche,0) - deep(Root->droite, 0);
	balance(Root->gauche);
	balance(Root->droite);
}

Element * AVL(Element * Root){
	if(Root == NULL)
		return NULL;
	Root->gauche = AVL(Root->gauche);
	Root->droite = AVL(Root->droite);

	int g = 0, d = 0;
	if(Root->gauche)
		g = Root->gauche->balance;
	if(Root->droite)
		d = Root->droite->balance;

	if(Root->balance == -2 && d == -1){//gauche
		Root = lRot(Root);
		balance(Root);
	}

	if(Root->balance ==2 && g == 1){//droite
		Root = rRot(Root);
		balance(Root);
	}

	if(Root->balance == -2 && d == 1){//droite gauche
		Root = rlRot(Root);
		balance(Root);
	}	
	
	if(Root->balance == 2 && g == -1){//gauche droite
		Root = lrRot(Root);
		balance(Root);
	}

	return Root;
}

Element * get_max_left(Element * Root){
	if(Root->droite)
		return get_max_left(Root->droite);
	return Root;
}

Element * suppress(Element * Root, char v){
	if(Root == NULL)
		return NULL;
	if(Root->data != v){
		if(v < Root->data){
			Root->gauche = suppress(Root->gauche, v);
		}else{
			Root->droite = suppress(Root->droite, v);
		}
		
	}else{
		if(Root->gauche == NULL && Root->droite == NULL){
			return NULL;
		}else if(Root->gauche == NULL){
			return Root->droite;
		}else if(Root->droite == NULL){
			return Root->gauche;
		}else{
			Element * new_Root = get_max_left(Root->gauche);
			new_Root->gauche = suppress(Root->gauche, new_Root->data);
			new_Root->droite = Root->droite;
			return new_Root;
		}
	}
	
	return Root;
}

int verify_AVL(Element * Root){
	if(Root == NULL)
		return 1;
	
	int v = Root->balance;
	if(v > 1 || v < -1)
		return 0;
	
	return verify_AVL(Root->gauche) && verify_AVL(Root->droite);
	
}

int main()
{
	Element *Root;
	int k =0;
    Root = NULL;
	
	
	Element *e1;e1=createElement('E');
	Element *e2;e2=createElement('C');
	Element *e3;e3=createElement('G');
	Element *e4;e4=createElement('B');
	Element *e5;e5=createElement('D');
		
	//		 e1            E
	//		/  \          / \
	//	   e2   e3       C   G
	//	  /  \          / \
    //   e4  e5        B   D
	// Prefixe : ECBDG
	//Rotation droite sur E donne l'arbre suivant :
   //	   C
   //	  / \
  //	 B   E
//		    / \
//	       D   G
// Prefixe : CBEDG
// Rotation gauche sur C
	
//	     E
//      / \
//	   C   G
//    / \
//   B   D 
	
	
	//Element *e4;e4=createElement();
	//Element *e5;e5=createElement('C');
	Root = e1;
	
	e1 ->gauche = e2;
	e1 ->droite = e3;
	
	e2 ->gauche = e4;
	e2 ->droite = e5;
		
	//e4 ->leftChild = e6;
	//e4 ->rightChild = e7;

	Root = e1;
	
	printf("\n Demonstration without factor balance \n");
	printf(" ------------------------------------ \n");
	printf("\nBefore rotation\n");
	PreFixe(Root);
	 
	Root = rRot(Root);
	printf("\n Right rotation \n");
    PreFixe(Root);
	
	Root = lRot(Root);
	printf("\n Left rotation on the right rotation \n");
    PreFixe(Root);
	
	//Root = lRot(Root);
	//printf("\n Left Rotation \n");
    //PreOrder(Root);
	printf("\n\n");
	


	printf("\n Demonstration for AVL \n");
	printf(" ------------------------------------ \n");

		
	Element *f1;f1=createElement('D');
	Element *f2;f2=createElement('F');
	Element *f3;f3=createElement('Y');
	//		 f1            D
	//		  \            \
	//	      f2            F
	//	       \             \
    //         f3             Y
	// Prefixe : DFY 
	//Rotation droite sur E donne l'arbre suivant :
	// FDY
//	     F
//      / \
//	   D   Y

	Root = f1;
	f1->droite = f2;
	f2->droite = f3;
	
	balance(Root);
	printf("\nBefore AVL left\n");
    PreFixe(Root);
	printf("\nAfter AVL left\n");
	Root = AVL(Root);
    PreFixe(Root);	
	
	


	// figure 6 du cours
	Element *g1;g1=createElement('Y');
	Element *g2;g2=createElement('F');
	Element *g3;g3=createElement('D');
	Root = g1;
	g1->gauche = g2;
	g2->gauche = g3;
	
	
	balance(Root);
	printf("\n\nBefore AVL right\n");
    PreFixe(Root);
	printf("\nAfter AVL right\n");
	Root = AVL(Root);
    PreFixe(Root);

	
	//figure 10 du cours
	Element *h1;h1=createElement('B');
	Element *h2;h2=createElement('A');
	Element *h3;h3=createElement('E');
	Element *h4;h4=createElement('D');
	Element *h5;h5=createElement('H');
	Element *h6;h6=createElement('C');
	
	Root = h1;
	h1->gauche = h2;
	h1->droite = h3;
	h3->gauche = h4;
	h3->droite = h5;
	balance(Root);
	printf("\n\nBefore insert C\n");
    PreFixe(Root);
	printf("\nAfter insert C\n");
	insert(Root,h6);
	balance(Root);
	PreFixe(Root);
	printf("\nAfter AVL right left\n");
	Root = AVL(Root);
    PreFixe(Root);
	
	//figure 14 du cours
	Element *i1;i1=createElement('H');
	Element *i2;i2=createElement('E');
	Element *i3;i3=createElement('C');
	Element *i4;i4=createElement('B');
	Element *i5;i5=createElement('A');
	Element *i6;i6=createElement('D');
	Element *i7;i7=createElement('G');
	Element *i8;i8=createElement('F');
	Element *i9;i9=createElement('K');
	Element *i10;i10=createElement('J');
	Element *i11;i11=createElement('I');
	Element *i12;i12=createElement('L');
	
	i1->gauche = i2;
	i1->droite = i9;

	i2->gauche = i3;
	i2->droite = i7;
	i7->gauche = i8;

	i3->gauche = i4;
	i3->droite = i6;
	i4->gauche = i5;
	i9->gauche = i10;
	i9->droite = i12;
	i10->gauche = i11;
	Root = i1;
	balance(Root);
	printf("\n\nBefore insert C\n");
    PreFixe(Root);
	printf("\nAfter supress H\n");
	Root = suppress(Root, 'H');
	balance(Root);
	PreFixe(Root);
	printf("\nAfter Rebalance\n");
	Root = AVL(Root);
	balance(Root);
	PreFixe(Root);
	
	printf("\nValide AVL: %d\n", verify_AVL(Root));
	
	
	return 0;


}


