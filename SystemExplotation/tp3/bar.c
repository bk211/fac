#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * print_message_function(void *ptr);


int main(int argc, char *argv[] ){

    pthread_t t1, t2;
    char * message1 = "Thread 1";
    char * message2 = "Thread 2";
    int iret1, iret2;

    iret1 = pthread_create(&t1, NULL, print_message_function, (void*) message1);
    iret2 = pthread_create(&t2, NULL, print_message_function, (void*) message2);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("T1 returns: %d\n", iret1 );
    printf("T2 returns: %d\n", iret2 );

    return EXIT_SUCCESS;
}

void * print_message_function(void *ptr){
    char * message;
    message = (char*) ptr;
    printf("%s\n", message );
}
