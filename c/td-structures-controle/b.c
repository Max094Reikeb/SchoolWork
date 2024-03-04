#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int n;
	printf("Entrez le nombre dont vous souhaitez voir la table de multiplication : ");
	scanf("%d", &n);
	for(int i=0; i<11; i++) {
		int r = n*i;
		printf("> %d*%d = %d", i, n, r);
		printf("\n");
	}
}
