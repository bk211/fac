#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char const *argv[]) {
    fork();
    fork();
    fork();

    printf("Je suis le processus :%d\n",getpid()  );

    exit(0);
}
