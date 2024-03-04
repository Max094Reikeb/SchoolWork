#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int n;
	int m;
	int i = 0;
	int x;
	int r;
	printf("Entrez N : ");
	scanf("%d", &n);
	printf("Entrez M : ");
	scanf("%d", &m);
	if (m == 0) {
		printf("La division par 0 est impossible !");
		printf("\n");
	} else {
		while ((m*i) < n) {
			i = i+1;
		}
		if (n%m == 0) {
			x = i;
			r = 0;
		} else {
			x = i - 1;
			r = n - (m*x);
		}
		if (r < 0) {
			r = r + m;
			x = x - 1;
		}
		printf("> La division de %d par %d est : %d (et il reste %d)", n, m, x, r);
		printf("\n");
	}
}