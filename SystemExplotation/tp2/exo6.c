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

int main(int argc, char const *argv[]) {

    pid_t pid_fils = Creation_process();

    switch (pid_fils) {
        case -1:
            perror("fork error");
            break;
        case 0: // dans le fils
            printf("fork = %d | Je suis le fils %d, mon pere est %d \n", pid_fils,getpid(), getppid());
            execlp("ls", "ls", (char*) NULL);
            sleep(4);

            exit(2);

            break;//jamais atteint

        default:// dans le pere
            printf("fork = %d | Je suis le pere %d, mon pere est %d \n", pid_fils, getpid(), getppid());
            execlp("ps", "ps", "-l",(char*) NULL);
            int code = wait(NULL);
            printf("Fin du wait, code de retour = %d\n",code );

    }
    return EXIT_SUCCESS;
}
