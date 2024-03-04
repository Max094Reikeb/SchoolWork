#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int a;
	int r;
	printf("Entrer votre nombre : ");
	scanf("%d", &a);
	printf("> ");
	while (a>0) {
		r = a % 2;
		a = floor(a/2);
		printf("%d",r);
	}
	printf("\n");
}
