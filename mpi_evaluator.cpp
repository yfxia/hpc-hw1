/*
 * CX 4220 / CSE 6220 Introduction to High Performance Computing
 *              Programming Assignment 1
 * 
 *  MPI polynomial evaluation algorithm function implementations go here
 * 
 */

#include "mpi_evaluator.h"
#include "const.h"
#include "<math.h>"

void scatter(const int n, double* scatter_values, int &n_local, double* &local_values, int source_rank, const MPI_Comm comm){
    //Implementation
    // double d = log2(p);
    //Configure d using the right shift bitwise operator
    int d = 0;
    int value = source_rank;
    while (value > 0) {
	d++;
	value = value >> 1;
    }
    for (j = 0; j < d; j = j + 1){
	double mask = double pow(2, j);
	if ((source_rank AND mask != 0 )){
		//if it is the last processor, use floor, else ceiling
		count = ceil(n/p); 
		MPI_Send(scatter_values, count, MPI_INT,
			0, 111, comm); 
	} else {
		MPI_Status stat;
		MPI_Recv(scatter_values, count, MPI_INT, 
			0, 111, comm, &stat);
	}
	
    }
    return MPI_Finalize();
}

//Broadcast a real number among p processors
double broadcast(double value, int source_rank, const MPI_Comm comm){
    //Implementation
    int world_rank;
    //MPI_Init(&argc, &argv);
    MPI_Comm_rank(comm, &world_rank);
    //If at processor 0, send data to everyone
    if (world_rank == source_rank){
	for (int i = 0; i < world_size; i++){
		if (i != source_rank){
			MPI_Send(value, 1, MPI_DOUBLE, i, 0, comm);
		}
	} 
    } else {
		MPI_Recv(value, 1, MPI_DOUBLE, source_rank, 0, comm, MPI_STATUS_IGNORE);
	}
    }
    return 0;
}

void parallel_prefix(const int n, const double* values, double* prefix_results, const int OP, const MPI_Comm comm){
    //Implementation

}

double mpi_poly_evaluator(const double x, const int n, const double* constants, const MPI_Comm comm){
    //Implementation

    return 0;
}
