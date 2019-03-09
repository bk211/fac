#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct node_t node_t;
struct node_t{
	int v;
	node_t * lc;
	node_t * rc;
};

void bt_print(node_t *bt){
	if(bt){
		bt_print(bt->lc);
		printf("%d, ",bt->v );
		bt_print(bt->rc);
	}
	
}

void bt_add_value(node_t **bt,int v){
	if(*bt){
		if(v < (*bt)->v)
			return bt_add_value( &((*bt)->lc),v);
		return bt_add_value(& ((*bt)->rc),v);
	}

	*bt = malloc (sizeof **bt);
	assert(*bt);
	(*bt)-> lc = (*bt)->rc = NULL;
	(*bt)->v=v;
}

void bt_free(node_t **bt)
{
	if( (*bt)->lc){
		bt_free(&((*bt)->lc));
	}
	if( (*bt)->rc){
		bt_free(&((*bt)->rc));
	}

	free(*bt);
	
}	

int bt_add_value_iter(node_t **bt,int v){
	while(*bt)
	{
		if(v < (*bt)->v)
			bt = &((*bt)->lc);
		else
			bt = &((*bt)->rc);
	}
	*bt = malloc (sizeof **bt);
	assert(*bt);
	(*bt)-> lc = (*bt)->rc = NULL;
	(*bt)->v=v;	
}



int main(int argc, char const *argv[])
{
	node_t *ab = NULL;
	bt_print(ab);
	//printf("dajiwo\n" );
	int tab[20];
	int i;
	for (i = 0; i < 20; ++i)
	{	
		tab[i]=i;
		//bt_add_value(&ab,tab[i]);
		bt_add_value_iter(&ab,tab[i]);
		
	}

	bt_print(ab);
	bt_free(&ab);
	bt_print(ab);
	return 0;
	/*
comparer l insert dans AB avec insert dans la L.C et tableau en rajoutant l'AB dans l'axe de comparatif 1.0tgz
	*/
}
