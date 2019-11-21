#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
    printf("%d >>Pere\n", getpid() );
    pid_t fils = fork();

    if(fils == 0){
        printf("Je suis le fils %d, le pere est %d\n",getpid(), getppid() );
    }
    else{
        pid_t fille = fork();
        if(fille == 0){
            printf("Je suis la fille %d, le pere est %d\n",getpid(), getppid() );
        }else{
            printf("Je suis le pere %d\n",getpid() );
        }
    }
    return EXIT_SUCCESS;
}
