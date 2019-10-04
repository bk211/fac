#include <stdio.h>
#include <stdarg.h>

double fibo(int current_lv, ...);
double fibo2(int current_lv, ...);


int main(int argc, char const *argv[]) {

    //printf("%f\n", fibo(3, 0.0, 1.0));
    printf("%f\n", fibo(3));

    return 0;
}


double fibo(int current_lv, ...){
    va_list args;
    double b, a;
    va_start(args, current_lv);
        a = va_arg(args, double);
        b = va_arg(args, double);
        if(current_lv<1){
            va_end(args);
            return b;
        }
        b += a;
        a = b - a;

    va_end(args);

    return fibo(current_lv-1, a, b);
}

double fibo2(int current_lv,...){
    va_list args;
    va_start(args, current_lv);
    double a = va_arg(args,double);

    va_end(args);

    return a;
}

// 1 1 2 3 5
