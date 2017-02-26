/*
 * CX 4220 / CSE 6220 Introduction to High Performance Computing
 *              Programming Assignment 1
 * 
 *  MPI polynomial evaluation algorithm function implementations go here
 * 
 */

#include "mpi_evaluator.h"
#include "const.h"
#include <math.h>

void scatter(const int n, double* scatter_values, int &n_local, double* &local_values, int source_rank, const MPI_Comm comm){
    //Get # processors and rank
    int p, rank;
    MPI_Comm_size(comm, &p);
    MPI_Comm_rank(comm, &rank);
    
    
    if (rank == source_rank){
	for (int i = 0; i < p; i++){
		if (i == p-1){
			n_local = floor(n / p);
		} else {
			n_local = ceil(n / p);
		}
		local_values = new double[n_local];
		if (i != source_rank) {
			MPI_Send(&scatter_values, n_local, MPI_INT, i, 111, comm);
		} else {
			MPI_Status stat;
			MPI_Recv(&scatter_values, n_local, MPI_INT, source_rank, 111, comm, &stat);
		}
		printf("After: Rank: %d\tscatter_V: %lld\n", rank, (long long int)scatter_values);
    		printf("\nrank:%d\tvalue:%d\n", rank, (scatter_values+rank));
	}

    }
    return;

}

double broadcast(double value, int source_rank, const MPI_Comm comm){
    //Implementation

    return 0;
}

void parallel_prefix(const int n, const double* values, double* prefix_results, const int OP, const MPI_Comm comm){
    //Implementation

}

double mpi_poly_evaluator(const double x, const int n, const double* constants, const MPI_Comm comm){
    //Implementation

    return 0;
}
