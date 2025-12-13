#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define MPI_TAG_VALUE 123456

static void run(int myid, int nprocs) {
  if (nprocs < 2) {
    if (myid == 0) printf("Need at least 2 processes.\n");
    return;
  }

  const int nReceivers = nprocs - 1; // autant de receveurs que d'elements

  if (myid == 0) {
    // Allocation dynamique : taille = nombre de receveurs
    int *arr = (int *)malloc(nReceivers * sizeof(int));
    if (!arr) {
      perror("malloc");
      MPI_Abort(MPI_COMM_WORLD, 1);
    }

    // Remplissage (exemple)
    for (int i = 0; i < nReceivers; i++) {
      arr[i] = 1000 + i;
    }

    // Envoi : rank 1 reçoit arr[0], rank 2 reçoit arr[1], etc.
    for (int dest = 1; dest < nprocs; dest++) {
      MPI_Send(&arr[dest - 1], 1, MPI_INT, dest, MPI_TAG_VALUE, MPI_COMM_WORLD);
    }

    free(arr);
  } else {
    int value = 0;
    MPI_Status status;

    MPI_Recv(&value, 1, MPI_INT, 0, MPI_TAG_VALUE, MPI_COMM_WORLD, &status);

    printf("proc %d received arr[%d] = %d from proc %d (tag=%d)\n",
           myid, myid - 1, value, status.MPI_SOURCE, status.MPI_TAG);
  }
}

int main(int argc, char *argv[]) {
  int myid, nprocs;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

  run(myid, nprocs);

  MPI_Finalize();
  return 0;
}
