#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int n;
	int m;
	int r = 0;
	printf("Entrez votre premier nombre : ");
	scanf("%d", &n);
	printf("Entrez votre deuxième nombre : ");
	scanf("%d", &m);
	int w = m+1;
	for(int i=1; i<w; i++) {
		r = r+n;
	}
	printf("> %d", r);
	printf("\n");
}
