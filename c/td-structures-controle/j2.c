#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int multiplicationaddition(int a, int b) {
	int r = 0;
	for(int i=0; i<a; i++) {
		r = r+b;
	}
	return r;
}


int main() {
	int n;
	int m;
	int r = 1;
	printf("Entrez votre premier nombre : ");
	scanf("%d", &n);
	printf("Entrez la puissance : ");
	scanf("%d", &m);
	if (m == 0) {
		printf("> 1");
		printf("\n");
	} else {
		for(int i=0; i<m; i++) {
			// r = r*n			
			r = multiplicationaddition(r, n);
		}
		printf("> %d", r);
		printf("\n");
	}
}
