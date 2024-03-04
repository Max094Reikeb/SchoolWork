#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int p = 0;
	int n = 0;
	int a = 1;
	while (a != 0) {
		printf("Entrez un nombre : ");
		scanf("%d", &a);
		if (a > 0) {
			p = p+a;
		} else {
			n = n+a;
		}
	}
	printf("> Somme des nombres positifs : %d", p);
	printf("\n");
	printf("> Somme des nombres négatifs : %d", n);
	printf("\n");
}
