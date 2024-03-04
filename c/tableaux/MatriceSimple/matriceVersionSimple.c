/* 
pour compiler le programme, on fait : gcc matriceVersionSimple.c - o pgm
pour l'exécuter, on fait : cat matriceA.txt | ./pgm 6
*/


#include <stdio.h>
#include <stdlib.h>


void afficherMat(int **mat, int N){
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
}



int main(int argc, char ** argv){
	
	int N;// dimension de la matrice
	// ptr est là juste pour utiliser strtol
	char* ptr;
	N = (int) strtol(argv[1], &ptr, 10);


	// allouer une matrice NXN
	int** mat = (int **) malloc(N*sizeof(int*)); 
	for(int i=0; i<N; i++)
		mat[i] = (int *) malloc(N*sizeof(int));


	// Remplir la matrice
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf("%d",&mat[i][j]);
		}
	}

	afficherMat(mat, N);

	for(int i=0; i<N; i++)
		free(mat[i]); 
	free(mat); 
	
}



