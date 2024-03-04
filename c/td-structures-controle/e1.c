#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int n;
	long r = 0;
	printf("Calculons la somme des chiffres entre 0 et le votre : ");
	scanf("%d", &n);
	int m = n+1;
	for(int i=1; i<m; i++) {
		r = r+i;
	}
	printf("> %ld", r);
	printf("\n");
}
