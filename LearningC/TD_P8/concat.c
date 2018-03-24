#include <stdio.h>
#include <stdlib.h>

char * concat (char *tab1, char *tab2, int n1,int n2){
    int i;
    char * res = malloc((n1+n2+1)*sizeof(*tab1));
    for (i = 0; i < n1; ++i)
    {
        res[i]= tab1[i];
    }
    for (i= n1; i <n1+n2 ; ++i)
    {
        res[i]=tab2[i-n1];
    }
    res[n1+n2]=0;
    return res;
}

int main(int argc, char const *argv[])
{
    char * x1 ="abc";
    char * x2 ="def";
    printf("%s\n",concat(x1,x2,3,3));
    return 0;
}