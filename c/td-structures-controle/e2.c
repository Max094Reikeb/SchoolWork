#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int n;
	int m;
	int r;
	printf("Entrez N : ");
	scanf("%d", &n);
	printf("Entrez M : ");
	scanf("%d", &m);
	r = m;
	printf("La somme de %d et de %d est :", n, m);
	printf("\n");
	for(int i=0; i<n; i++) {
		r = r+1;
	}
	printf("> %ld", r);
	printf("\n");
}
