#include <stdio.h>

int main(int argc, char const *argv[])
{   


    int taille,i,j;
    for (i = 1; i <= argc-1; ++i)
    {        
        for ( taille = 0; argv[argc-i][taille]; ++taille);
    
        for (j = 0; j <= taille; ++j)
        {
            printf("%c",argv[argc-i][taille-j] );
        }
    
    }


    return 0;
}