#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <assert.h>
const int vec_size = 150;//taille vecteur
//const int vec_size = 4;//qte data par vecteur
//const int neu_size = 60;//qte de neuronne
//const double random_ponderation_upper = 0.025;
//const double random_ponderation_lower = -0.05;
//-0.05 +0.025

typedef struct flower flower_t;
struct flower
{
    char *name;
    double * data;
};

/*
void fill_vector(int indice, flower_t * vec, double * data, int datasize, char * n){
    
    vec[indice].data = malloc(vec_size * sizeof(double));

    for (int i = 0; i < datasize; i++)
    {
        vec[indice].data[i] = data[i];
    }
    
    vec[indice].name = malloc(15*sizeof(char));
    strcpy(vec[indice].name, n);
}*/


/*
double get_moyenne(flower_t * vec, int col_number, int size){
    double ret = 0;
    for (int i = 0; i < size; i++)
    {
        ret += vec[i].data[col_number];
    }
    ret /= size;
    return ret;
}*/

/*
double get_norme(flower_t * vec, int col_number, int size){
    double ret = 0;
    for (int i = 0; i < size; i++){
        ret += vec[i].data[col_number] * vec[i].data[col_number];
    }
    ret = sqrt(ret);
    return ret;
}
*/

/*
void normalise(flower_t * vec, int size, flower_t * ret){
    double tab_norme[vec_size];
    for (int i = 0; i < vec_size; i++)
    {
        tab_norme[i] = get_norme(vec, i , size);
    }

    for (int i = 0; i < size; i++)
    {
        ret[i].data = malloc(vec_size * sizeof(double));
        for (int j = 0; j < vec_size; j++)
        {
            ret[i].data[j] = vec[i].data[j]/ tab_norme[j];
        }


        ret[i].name = malloc(15*sizeof(char));
        assert(ret[i].name);
        strcpy(ret[i].name, vec[i].name);
    }

}
*/


/*
double get_random_ponderation(){
    double range = random_ponderation_upper - random_ponderation_lower;
    double result = 1 + (double) rand() / (double) RAND_MAX * range - fabs(random_ponderation_lower);
    return result;
}
*/

/*
flower_t * create_neuronne(flower_t vec_moyen, int vec_size){

    flower_t * result = (flower_t *) malloc( (neu_size % 10) * sizeof(flower_t));
    

    for (size_t i = 0; i < size; i++)
    {
        result[i].data = (double*) malloc( vec_size * sizeof(double));
        for (size_t j = 0; j < vec_size; j++)
        {
            result[i].data[j] = vec_moyen.data[j] * get_random_ponderation();
        }
        
    }
    
    return result;
}
*/

/*
double compare_neuronne(flower_t f1, flower_t f2){
    double result = 0;
    for (size_t i = 0; i < vec_size; i++)
    {
        result += sqrt( (f1.data[i] - f2.data[i]) * (f1.data[i] - f2.data[i]) );
    }
    
    return result;
}
*/

int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("Usage: ./exec file_name\n");
        exit(1);
    }

    const char * fname = argv[1];
    //size_t buffer_size = 27;
    printf("%s\n", fname);
    //FILE * file = fopen(fname,"r");

    //flower_t * vector_data = malloc(size*sizeof(flower_t));
    //flower_t * normalized_vector_data = malloc(size*sizeof(flower_t));
    
    int *indice = malloc(vec_size* sizeof(int));
    
    
    //genese tableau randomisation
    for (int i = 0; i < vec_size; i++){
        indice[i] = i;
    }
    int draw, tmp;

    srand(time(NULL));
    for (int i = 0; i < vec_size; i++){
        draw = rand() % vec_size;
        tmp = indice[i];
        indice[i] = indice[draw];
        indice[draw] = tmp;
    }
    

    /*

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

    normalise(vector_data, size, normalized_vector_data);

    flower_t vec_moyen;//vecteur contenant les valeurs moyennes
    vec_moyen.name = "???";
    vec_moyen.data = malloc(vec_size * sizeof(double));
    for (int i = 0; i < vec_size; i++)
    {
        vec_moyen.data[i] = get_moyenne(normalized_vector_data, i, size);
        //printf("%f ,", vec_moyen.data[i]);
    }
    
    flower_t * neuronnes = create_neuronne(vec_moyen, vec_size);
    
    printf("%f", neuronnes[0].data[3]);
    */


        
    return 0;
}