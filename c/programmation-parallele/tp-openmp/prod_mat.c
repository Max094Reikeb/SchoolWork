////////////////////////////////////////////////////////////////////////////////
// prod_mat.c --- produit de matrices : C = A * B
//
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


// Dimension par defaut de la taille des matrices
#ifndef VAL_M
#define VAL_M 101
#endif
#ifndef VAL_N
#define VAL_N 201
#endif

int main(void) {

  int m = VAL_M, n = VAL_N;

  static double a[VAL_M][VAL_N];
  static double b[VAL_N][VAL_M];
  static double c[VAL_M][VAL_M];


  // Initialisation A
  for(int i=0; i < m; i++) {
    for(int j=0; j < n; j++) {
      a[i][j] = (i+1)+(j+1);
    }
  }

  // Initialisation B
  for(int i=0; i < n; i++) {
    for(int j=0; j < m; j++) {
      b[i][j] = (i+1)-(j+1);
    }
  }

  // Initialisation C
  for(int i=0; i < m; i++) {
    for(int j=0; j < m; j++) {
      c[i][j] = 0.0;
    }
  }

  double t0 = omp_get_wtime();

  // Produit de matrice / Parallélisation
  // "schedule(runtime)" permet de tester STATIC/DYNAMIC/GUIDED via OMP_SCHEDULE
  // "collapse" permet d'applatir les boucles i et j en une seule grande boucle
  // "shared" indique que 'a', 'b', 'c', 'm' et 'n' sont partagés
  #pragma omp parallel for collapse(2) schedule(runtime) default(none) shared(a,b,c,m,n)
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      double sum = 0.0;
      for (int k = 0; k < n; k++) {
        sum += a[i][k] * b[k][j];
      }
      c[i][j] = sum;
    }
  }

  double t1 = omp_get_wtime();

  // Impression du resultat + temps
  fprintf(stdout, "\n\n"
	  "   Valeurs de m et n   : %5d %5d\n"
	  "   Temps (s)           : %10.6f\n"
	  "   Resultat partiel    : %10.3E %10.3E ... %10.3E %10.3E\n\n",
      m, n, (t1 - t0),
      c[1][1], c[2][2], c[m-3][m-3], c[m-2][m-2]
  );

  return EXIT_SUCCESS;
}
