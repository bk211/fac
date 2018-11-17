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