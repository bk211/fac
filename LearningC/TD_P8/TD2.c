#include <stdio.h>
#include <assert.h>

float moy(float a, float b){
    float m = (a + b) / 2;
    return m;
}

int ent_flo(float a){
    int res = (int)a;
    return res;
}

int arr_flo(float a){
    return (int)(a+0.5);  
}

void permuter(){
    int a,b;
    a = 5; b = 2;
    printf("a contient %d et b contient %d\n", a,b);
    a ^= b ^= a ^= b;
    printf("a contient %d et b contient %d\n", a,b);
}

int factorielle(int n){
    if (n == 1) 
        return 1;
    else       
        return n * factorielle(n-1) ;     
}

int factorielle_term(int n,int p){
    if (n==0)
        return p;
    return factorielle_term(n-1, p*n);
}


int sommecarre(int n){
    if (n == 1) 
        return 1; 
    return n * n + sommecarre(n-1) ;     
}

int sommecarre_term(int n, int p){
    if (n == 0)
        return p;
    return sommecarre_term(n-1, p+ n*n);
}

int puiss(int n, int p){
    if (p == 0)
        return 1;
    else if (p == 1)
        return n;
    else
        return n * puiss(n, p-1);
} 

int puiss_term(int n, int p, int m){
    if (p == 0)
        return m;
    return puiss_term(n, p-1,m * n);
}


int sommepuiss(int n, int p){
    if (n == 0)
        return 1;
    else if (n == 1)
        return 1;
    else return puiss(n,p) + sommepuiss(n-1, p);
}

int sommepairs(int n){
    if (n == 0)
        return 0;
    else if (n % 2 == 0)
        return n *2 + sommepairs(n-1);
    else if (n % 2)
        return n*2 +sommepairs(n-1);
}

int fibo(int n){
    if (n == 0 )
        return 0;
    else if (n == 1)
        return 1;
    else 
        return fibo(n-1)+ fibo(n-2);
}


int main(int argc, char const *argv[])
{
    int tab[3]={1,2,5};
    int *p;
    p= tab;
    printf("%d %d \n",tab[1], *(p +2));
    return 0;
}