#include <stdio.h>
#include <stdarg.h>

int fib(int current_lv, ...);

int main(int argc, char const *argv[]) {
    int i, rang = 10;
    for ( i = 0; i < rang; i++) {
        printf("n = %d  >>> Xn = %d \n",i, fib(i) );
    }
    return 0;
}


int fib(int current_lv,...){
    va_list args;
    int a,b;
    va_start(args, current_lv);
        int ready = va_arg(args,int);
        if(ready){//si la fct n'est pas initialise, on initialise
            va_end(args);
            a = 0;
            b = 1;
            return fib(current_lv, 0, a, b);
        }
        else{
            a = va_arg(args, int);
            b = va_arg(args, int);
            va_end(args);
            if (current_lv == 0){// cas stop 0
                return a;
            }else if (current_lv == 1) { // cas stop 1
                return b;
            }
            else{//appel reccursif
                return fib(current_lv - 1, 0, b, a+b);
            }

        }
}
