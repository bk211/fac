#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <assert.h>
const int vec_size = 150;//taille vecteur
size_t buffer_size = 27;

const int vec_att_size = 4;//qte data par vecteur
const int neu_size = 60;//qte de neuronne
const double random_ponderation_max = 1.025;
const double random_ponderation_min = 0.95;
const int neu_sizeX = 10;
const int neu_sizeY = 6;

//-0.05 +0.025


typedef struct flower flower_t;
struct flower
{
    int type;
    double * data;
};

typedef flower_t ** network;

typedef struct list list_t;
struct list
{
    flower_t * data;
    double diff;
    list_t * next;
};

typedef struct head head_t;
struct head{
    list_t * next;
};



void print_fleur(flower_t f){
    printf("%f %f %f %f %d\n", f.data[0],f.data[1],f.data[2],f.data[3], f.type);
}

void fill_vector(int indice, flower_t * vec, int datasize, double * data, char * name){
    vec[indice].data = (double*)malloc(vec_att_size * sizeof(double));

    for (int i = 0; i < datasize; i++){
        vec[indice].data[i] = data[i];
    }

    if(strcmp(name, "Iris-setosa\n") == 0){
        vec[indice].type = 1;
    }else if(strcmp(name, "Iris-versicolor\n") == 0){
        vec[indice].type = 2;
    }else if(strcmp(name, "Iris-virginica\n") == 0){
        vec[indice].type = 3;
    }else{
        fprintf(stderr,"unknow type\n");
        exit(1);
    }
}

double get_moyenne(flower_t * vec, int col_number, int size){
    double ret = 0;
    for (int i = 0; i < size; i++){
        //printf("%f ,",vec[i].data[col_number]);
        ret += vec[i].data[col_number];
    }
    ret /= size;
    return ret;
}

double get_norme(flower_t * vec, int col_number, int size){
    double ret = 0;
    for (int i = 0; i < size; i++){
        ret += vec[i].data[col_number] * vec[i].data[col_number];
    }
    ret = sqrt(ret);
    return ret;
}

void normalize(flower_t * vec, int size, flower_t * ret){
    double *tab_norme = (double*)malloc(vec_size * sizeof(double));
    for (int i = 0; i < vec_size; i++){
        tab_norme[i] = get_norme(vec, i , size);
    }

    for (int i = 0; i < size; i++){
        ret[i].data = malloc(vec_size * sizeof(double));
        for (int j = 0; j < vec_size; j++){
            ret[i].data[j] = vec[i].data[j]/ tab_norme[j];
        }
        ret[i].type = vec[i].type;
    }
    free(tab_norme);
}

double get_random_ponderation(){
    double result = random_ponderation_min + ((double) rand() / (double) RAND_MAX) * (double)(random_ponderation_max - random_ponderation_min);
    //printf("%f ", result);
    return result;
}

void fill_neuron(flower_t * neu, flower_t av_neu, int att_size){
    neu->data = (double*) malloc(att_size * sizeof(double));
    for (size_t i = 0; i < att_size; i++){
        neu->data[i] = av_neu.data[i] * get_random_ponderation();
        neu->type = 0;
    }
}

void print_network(network r){
    for (size_t i = 0; i < 6; i++){
        for (size_t j = 0; j < 10; j++){
            printf("%ld : ",i*10+ j);
            print_fleur(r[i][j]);
        }
    }
}

network create_neurons(flower_t vec_av, int neu_size, int att_size, int sizeX, int sizeY){

    network result = (flower_t **) malloc( sizeY * sizeof(flower_t*));
    assert(result);
    for (size_t i = 0; i < sizeX; i++){
        result[i] = (flower_t *) malloc(10 * sizeof(flower_t));
    }

    //printf("%d \n", neu_size);
    //printf("%d \n", neu_size / 10);
    
    for (size_t i = 0; i < sizeY ; i++){    
        for (size_t j = 0; j < sizeX; j++){
            fill_neuron(&result[i][j], vec_av, att_size);
        }
    }

    return result;
        
}

