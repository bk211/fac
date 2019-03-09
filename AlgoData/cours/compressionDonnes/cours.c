#include <stdio.h>
#include <strlib.h>

typedef struct node_t node_t;
struct node_t{
	int c, occ;
	struct node_t * b0,b1;
};



int * histogramme(unsigned char * str){
	int * h;
	h = calloc( 256, sizeof *h);// calloc met 0 dans cq case
	assert(h);
	while(*str){
		h[*str]++;
		++str;
	}
	return h;

}

int main(){
  
}
