/* Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void randTabdyn(int *tableau, int n, int x, int y) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int nbre_alea = (rand() % (y - x)) + x;
        tableau[i] = nbre_alea;
    }
    printf("Votre tableau :\n");
    for (int j = 0; j < n; j++) {
        printf("| %d ", tableau[j]);
    }
    printf("|\n");
}

int main(void) {
    int n, x, y;
    int *tableau = NULL;

    printf("Combien de cases possède votre tableau ? ");
    scanf("%d", &n);

    if (n > 0) {
        tableau = malloc(n * sizeof(int));
        if (tableau == NULL) {
            exit(0);
        }

        printf("Entrez les bornes pour les nombres aléatoires...\n");
        printf("Min : ");
        scanf("%d", &x);
        printf("Max : ");
        scanf("%d", &y);

        randTabdyn(tableau, n, x, y);
    }
}