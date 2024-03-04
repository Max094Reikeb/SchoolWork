/* 
pour compiler le programme, on fait : gcc matriceStatique.c -o pgm
pour l'exécuter, on fait : cat contenuMatrice.txt | ./pgm 
*/

#include <stdio.h>

#define N 4
#define M 3

/*void afficherMat(int **mat, int N){*/
void afficherMatrice(int mat[N][M]){//int **mat, int N){
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

void remplirMatrice(int mat[N][M]){//int **mat, int N){
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++)
			scanf("%d", &mat[i][j]);
	}
}

int main(){
	int matrice[N][M];

	remplirMatrice(matrice);

	afficherMatrice(matrice);

	return 0;
	
}

