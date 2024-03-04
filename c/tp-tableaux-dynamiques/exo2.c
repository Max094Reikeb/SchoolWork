/* Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "aTM.h"

void supprimerIdenticValues(int *tableau, int sizeofTable) {
    int *newTable = NULL;
    newTable = malloc(sizeofTable * sizeof(int));
    if (newTable == NULL) {
        exit(0);
    }
    newTable[0] = tableau[0];
    for (int j = 1; j < sizeofTable; j++) {
        newTable[j] = 99;
    }
    bool c = false;
    int a = 0;
    for (int i = 1; i < sizeofTable; i++) {
        if ((newTable[i - (1 + a)] == tableau[i]) || (newTable[i + (1 - a)] == tableau[i])) {
            c = true;
            a++;
        }
        if (!c) {
            newTable[i-a] = tableau[i];
        }
        c = false;
    }
    free(tableau);
    sizeofTable = sizeofTable - a;
    aTM(newTable, sizeofTable);
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

        supprimerIdenticValues(tableau, sizeofTable);
    }
}