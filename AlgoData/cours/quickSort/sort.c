#include <stdio.h>
#include "sort.h"
#define N 10
//sinon pr utiliser la grainesrand(time(NULL))
//#include <time.h>
#include <stdlib.h> // ou se trouve qsort()
void qsort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *)){

};

int foo(const void *a, const void *b){
	/*if(a == b) return 0;
	if(a < b) return -1;
	return 1;*/
	//sinon
	return (*(int*)a) - (*(int*)b);
}

int main(int argc, char const *argv[])
{
	int t[N],i;
	for (i = 0; i < N; ++i)
	{
		t[i] = rand();
		printf("%d\n",t[i] );
	}
	qsort(t,sizeof t/ sizeof *t, sizeof *t, foo);
	//sizeof t/ sizeof *t == N  taille du tableau
	return 0;
}