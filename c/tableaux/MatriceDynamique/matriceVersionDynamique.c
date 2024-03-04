/* 
pour compiler le programme, on fait : gcc matriceVersionDynamique.c - o pgm
pour l'exécuter, on fait : cat matrice.txt | ./pgm 6
*/


#include <stdio.h>
#include <stdlib.h>

void remplirMat(int **mat, int N){
	// Remplir la matrice
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf("%d",&mat[i][j]);
		}
	}
}

void afficherMat(int **mat, int N){
	// afficher la matrice
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
	int** mat = (int **) malloc(N*sizeof(int*)); // allocation de la ligne principale (des pointeurs)
	for(int i=0; i<N; i++) // allocation des colonnes
		mat[i] = (int *) malloc(N*sizeof(int));

	// remplir la matrice
	remplirMat(mat, N);

	// afficher la matrice
	afficherMat(mat, N);

	// libérer la matrice
	for(int i=0; i<N; i++)  // liberation des colonnes
		free(mat[i]); 
	free(mat); // libération de la ligne principale (ligne des pointeurs)
	
}



