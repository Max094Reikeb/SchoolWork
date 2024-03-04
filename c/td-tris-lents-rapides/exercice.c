/* Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/* Fonction permettant d'échanger rapidement deux pointeurs rapidement */
void echanger(int *m, int *n) {
    int r = *n;
    *n = *m;
    *m = r;
}

/* Fonction de tri par Insertion */
int* triInsertion(int *tableau, int n) {
    int i, j, x;
    for(i = 1; i < n; i++) {
        x = tableau[i];
        j = i;
        while ((j > 0) && (tableau[j-1] > x)) {
            tableau[j] = tableau[j-1];
            j = j-1;
        }
    }
    return tableau;
}

/* Fonction de tri par Selection */
int* triSelection(int *tableau, int n) {
    int m, i, j;
    m = 0;
    for(i = 0; i < n; i++) {
        m = i;
        for(j = i + 1; j < n; j++) {
            if (tableau[j] < tableau[m]) {
                m = j;
            }
        }
        echanger(&tableau[i], &tableau[m]);
    }
    return tableau;
}

/* Fonction de tri par Bulles */
int* triBulles(int *tableau, int n) {
    int i, j;
    j = n;
    while (j > 0) {
        for (i = 0; i < j; i++) {
            if (tableau[i+1] < tableau[i]) {
                echanger(&tableau[i+1], &tableau[i]);
            }
        }
        j = j-1;
    }
    return tableau;
}

/* Fonction pour générer un tableau de taille n d'entiers aléatoires compris entre x et y */
int* randTabdyn(int *tableau, int n, int x, int y) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int nbre_alea = (rand() % (y - x)) + x;
        tableau[i] = nbre_alea;
    }
    return tableau;
}

/* Fonction de choix de l'utilisateur */
int menu(void) {
    int choixMenu;
    printf("|-----------CHOIX-----------|\n");
    printf("| 1 || Choisir soi-même     |\n");
    printf("| 2 || Nombres aléatoires   |\n");
    printf("|---------------------------|\n");
    printf("Votre choix > ");
    scanf("%d", &choixMenu);
    return choixMenu;
}

/* Programme principal */
int main(void) {
	int n, x, y;
    int *tableau = NULL;
    switch (menu()) {
        case 1: // Cas où on doit entrer nous même les valeurs
            printf("Combien de cases possède votre tableau ? ");
            scanf("%d", &n);
            if (n > 0) {
                tableau = malloc(n * sizeof(int));
                if (tableau == NULL) {
                    exit(0);
                }
                for (int i = 0; i < n; i++) {
                    printf("> ");
                    scanf("%d", &tableau[i]);
                }
            }
            break;
        case 2: // Cas où l'utilisateur décide de valeurs aléatoires
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

                tableau = randTabdyn(tableau, n, x, y);
            }
            break;
        default: // Cas où on ne fait aucun choix
            printf("Aucun choix n'a été fait\n");
            break;
    }
    int *tableauBulles = NULL;
    int *tableauInsert = NULL;
    int *tableauSelect = NULL;
    tableauBulles = malloc(n * sizeof(int));
    tableauInsert = malloc(n * sizeof(int));
    tableauSelect = malloc(n * sizeof(int));
    if ((tableauBulles == NULL) || (tableauInsert == NULL) || (tableauSelect == NULL)) {
        exit(0);
    }
    long clk_tck = CLOCKS_PER_SEC;
    clock_t t1, t2, t3, t4;

    t1 = clock();
    tableauBulles = triBulles(tableau, n);
    t2 = clock(); // Pour plus de précision, on prend la mesure du temps AVANT d'afficher le tableau

    printf("Votre tableau (bulles) :\n");
    for (int j = 1; j <= n; j++) {
        printf("| %d ", tableau[j]);
    }
    printf("|\n");
    tableauInsert = triInsertion(tableau, n);
    t3 = clock(); // Pour plus de précision, on prend la mesure du temps AVANT d'afficher le tableau

    printf("Votre tableau (insertion) :\n");
    for (int j = 1; j <= n; j++) {
        printf("| %d ", tableau[j]);
    }
    printf("|\n");
    tableauSelect = triSelection(tableau, n);
    t4 = clock(); // Pour plus de précision, on prend la mesure du temps AVANT d'afficher le tableau

    printf("Votre tableau (selection) :\n");
    for (int j = 1; j <= n; j++) {
        printf("| %d ", tableau[j]);
    }
    printf("|\n");
    printf("Temps bulles : %lf \n", (double)(t2-t1)/(double)clk_tck);
    printf("Temps insert : %lf \n", (double)(t3-t2)/(double)clk_tck);
    printf("Temps select : %lf \n", (double)(t4-t3)/(double)clk_tck);

    /* Stockage des résultats dans le fichier */
    FILE* fichier = NULL;
    fichier = fopen("temps.csv", "a");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier mémoire !\n");
    } else {
        fprintf(fichier, "%d; %lf; %lf; %lf\n", n, (double)(t2-t1)/(double)clk_tck, (double)(t4-t3)/(double)clk_tck, (double)(t3-t2)/(double)clk_tck);
        printf("Résultats enregistrés dans le fichier temps.csv !\n");
        fclose(fichier);
    }
}
