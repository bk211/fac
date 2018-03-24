#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *rii;
    int c;
    rii= fopen("faiz.txt","w+");
    fprintf(rii, "%s\n","riiiiiiiiiiiiii" );
    fclose(rii);
    return 0;
}