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
	char a = 'a', e = 'e', i = 'i', o = 'o', u = 'u', y = 'y', mot[26];

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL) {
		perror("Unable to allocate buffer");
        	exit(1);
	}

	printf("Entrez votre mot : ");
	characters = getline(&buffer,&bufsize,stdin);

	int r = strlen(buffer);

	for(int j=0; j<=r; j++) {
        	if (buffer[j] == a || buffer[j] == e || buffer[j] == i || buffer[j] == o || buffer[j] == u || buffer[j] == y) {
            		buffer[j] = '?';
        	}
    	}

    	printf("Après remplacement, voici votre mot : %s", buffer);
    	printf("\n");

	return(0);
}
