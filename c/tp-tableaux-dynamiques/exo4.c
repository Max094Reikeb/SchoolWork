/* Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void isMagic(int n, int *tableau, int sizeofTable) {
    FILE* fichier = NULL;
    fichier = fopen("tableaux.txt", "a");
    if (fichier != NULL) {
        for (int i = 0; i < sizeofTable; i++) {
            for (int j = 0; j < sizeofTable; j++) {
                int r = sizeofTable * i;
                fprintf(fichier, "| %d ", tableau[r + j]);
            }
            fprintf(fichier, "|\n");
        }
        fprintf(fichier, "\n");
        if (n == 0) {
            fprintf(fichier, "Tableau pas magique.\n");
            printf("Votre tableau n'est pas magique !\n");
            fprintf(fichier, "\n");
            fprintf(fichier, "\n");
        } else {
            fprintf(fichier, "Tableau magique.\n");
            printf("Votre tableau est magique !\n");
            fprintf(fichier, "\n");
            fprintf(fichier, "\n");
        }
        fclose(fichier);
    } else {
        printf("Impossible d'ouvrir le fichier mémoire !\n");
        if (n == 0) {
            printf("Votre tableau n'est pas magique !\n");
        } else {
            printf("Votre tableau est magique !\n");
        }
    }
}

void calculDiagonales(int *tableau, int sizeofTable) {
    int k = sizeofTable + 1, somme = 0, l = sizeofTable - 1, somme2 = 0;
    for (int i = 0; i < sizeofTable; i++) {
        somme = somme + tableau[k * i];
        printf("%d\n", somme);
    }
    printf("somme diagonale 1 = %d\n", somme);
    for (int j = 1; j <= sizeofTable; j++) {
        somme2 = somme2 + tableau [l * j];
        printf("%d\n", somme2);
    }
    printf("somme diagonale 2 = %d\n", somme2);
    if (somme == somme2) {
        isMagic(1, tableau, sizeofTable);
    } else {
        isMagic(0, tableau, sizeofTable);
    }
}

void calculColones(int *tableau, int sizeofTable) {
    int sT = sizeofTable;
    int *tB3 = NULL;
    tB3 = malloc(sT * sizeof(int));
    if (tB3 == NULL) {
        exit(0);
    }
    for (int i = 0; i < sizeofTable; i++) {
        int somme = 0;
        for (int j = 0; j < sizeofTable; j++) {
            int k = j * sizeofTable;
            somme = somme + tableau[k + i];
            printf("%d\n", somme);
        }
        tB3[i] = somme;
        printf("somme colonne %d = %d\n", i, somme);
    }
    bool isEqual = true;
    for (int l = 1; l < (sizeofTable - 1); l++) {
        if ((tB3[l-1] != tB3[l]) || (tB3[l] != tB3[l+1])) {
            isEqual = false;
        }
    }
    free(tB3);
    if (isEqual == true) {
        printf("Pour le moment c'est ok\n");
        calculDiagonales(tableau, sizeofTable);
    } else {
        isMagic(0, tableau, sizeofTable);
    }
}

void calculLignes(int *tableau, int sizeofTable) {
    int sT = sizeofTable;
    int *tB2 = NULL;
    tB2 = malloc(sT * sizeof(int));
    if (tB2 == NULL) {
        exit(0);
    }
    for (int i = 0; i < sizeofTable; i++) {
        int somme = 0;
        int k = i * sizeofTable;
        for (int j = 0; j < sizeofTable; j++) {
            somme = somme + tableau[j + k];
            printf("%d\n", somme);
        }
        tB2[i] = somme;
        printf("somme ligne %d = %d\n", i, somme);
    }
    bool isEqual = true;
    for (int l = 1; l < (sizeofTable - 1); l++) {
        if ((tB2[l-1] != tB2[l]) || (tB2[l] != tB2[l+1])) {
            isEqual = false;
        }
    }
    free(tB2);
    if (isEqual == true) {
        printf("Pour le moment c'est ok\n");
        calculColones(tableau, sizeofTable);
    } else {
        isMagic(0, tableau, sizeofTable);
    }
}

int main(void) {
    int sizeofTable = 0;
    int *tableau = NULL;

    printf("Entrez la dimension x*x de votre tableau : ");
    scanf("%d", &sizeofTable);

    int doubleSizeTable = sizeofTable * sizeofTable;

    if (doubleSizeTable >= 4) {
        tableau = malloc(doubleSizeTable * sizeof(int));
        if (tableau == NULL) {
            exit(0);
        }

        int m = 1;
        printf("Voici votre tableau");
        printf("\n");
        for (int i = 0; i < sizeofTable; i++) {
            for (int j = 1; j <= sizeofTable; j++) {
                if (sizeofTable >= 4) {
                    if (sizeofTable >= 10) {
                        if (m < 10) {
                            printf("| 00%d ", m);
                        } else if (m >= 10 && m < 100) {
                            printf("| 0%d ", m);
                        } else {
                            printf("| %d ", m);
                        }
                    } else {
                        if (m < 10) {
                            printf("| 0%d ", m);
                        } else {
                            printf("| %d ", m);
                        }
                    }
                } else {
                    printf("| %d ", m);
                }
                m++;
            }
            printf("|\n");
        }
        printf("Entrez les valeurs :\n");
        for (int k = 0; k < doubleSizeTable; k++) {
            printf("%d >> ", k+1);
            scanf("%d", &tableau[k]);
        }

        calculLignes(tableau, sizeofTable);

    } else {
        printf("Erreur : votre tableau doit être au moins de 2*2");
    }
}