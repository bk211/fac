#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct flower flower_t;
struct flower
{
    char* name;
    double sepal_length;
    double sepal_width;
    double petal_length;
    double petal_width;
};

void fill_vector(int indice, flower_t * vec,int sl, int sw, int pl , int pw, char * n){
    vec[indice].sepal_length = sl;
    vec[indice].sepal_width  = sw;
    vec[indice].petal_length = pl;
    vec[indice].petal_width  = pw;
    strcpy(vec[indice].name, n); 
}


int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("Usage: ./exec file_name\n");
        exit(1);
    }

    const char * fname = argv[1];
    size_t buffer_size = 27;
//    printf("%s\n", fname);
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
    
    
    printf("out");
    double buffer_data[4];
    char * line = (char *) malloc(buffer_size* sizeof(char));
    char * data_tmp;
    char *buffer_name = NULL;
    for (size_t i = 0; i < 150; i++)
    {
        getline(&line, &buffer_size, file);
        data_tmp = strtok(line, ",");
        for (int j = 0; j < 4; j++)
        {
            buffer_data[j] = strtod( data_tmp,NULL);
            data_tmp = strtok(NULL, ",");
        }
        strcpy(buffer_name,data_tmp);
        data_tmp = strtok(NULL, ",");
    //    fill_vector(i, vector_data, buffer_data[0], buffer_data[1], buffer_data[2], buffer_data[3],buffer_name);
      
    }
    printf("out");

    fclose(file);
    
    
    return 0;
}
