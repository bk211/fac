#include <mpi.h>
#include <iostream>

int main(int argc, char const *argv[]) {
    int size,rank;
    int tmp;
    int result = 0;
    MPI_Init(&argc,(char ***)&argv);
    MPI_Comm_size (MPI_COMM_WORLD,&size);
    MPI_Comm_rank (MPI_COMM_WORLD,&rank);
    srand(time(NULL));
    if(rank == 0){
        std::cout << "In rank 0" << '\n';
        MPI_Status status;

        for (int i = 1; i < size; i++) {
            MPI_Recv(&tmp,1,MPI_INT,i,0,MPI_COMM_WORLD, &status);
            std::cout << "Received <" <<tmp <<"> from " << i<<'\n';
            if(tmp > result){
                result = tmp;
            }
        }
        std::cout << "max is " <<result<< '\n';


    }else{
        std::cout << "In rank "<< rank<<"\n";
        int draw = rand()%10;
        std::cout <<rank <<" has draw " <<draw<< '\n';
        MPI_Send(&draw,1, MPI_INT,0,0,MPI_COMM_WORLD);
        std::cout << "msg sent" << '\n';
    }

    MPI_Finalize();
    return 0;
}