double compare_neuronne(flower_t f1, flower_t f2, int att_size){
    double result = 0;
    for (size_t i = 0; i < att_size; i++){
        result += sqrt( (f2.data[i] - f1.data[i]) * (f2.data[i] - f1.data[i]) );
        //printf("res =%f\n",result);
    }
    return result;
}


void fill_random_index_arr(int * indice,int size){
    for (int i = 0; i < size; i++){
        indice[i] = i;
    }

    int draw, tmp;
    for (int i = 0; i < size; i++){
        draw = rand() % size;
        tmp = indice[i];
        indice[i] = indice[draw];
        indice[draw] = tmp;
    }
}
void find_best_match(int * x, int *y, network neu, flower_t data){
    
    
    print_fleur(data);
}

//une cycle d'apprentissage
void learn(network neu, int neu_size, flower_t * vec_data, int att_size, int * indice,int ind_size, int sizeX, int sizeY){
    int x = 0, y = 0;
    for (size_t i = 0; i < ind_size; i++){
        find_best_match(&x, &y, neu, vec_data[indice[i]]);
        //a enlever
        break;
    }
    
}



int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("Usage: ./exec file_name\n");
        exit(1);
    }

    const char * fname = argv[1];
    //printf("filename: %s\n", fname);
    
    FILE * file = fopen(fname,"r");
    flower_t * vec_data = (flower_t *)malloc(vec_size * sizeof(flower_t));
    flower_t * normalized_vec_data = (flower_t *)malloc(vec_size*sizeof(flower_t));
    
    char * line = (char *) malloc(buffer_size* sizeof(char));
    double * buffer_data = (double *) malloc(vec_att_size * sizeof(double));
    char* buffer_type;
    char * buffer_reader;
    
    for (int i = 0; i < vec_size; i++){
        getline(&line, &buffer_size, file);
        //printf("%s",line);
        
        buffer_reader = strtok(line, ",");
        for (int j = 0; j < 4; j++)
        {
            buffer_data[j] = strtod( buffer_reader,NULL);
            buffer_reader = strtok(NULL, ",");
        }
        //printf("%lf %lf %lf %lf ", buffer_data[0], buffer_data[1], buffer_data[2], buffer_data[3]);
        buffer_type = buffer_reader;
        //int j = 0;
        //printf(">> %d\n", sizeof(buffer_type));
        //printf("%s", buffer_type);
        fill_vector(i, vec_data, vec_att_size, buffer_data, buffer_type);

    }

    fclose(file);

    //for (size_t i = 0; i < 150; i++){print_fleur(vec_data[i]);}
    
    normalize(vec_data, vec_size, normalized_vec_data);

    //vecteur contenant les valeurs moyennes
    flower_t vec_average;
    vec_average.type = 0;
    vec_average.data = malloc(vec_size * sizeof(double));
    
    for (int i = 0; i < vec_att_size; i++){
        vec_average.data[i] = get_moyenne(normalized_vec_data, i, vec_size);
        //printf("%f ,", vec_average.data[i]);
    }
    //print_fleur(vec_average);
    srand(time(NULL));

    network neurons = create_neurons(vec_average, neu_size, vec_att_size , neu_sizeX, neu_sizeY);
    assert(neurons);
    
    //print_network(neurons);
    
    //genese tableau randomisation
    int *indice = (int*)malloc(vec_size * sizeof(int));
    assert(indice);
    fill_random_index_arr(indice,vec_size);
    //for (size_t i = 0; i < 150; i++){printf("%d ", indice[i]);}
    
    print_fleur(neurons[0][0]);
    print_fleur(neurons[0][1]);
    printf("=> %f \n", compare_neuronne(neurons[0][0], neurons[0][1], vec_att_size));

    learn(neurons, vec_size, normalized_vec_data,vec_att_size, indice, vec_size, neu_sizeX, neu_sizeY);

    return 0;
}