#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int n;
	int m;
	int r = 1;
	printf("Entrez votre premier nombre : ");
	scanf("%d", &n);
	printf("Entrez la puissance : ");
	scanf("%d", &m);
	int w = m+1;
	if (m == 0) {
		printf("> 1");
		printf("\n");
	} else {
		for(int i=1; i<w; i++) {
			r = r*n;
		}
		printf("> %d", r);
		printf("\n");
	}
}
