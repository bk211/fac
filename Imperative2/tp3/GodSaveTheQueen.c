#include <stdio.h>
#include <setjmp.h>
#include <assert.h>
#include <unistd.h>
#include <signal.h>

struct vec_int{
    int nbele;
    int * v;
}
typedef struct vec_int vec_int_t;

vec_int_t v;
void afficharec(vec_int_t w){
    int i;
    for ( i = 0; i < nbele; i++) {
        printf("%d\n", w.w[i]);
        printf("\n", );
    }
}

void sig_handler(int signo){
    int i;
    FILE * fic;
    if (signo == SIGINT) {
        printf("recu SIGINT\n");
        fic = fopen("FIB.txt", "a");
        for (i = 0; i < v.nbele; i++) {
            fprintf(fic, "%d\n",w.vpi );
            fprintf(fic, "%s\n");
            fclose(fic);
        }
    }
}

int main(int argc, char const *argv[]) {
    int a, b, q;

    return 0;
}
