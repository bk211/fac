#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    int count = 0;
    int _char;
    char count_c[20];
    fp = fopen(argv[2],"r");
    for(_char =fgetc(fp); _char !=EOF || count_c < argv[1] ; _char = fgetc(fp)){
        printf("%c\n", _char);
        if(_char == '\n')
            count++;
        itoa(count, count_c,10)
    }




    fclose(fp);
    return 0;
}