#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

pid_t Creation_process(void){
    pid_t pid_fils;
    do{
        pid_fils = fork();
    }while((pid_fils == -1) && (errno == EAGAIN));

    return pid_fils;

}

void Process_FiLs(void){
    printf("Je suis le fils %d, mon pere est %d \n", getpid(), getppid());
}


void Process_PeRe(int Fils_pid){
    printf("Je suis le pere %d \n",getpid());
    if(wait(NULL) == -1){
        perror("wait:");
    }
}


int main(int argc, char const *argv[]) {

    pid_t pid_fils = Creation_process();

    switch (pid_fils) {
        case -1:
            perror("fork error");
            break;
        case 0:
            Process_FiLs();
            break;
        default:
            Process_PeRe(pid_fils);
    }
    return EXIT_SUCCESS;
}
