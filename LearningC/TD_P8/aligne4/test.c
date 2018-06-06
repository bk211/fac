#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
          

void incrementer(int *a){
    (*a)++;
    printf("a= %d ds la fct\n",*a );
}

int tirage(int max){
    rand();
    return (double)(rand()/(double)(RAND_MAX) * (max+1));
}

int bla(int a){
    printf("%d\n",a );
    a--;
    printf("%d\n",a );
}
int main(int argc, char const *argv[]){

    srand((unsigned)time(NULL));
    int a = 3;
    bla(a);
    printf("%d\n",a );
}