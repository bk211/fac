#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
const int size = 150;//taille vecteur
const int vec_size = 4;//qte data par vecteur

typedef struct flower flower_t;
struct flower
{
    char *name;
    double * data;
};

void fill_vector(int indice, flower_t * vec, double * data, int datasize, char * n){
    
    vec[indice].data = malloc(vec_size * sizeof(double));

    for (int i = 0; i < datasize; i++)
    {
        vec[indice].data[i] = data[i];
    }
    
    vec[indice].name = malloc(15*sizeof(char));
    strcpy(vec[indice].name, n);
}


double get_moyenne(flower_t * vec, int col_number){
    double ret = 0;
    for (int i = 0; i < size; i++)
    {
        ret += vec[i].data[col_number];
    }
    ret /= size;
    return ret;
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

    flower_t * vector_data = malloc(size*sizeof(flower_t));
    int *indice = malloc(size* sizeof(int));
    

    //genese tableau randomisation
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
    

    char * line = (char *) malloc(buffer_size* sizeof(char));
    double buffer_data[4];
    char * data_tmp;
    char *buffer_name = NULL;
    for (int i = 0; i < size; i++)
    {
        getline(&line, &buffer_size, file);
        //printf("%s",line);
        data_tmp = strtok(line, ",");
        for (int j = 0; j < 4; j++)
        {
            buffer_data[j] = strtod( data_tmp,NULL);
            data_tmp = strtok(NULL, ",");
        }
        //printf("%lf %lf %lf %lf ", buffer_data[0], buffer_data[1], buffer_data[2], buffer_data[3]);
        buffer_name = data_tmp;
        //printf("%s\n", buffer_name);
        fill_vector(i, vector_data, buffer_data, vec_size, buffer_name);
      
    }

    fclose(file);
    /*for (int i = 0; i < 150; i++)
    {
        printf("%f ",vector_data[i].data[0]);
        printf("%f ",vector_data[i].data[1]);
        printf("%f ",vector_data[i].data[2]);
        printf("%f \n",vector_data[i].data[3]);
        printf("%s \n",vector_data[i].name);
    }*/

    double moyennes[vec_size];//vecteur de moyenne
    for (int i = 0; i < vec_size; i++)
    {   
        moyennes[i] = get_moyenne(vector_data, i);
        printf(">%f \n", moyennes[i]);
    }
    


        
    return 0;
}
