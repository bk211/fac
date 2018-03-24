#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    int c;
    fp= fopen("faiz.txt","r");
    while(1){
        c = fgetc(fp);
        if( feof(fp)){
            break;
        }
        printf("%c",c );
    }
    fclose(fp);
    return 0;
}