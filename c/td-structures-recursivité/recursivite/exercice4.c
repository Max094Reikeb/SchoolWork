/**Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void mirroir_reccu(char mot[100], char word[100], int i) {
	int length = strlen(mot);
	if (i == length) {
		word[i+1] = '\0';
		return;
	} else {
		word[length-i-1] = mot[i];
		i++;
		mirroir_reccu(mot, word, i);
	}
}

void mirroir_ite(char mot[100], char word[100]) {
	int length = strlen(mot);
	int i;
	for (i = 0; i < length; i++) {
		word[length-i-1] = mot[i];
	}
	word[i+1] = '\0';
}

int main(void) {
    char mot[100];
	char mot_inverse[100];
	int n;
	printf("Fonction...\n");
	printf("1. Récursive ?\n");
	printf("2. Itérative ?\n");
	printf("> ");
	scanf("%d", &n);
	if (n == 1) {
    	printf("Entrez votre mot : ");
    	scanf("%s", mot);
    	mirroir_reccu(mot, mot_inverse, 0);
    	printf("Le mot mirroir est : %s\n", mot_inverse);
	} else if (n == 2) {
		printf("Entrez votre mot : ");
    	scanf("%s", mot);
    	mirroir_ite(mot, mot_inverse);
    	printf("Le mot mirroir est : %s\n", mot_inverse);
	}
}
