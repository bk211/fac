#include <mpi.h>
#include <iostream>
int main(int argc, char const *argv[]) {
    int size,rank;
    int tmp;
    MPI_Init(&argc,(char ***)&argv);
    MPI_Comm_size (MPI_COMM_WORLD,&size);
    MPI_Comm_rank (MPI_COMM_WORLD,&rank);
    if(rank == 0){
        std::cout << "In rank 0" << '\n';
        int foo;
        MPI_Status STATUS;
        MPI_Recv(&foo,1,MPI_INT,1,0,MPI_COMM_WORLD, &STATUS);
        std::cout << "Received " << foo<< '\n';

    }else if(rank == 1){
        std::cout << "In rank "<< rank<<"\n";
        int draw = rand()%10;
        std::cout << "draw " <<draw<< '\n';
        MPI_Send(&draw,1, MPI_INT,0,0,MPI_COMM_WORLD);
        std::cout << "msg sent" << '\n';
    }else{
        std::cout << "hello world from "<<rank<<" | "<<size << '\n';
    }

    MPI_Finalize();
    return 0;
}
