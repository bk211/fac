#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {

    pid_t pid_fils;
    do{
        pid_fils = fork();
    }while( (pid_fils == -1)&& (errno == EAGAIN) );

    if(pid_fils == -1 ){
        perror("fork");
    }
    else if( pid_fils == 0){
        printf("Je suis le fils\n");
        printf("fils:%d\npere:%d\n",getpid(),getppid() );
    }else{
        printf("Je suis le pere\n");
        printf("fils:%d\npere:%d\n",pid_fils,getpid() );
    }

    return EXIT_SUCCESS;
}
