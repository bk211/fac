#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    int i,nb_char=0, nb_mots=0, nb_ligne=0;
    
    fp = fopen("charac.txt","r");
    for (i =fgetc(fp); i != EOF; i = fgetc(fp))
    {
        if(i >='A' && i <= 'z')
            nb_char++;
        else if(i == '\n'){
            nb_ligne++;
            nb_mots++;
        }

        else if(i==' '){
            for (; i ==' '; i=fgetc(fp)){}
            nb_mots++;
        }
    }

    nb_ligne++;nb_mots++;nb_char++;    

    fclose(fp);
    printf("\n%d %d %d\n", nb_char,nb_mots,nb_ligne);

    return 0;
}