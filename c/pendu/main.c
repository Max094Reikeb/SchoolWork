#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//#include "dico.h"
int nombreAleatoire(int nombreMax) {
    srand(time(NULL));
    return (rand() % nombreMax);
}

int piocherMot(char *motPioche) {
    FILE* dico = NULL;
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
    dico = fopen("dico.txt", "r");

    if (dico == NULL) {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0;
    }

    do {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n') {
            nombreMots++;
        }
    } while(caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots);

    rewind(dico);
    while (numMotChoisi > 0) {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }

    fgets(motPioche, 100, dico);

    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);

    return 1;
}

char lireCaractere() {
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);

    while (getchar() != '\n') ;

    return caractere;
}


int gagne(int lettreTrouvee[], long tailleMot) {
    long i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < tailleMot ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[]) {
    long i = 0;
    int bonneLettre = 0;

    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }

    return bonneLettre;
}


int main(int argc, char* argv[]) {
    char lettre = 0;
    char motSecret[100] = {0};
    int *lettreTrouvee = NULL;
    long coupsRestants = 10;
    long i = 0;
    long tailleMot = 0;

    printf("Bienvenue dans le Pendu !\n\n");

    if (!piocherMot(motSecret)) {
        exit(0);
    }

    tailleMot = strlen(motSecret);

    lettreTrouvee = malloc(tailleMot * sizeof(int));
    if (lettreTrouvee == NULL) {
        exit(0);
    }

    for (i = 0 ; i < tailleMot ; i++) {
        lettreTrouvee[i] = 0;
    }

    while (coupsRestants > 0 && !gagne(lettreTrouvee, tailleMot)) {
        printf("\n\nIl vous reste %ld coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");

        for (i = 0 ; i < tailleMot ; i++) {
            if (lettreTrouvee[i]) {
                printf("%c", motSecret[i]);
            } else {
                printf("*");
            }
        }

        printf("\nProposez une lettre : ");
        lettre = lireCaractere();

        if (!rechercheLettre(lettre, motSecret, lettreTrouvee)) {
            coupsRestants--;
        }
    }


    if (gagne(lettreTrouvee, tailleMot)) {
        printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
    } else {
        printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);
    }

    free(lettreTrouvee);

    return 0;
}