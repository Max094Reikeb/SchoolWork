#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int n;
	int m;
	int r;
	printf("Entrez N : ");
	scanf("%d", &n);
	printf("Entrez M : ");
	scanf("%d", &m);
	printf("Le produit de %d et de %d est :", n, m);
	printf("\n");
	for(int i=0; i<n; i++) {
		r = r+m;
	}
	printf("> %d", r);
	printf("\n");
}
