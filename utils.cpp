/*
 * CX 4220 / CSE 6220 Introduction to High Performance Computing
 *              Programming Assignment 1
 * 
 *  Utility function implementation
 * 
 */

#include "utils.h"

//------------------- Timer Functions (Do not change) -------------------//
void set_time(struct timespec &t, const int rank, MPI_Comm comm){
    if (rank>=0) // Do not call barrier if rank is negative
        MPI_Barrier(comm);
    if (rank <= 0){ //only 1 processor will set the time
        clock_gettime(CLOCK_MONOTONIC,  &t);
    }
}

double get_duration(struct timespec &t_start, struct timespec &t_end){
    return (t_end.tv_sec - t_start.tv_sec)
         + (double) (t_end.tv_nsec - t_start.tv_nsec) * 1e-9;
}
//---------------------------------------------------------------------//

/*********************************************************************
 *                 Implement your own functions here                 *
 *********************************************************************/




// ...