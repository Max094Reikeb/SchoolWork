# include <stdio.h>
# include <mpi.h>

int main(int argc, char *argv[]) {

    int rank;
    int nprocs;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank % 2 == 0) {
        printf("Je suis le processus pair de rang %d\n", rank);
    } else {
        printf("Je suis le processus impair de rang %d\n", rank);
    }
    fflush(stdout);

    MPI_Finalize();
    return 0;
}
