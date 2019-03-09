#include "isort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/*
//void triselction(void *base, size t nmemb, size t size, int(*compar)(const void *, const void *));
void triSelection(void * t, size_t nmemb, size_t taille_elem,int(*compar)(const void * a, const void * b) ) {
//void triSelection(int * t, int nmeb) {
    void * i;
    void * j;
    void * min;
    void * temp = NULL;
    for(i = 0; i < nmemb - 1; ++i) {
        min = t+ sizeof(taille_elem) *i;
        for(j = i + 1; j < nmemb; ++j){
//            if(t[j] < t[min])
            if(compar(t[i],t[min]) < 0)
                min = t+ sizeof(taille_elem)*j;
        }
        if(t+i != min) {
            temp = *(void**)t+i;
            *(void**)t+i = *(void**)min;
            *(void**)min = temp;
        }
 }
}*/

void isort(void * base, size_t nmemb, size_t size,int(*compar)(const void * a, const void * b) ) {
    int i, j ;
    void * v = malloc(size); assert(v); 
    for (i = 0; i < nmemb; ++i){
        v = memcpy(v, (char *)base + i*size, size);
        while(j >0 && compar((char *)base+(j-1)*size,v) > 0){
            memcpy((char*)base+j*size, (char*)base+(j-1)*size,size);
            --j;
        }
        memcpy((char*)base+j*size, v,size);
    }
    free(v);
}

int comparer(void const *a, void const *b)
{
   int const *pa = a;
   int const *pb = b;

   return *pa - *pb;
}


int main(int argc, char const *argv[])
{
/* code */
    int tab[] ={5,6,2,1};
    for (int i = 0; i < 4; ++i)
    {
        printf("%d\t",tab[i]);
    }
    isort(tab,sizeof(tab)/sizeof(int),(int),comparer);
    printf("\n");
    
    for (int i = 0; i < 4; ++i)
    {
        printf("%d\t",tab[i]);
    }
    return 0;
}