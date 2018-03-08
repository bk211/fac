#include <stdio.h>

int main(int argc, char const *argv[])
{   
    int i,j;
    for (i = 1; i < argc; ++i)
    {
        for ( j = 0; j < 2; ++j)
        {
            printf("%s\n",argv[i] );
        }
    }
    return 0;
}