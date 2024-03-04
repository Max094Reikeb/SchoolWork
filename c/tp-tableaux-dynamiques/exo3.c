/* Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "aTM.h"

void calculMoyenne(int *tableau, int sizeofTable) {
    int sommeNotes = 0, compteur = 0;
    for(int i = 0; i < sizeofTable; i++) {
        sommeNotes = sommeNotes + tableau[i];
    }
    int moyenne = sommeNotes/sizeofTable;

    for(int j = 0; j < sizeofTable; j++) {
        if (tableau[j] > moyenne) {
            compteur++;
        }
    }
    printf("Il y a %d notes au dessus de la moyenne (qui est de %d) !\n", compteur, moyenne);
}

int main(void) {
    int sizeofTable = 0;
    int *tableau = NULL;

    printf("Entrez le nombre d'étudiants : ");
    scanf("%d", &sizeofTable);

    if (sizeofTable > 0) {
        tableau = malloc(sizeofTable * sizeof(int));
        if (tableau == NULL) {
            exit(0);
        }

        printf("Entrez les notes :\n");
        for (int i = 0; i < sizeofTable; i++) {
            printf("> ");
            scanf("%d", &tableau[i]);
            if (tableau[i] > 20) {
                printf("Erreur ! Note supérieure à 20/20 !\n");
                return 1;
            }
        }

        calculMoyenne(tableau, sizeofTable);
    }
}