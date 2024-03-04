#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int n;
	long r = 1;
	printf("Entrez le nombre dont vous souhaitez avoir la factorielle : ");
	scanf("%d", &n);
	int m = n+1;
	for(int i=1; i<m; i++) {
		r = r*i;
	}
	printf("> %ld", r);
	printf("\n");
}
