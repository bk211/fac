#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int echanger(int x, int y){
	int z = x;
	x = y;
	y = z;
}

int echanger2(int* x, int* y){
	int z = *x;
	*x = *y;
	*y = z;
}

typedef struct noeud noeud;
struct noeud{
	int v;
	struct noeud * next;
};

void insert(int a, noeud ** plc){
	*plc = malloc (1 * sizeof **plc);
	(*plc)->v = a;
	(*plc)->next = NULL;
}

noeud** insert2(int a, noeud ** last){
	noeud * old = *last;
	*last = malloc (1 * sizeof **last);
	assert(*last);
	(*last)->v = a;
	(*last)->next = old;
	return &((*last)->next);
}

void print(noeud* l){
	if(l){
		print(l->next);
		printf("%d\n",l->v );
	}

}

void liberer(noeud *t){
	noeud *tmp;
	while(t){
		tmp =t->next;
		free(t);
		t = tmp;
	}
}

void liberer2(noeud **pl){
	noeud * tmp, *l = *pl
	while(*pl){
		tmp = l->next;
		free(l);
	}
	l = tmp;
	opl = NULL;
}

int main(void){
	int a =1, b = 2;
	echanger(a,b);
	//printf("%d %d\n",a,b ); // 1 2

	echanger2(&a,&b);
	//printf("%d %d\n",a,b ); // 2 1
	
	int t[] = {4,2,1,3,5},i;
	noeud * lc = NULL, **last=&lc;
	for (i = 0; i < sizeof t/ sizeof *t ; ++i){
		//insert(t[i],&lc);
		last =insert2(t[i],&lc);
	}
	print(lc);
	return 0;
}