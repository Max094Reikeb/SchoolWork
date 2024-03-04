#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int n;
	printf("Nous allons afficher les nombres pairs entre 0 et votre nombre : ");
	scanf("%d", &n);
	int m = n+1;
	for(int i=1; i<m; i++) {
		int j = i%2;
		if (j == 0){
			printf("> %d", i);
			printf("\n");
		}
	}
}
