#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * thread_1(void *arg){
    printf("Nous somme dans le thread.\n");
    pthread_exit(NULL);
}


int main(int argc, char *argv[] ){
    pthread_t thread1;
    printf("Avant la creation du thread.\n");
    if(pthread_create(&thread1, NULL, thread_1, NULL) == -1){
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    pthread_join(thread1,NULL);
    printf("Apres la creation du thread.\n");
    return EXIT_SUCCESS;
}
