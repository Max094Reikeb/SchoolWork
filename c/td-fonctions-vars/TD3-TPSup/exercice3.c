/**Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int input(char *s,int length);

int main() {
	char *buffer;
	size_t bufsize = 32;
	size_t characters;
	int w = 1;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL) {
		perror("Unable to allocate buffer");
        	exit(1);
	}

	printf("Entrez votre phrase : ");
	characters = getline(&buffer,&bufsize,stdin);

	int r = strlen(buffer);
	for(int j=1; j<=r; j++) {
		if (buffer[j] == ' ') {
            		w = w+1;
        	}
    	}
	printf("La phrase que tu as entré comporte %d mots", w);
	printf("\n");

	return(0);
}
