/*
**  Parallel producer/consumer with pairwise synchronization (pipeline-like)
*/
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

#define N 10000

/* Some random number constants from numerical recipies */
#define SEED       2531
#define RAND_MULT  1366
#define RAND_ADD   150889
#define RAND_MOD   714025

static int randy = SEED;

/* function to fill "length" values into a buffer */
static void fill_rand_chunk(int length, double *buf)
{
   for (int i = 0; i < length; i++) {
     randy = (RAND_MULT * randy + RAND_ADD) % RAND_MOD;
     buf[i] = ((double) randy)/ ((double) RAND_MOD);
   }   
}

/* function to sum the elements of an array */
static double sum_array(int length, const double *buf)
{
   double sum = 0.0;
   for (int i = 0; i < length; i++)  sum += buf[i];
   return sum; 
}
  
int main(void)
{
  const int CHUNK = 512; // taille de paquet
  double *buf0 = (double *)malloc(CHUNK * sizeof(double));
  double *buf1 = (double *)malloc(CHUNK * sizeof(double));
  if (!buf0 || !buf1) { perror("malloc"); return 1; }

  volatile int ready[2] = {0, 0}; // ready[s] = 1 => slot s rempli et prêt à consommer
                                  // ready[s] = 0 => slot s libre pour produire

  double sum = 0.0;
  double t0 = omp_get_wtime();

  #pragma omp parallel num_threads(2) default(none) shared(ready, buf0, buf1, sum)
  {
    int tid = omp_get_thread_num();

    if (tid == 0) {
      // PRODUCER
      int produced = 0;
      int slot = 0;

      while (produced < N) {
        int len = (N - produced < CHUNK) ? (N - produced) : CHUNK;
        double *buf = (slot == 0) ? buf0 : buf1;

        // attendre que le slot soit libre
        while (ready[slot] == 1) {
          #pragma omp flush(ready)
        }

        fill_rand_chunk(len, buf);  // produire un chunk

        // publier le chunk
        #pragma omp flush  // s'assure que buf est visible avant le flag
        ready[slot] = 1;
        #pragma omp flush(ready)

        produced += len;
        slot ^= 1;  // alterne 0/1 (double buffering)
      }

      // envoyer un "sentinel" de fin : ready = 2 sur un slot libre
      while (ready[slot] == 1) {
        #pragma omp flush(ready)
      }
      ready[slot] = 2;
      #pragma omp flush(ready)

    } else {
      // CONSUMER
      int consumed = 0;
      int slot = 0;
      double local_sum = 0.0;

      while (1) {
        // attendre qu'un slot soit prêt (1) ou qu'on reçoive la fin (2)
        while (ready[slot] == 0) {
          #pragma omp flush(ready)
        }

        if (ready[slot] == 2) break;  // fin de production

        int len = (N - consumed < CHUNK) ? (N - consumed) : CHUNK;
        const double *buf = (slot == 0) ? buf0 : buf1;

        #pragma omp flush  // s'assure de voir les données du buffer
        local_sum += sum_array(len, buf);

        // libérer le slot
        ready[slot] = 0;
        #pragma omp flush(ready)

        consumed += len;
        slot ^= 1;

        if (consumed >= N) {
          // on peut aussi attendre le sentinel sur le slot suivant,
          // mais consumed>=N suffit à sortir proprement ici.
          break;
        }
      }

      // publication du résultat
      #pragma omp atomic write
      sum = local_sum;
    }
  }

  double runtime = omp_get_wtime() - t0;

  printf("In %f seconds, The sum is %f\n", runtime, sum);

  free(buf0);
  free(buf1);
  return 0;
}
