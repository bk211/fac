/*
* NOM : CHAOLEI
* NUMERO : 17812776
* EMAIL : CHAOLEICAI@GMAIL.COM
*/
#include "bintree.h"

void bt_print(node_t * bt, void (*print)(const void *)){
	if(bt){
		bt_print(bt->lc, print);
		print(bt->data);
		bt_print(bt->rc,print);
	}
	
}

void bt_add_value(node_t ** bt, void * data, size_t s,
	int (* compar)(const void *, const void *)){
	if(*bt){
		if(compar((*bt)->data, data) > 0)
			return bt_add_value( &((*bt)->lc), data, s, compar);
		return bt_add_value(& ((*bt)->rc), data, s, compar);
	}
	*bt = malloc (sizeof **bt);
	(*bt)->data = malloc(s); 
	assert(*bt);
	assert((*bt)->data);
	(*bt)-> lc = (*bt)->rc = NULL;
	memcpy((char*)(*bt)->data,(char*)data, s);
}

void bt_free(node_t **bt)
{
	if( (*bt)->lc){
		bt_free(&((*bt)->lc));
	}
	if( (*bt)->rc){
		bt_free(&((*bt)->rc));
	}

	free((*bt)->data);
	free(*bt);
	*bt=NULL;
}	