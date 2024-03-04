#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int r = 0;
	char** ar = argv[1];
	int lenght = sizeof(ar); 
	for(int i=1; i<lenght; i++) {
		int arg2 = strtol(ar[i], NULL, 10);
		r = r + (arg2*pow(2,i));
	}
	printf("> %d",r);
	printf("\n");
}
