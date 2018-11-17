#include "bintree.h"

void bt_print(node_t * bt, void (*print)(const void *)){
//void bt_print(node_t *bt){
	if(bt){
		bt_print(bt->lc, print);
		//printf("%d, ",bt->v );
		print(bt->data);
		bt_print(bt->rc,print);
	}
	
}

void bt_add_value(node_t ** bt, void * data, size_t s,
	int (* compar)(const void *, const void *)){
//void bt_add_value(node_t **bt,int v){
	if(*bt){
		if(compar((*bt)->data, data) < 0)
		//if(v < (*bt)->v)
			return bt_add_value( &((*bt)->lc), data, s, compar);
		return bt_add_value(& ((*bt)->rc), data, s, compar);
	}

	*bt = malloc (sizeof **bt);
	assert(*bt);
	(*bt)-> lc = (*bt)->rc = NULL;
	//(*bt)->v=v;
	memcpy((*bt)->data, (char *)data, s);
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

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}