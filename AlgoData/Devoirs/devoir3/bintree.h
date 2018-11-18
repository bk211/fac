#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct node_t node_t;
struct node_t{
	void * data;
	node_t * lc;
	node_t * rc;
};

void bt_print(node_t * bt, void (*print)(const void *));
void bt_add_value(node_t ** bt, void * data, size_t s,
	int (* compar)(const void *, const void *));
void bt_free(node_t **bt);