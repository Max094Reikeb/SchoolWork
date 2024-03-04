/**Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int echange(int nb1, int nb2) {
	int tmp;
    printf("Avant échange :");
    printf("\nNb1 = %d", nb1);
    printf("\nNb2 = %d", nb2);
    tmp = nb1;
    nb1 = nb2;
    nb2 = tmp;
    printf("\nAprès échange :");
    printf("\nNb1 = %d", nb1);
    printf("\nNb2 = %d", nb2);
    printf("\n");
}

int main(void) {
	int nb1 = 5;
    int nb2 = 7;
    printf("Avant appel de la fonction :");
    printf("\nNb1 = %d", nb1);
    printf("\nNb2 = %d", nb2);
    printf("\nAppel de la fonction échange...\n");
    echange(nb1, nb2);
    printf("\nAprès appel de la fonction :");
    printf("\nNb1 = %d", nb1);
    printf("\nNb2 = %d", nb2);
}
