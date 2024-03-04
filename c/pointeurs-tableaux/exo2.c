/* Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void afficherMinMax(int *tableau, int sizeofTable) {
    int min = tableau[0];
    int max = tableau[0];

    for (int i = 1; i < sizeofTable; i++) {
        if (min > tableau[i]) {
            min = tableau[i];
        }
        if (max < tableau[i]) {
            max = tableau[i];
        }
    }
    printf("Votre tableau :\n");
    for (int j = 0; j < sizeofTable; j++) {
        printf("| %d ", tableau[j]);
    }
    printf("|\nMin : %d\n", min);
    printf("Max : %d\n", max);
    free(tableau);
}

int main(void) {
    int sizeofTable = 0;
    int *tableau = NULL;

    printf("Combien de valeurs voulez-vous entrer ? ");
    scanf("%d", &sizeofTable);

    if (sizeofTable > 0) {
        tableau = malloc(sizeofTable * sizeof(int));
        if (tableau == NULL) {
            exit(0);
        }

        printf("Entrez vos valeurs :\n");
        for (int i = 0; i < sizeofTable; i++) {
            printf("> ");
            scanf("%d", &tableau[i]);
        }

        afficherMinMax(tableau, sizeofTable);
    }
}