#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct flower flower_t;
struct flower
{
    char* name;
    int sepal_length;
    int sepal_width;
    int petal_length;
    int petal_width;
};

void fill_vector(int indice, flower_t * vec,int sl, int sw, int pl , int pw, char * n){
    vec[indice].sepal_length = sl;
    vec[indice].sepal_width  = sw;
    vec[indice].petal_length = pl;
    vec[indice].petal_width  = pw;
    vec[indice].name = n;   
}


int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("Usage: ./exec file_name\n");
        exit(1);
    }

    const char * fname = argv[1];
    printf("%s\n", fname);
    FILE * file = fopen(fname,"r");
    int size = 150;

    flower_t * vector_data = malloc(size*sizeof(flower_t));
    int *indice = malloc(size* sizeof(int));
    for (int i = 0; i < size; i++)
    {
        indice[i] = i;
    }
    int draw, tmp;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        draw = rand() % size;
        tmp = indice[i];
        indice[i] = indice[draw];
        indice[draw] = tmp;
    }
    
    float buff_sl, buff_sw, buff_pl, buff_pw;
    char comma;
    char buff_name[15];

    for (int i = 0; i < size; i++)
    {
        fscanf(file,"%f %c %f %c %f %c %f %c %s",&buff_sl, &comma, &buff_sw, &comma, &buff_pl, &comma, &buff_pw, &comma, buff_name);
        //printf("%d : %f, %f, %f, %f, %s\n",i, buff_sl,buff_sw,buff_pl,buff_pw, buff_name);
        fill_vector(i, vector_data, buff_sl, buff_sw, buff_pl, buff_pw, buff_name);
    }
    fclose(file);
    
    for (size_t i = 0; i < 150; i++)
    {
        printf("%s\n", vector_data[i].name);
    }
    
    
    return 0;
}
