#include <stdio.h>
   #include <mpi.h>
     
int main(int argc, char **argv)
   {
      int ierr, num_procs, my_id;

      ierr = MPI_Init(&argc, &argv);

      ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
      ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

      printf("Hello world! I'm process %i out of %i processes\n", 
         my_id, num_procs);

      ierr = MPI_Finalize();
   }