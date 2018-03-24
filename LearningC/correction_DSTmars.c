#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    return 0;
}

int sommerec(int n){
    if(!n)
        return 0;
    return sommerec(n-1)+2*n;
}

int sommerec_ter(int n,int acc){
    if(!n)
        return acc;
    return sommerec_ter(n-1,acc+2*n);

}

int sommeiter(int n){
    int acc=0;
    while(n!=0){
        acc+2*n;
        n--;
    }
    return acc;
}

int foo(int bar, int baz){
    int i;
    int ret = bar;
    for (i = 0; i <=baz ; ++i)
    {
        if(ret % 2 ==0)
            ret = ret /2;
        else
            ret =3*ret+1;

    }
    return ret;
}


float moyennepairs(float tab[], int taille){
    int moyenne =0
    for (int i = 0; tab[i]; ++i)
    {
        if(!tab[i]%2)
            moyenne += tab[i]
    }
    moyenne /=taille;
    return moyenne;

}


void et(int n){
    int i,e=0,j;
    for (i = n; i >0; i -=2)
    {
        for (int j = 0; j < e; ++j)
        {
            printf(" ", );
        }
        for (int j = 0; j < i; ++j)
        {
            printf("*");
        }
        printf("\n");
        e++;
    }
}

