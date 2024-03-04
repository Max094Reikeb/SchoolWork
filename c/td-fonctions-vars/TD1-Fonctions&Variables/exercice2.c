#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

int bidon(){
	int n;
	printf("%d\n", n);
	scanf("%d", &n);
	printf("%d\n", n);
}

int main(){
	int n;
	printf("Donnez %d et %d", n, n);
	scanf("%d", &n);
	printf("%d\n", n);
	bidon();
	printf("%d\n", n);
}

