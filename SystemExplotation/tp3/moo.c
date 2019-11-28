#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * fsomme (void * arg);
void * fproduit (void * arg);

int main(int argc, char const *argv[]) {
    int i;
    pthread_t tab_pth[2];
    char * temp;
    temp = (char*) malloc(sizeof(int) + sizeof(char));
    sprintf(temp, "%d",5);

    void* (*tab[2])(void*) = {fsomme, fproduit};

    for ( i = 0; i < 2; i++) {
        if(pthread_create(&tab_pth[i], NULL, (*tab[i]), (void*) temp) == -1){
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    for ( i = 0; i < 2; i++) {
        pthread_join(tab_pth[i],NULL);
    }

/*
    if(pthread_create(&fils1, NULL, fsomme, (void*) temp) == -1){
        perror("pthread_create");
        return EXIT_FAILURE;
    }
    if(pthread_create(&fils2, NULL, fproduit,(void*) temp) == -1){
        perror("pthread_create");
        return EXIT_FAILURE;
    }
*/
    printf("Sortie du main \n");
    pthread_exit(0);
    //exit(0)
    return 0;
}

void * fsomme (void * arg){
    int i, somme = 0;
    int n= atoi((char*) arg);
    for (i = 0; i <= n ; i++) {
        somme += i;
    }
    printf("Somme = %d\n", somme );
    pthread_exit(0);

}

void * fproduit (void * arg){
    int i, produit =1;
    int n= atoi((char*) arg);

    for (i = 1; i <= n ; i++) {
        produit *= i;
    }
    printf("Produit = %d\n", produit);
    pthread_exit(0);

}

void * start_fsomme_fproduit( void* arg){


}
