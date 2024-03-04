/* Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

              //Joueur 1      Joueur 2
//Carré 1        1              9
//Triangle 1     2              10
// Losange 1     3              11
// Rond 1        4              12
// Rond 2        5              13
// L0sange 2     6              14
// Triangle 2    7              15
// Carré 2       8              16


int showTable(int *tableau) {
    for (int i=0; i<10; i++) {
        if (tableau[i] == 0) {
            printf("*");
        } else if (tableau[i] == 1) {
            printf("C");
        } else if (tableau[i] == 2) {
            printf("T");
        } else if (tableau[i] == 3) {
            printf("L");
        } else if (tableau[i] == 4) {
            printf("R");
        } else if (tableau[i] == 5) {
            printf("R");
        } else if (tableau[i] == 6) {
            printf("L");
        } else if (tableau[i] == 7) {
            printf("T");
        } else if (tableau[i] == 8) {
            printf("C");
        } else if (tableau[i] == 9){
            printf("c");
        } else if (tableau[i] == 10) {
            printf("t");
        } else if (tableau[i] == 11) {
            printf("l");
        } else if (tableau[i] == 12) {
            printf("r");
        } else if (tableau[i] == 13) {
            printf("r");
        } else if (tableau[i] == 14) {
            printf("l");
        } else if (tableau[i] == 15) {
            printf("t");
        } else if (tableau[i] == 16) {
            printf("c");
        } else {
            return -1;
            printf("Internal error. Relaunch game or download it again.");
        }
    }
    printf("\n");
    for (int j=10; j<20; j++) {
        if (tableau[j] == 0) {
            printf("*");
        } else if (tableau[j] == 1) {
            printf("C");
        } else if (tableau[j] == 2) {
            printf("T");
        } else if (tableau[j] == 3) {
            printf("L");
        } else if (tableau[j] == 4) {
            printf("R");
        } else if (tableau[j] == 5) {
            printf("R");
        } else if (tableau[j] == 6) {
            printf("L");
        } else if (tableau[j] == 7) {
            printf("T");
        } else if (tableau[j] == 8) {
            printf("C");
        } else if (tableau[j] == 9){
            printf("c");
        } else if (tableau[j] == 10) {
            printf("t");
        } else if (tableau[j] == 11) {
            printf("l");
        } else if (tableau[j] == 12) {
            printf("r");
        } else if (tableau[j] == 13) {
            printf("r");
        } else if (tableau[j] == 14) {
            printf("l");
        } else if (tableau[j] == 15) {
            printf("t");
        } else if (tableau[j] == 16) {
            printf("c");
        } else {
            return -1;
            printf("Internal error. Relaunch game or download it again.");
        }
    }
    printf("\n");
    for (int k=20; k<30; k++) {
         if (tableau[k] == 0) {
            printf("*");
        } else if (tableau[k] == 1) {
            printf("C");
        } else if (tableau[k] == 2) {
            printf("T");
        } else if (tableau[k] == 3) {
            printf("L");
        } else if (tableau[k] == 4) {
            printf("R");
        } else if (tableau[k] == 5) {
            printf("R");
        } else if (tableau[k] == 6) {
            printf("L");
        } else if (tableau[k] == 7) {
            printf("T");
        } else if (tableau[k] == 8) {
            printf("C");
        } else if (tableau[k] == 9){
            printf("c");
        } else if (tableau[k] == 10) {
            printf("t");
        } else if (tableau[k] == 11) {
            printf("l");
        } else if (tableau[k] == 12) {
            printf("r");
        } else if (tableau[k] == 13) {
            printf("r");
        } else if (tableau[k] == 14) {
            printf("l");
        } else if (tableau[k] == 15) {
            printf("t");
        } else if (tableau[k] == 16) {
            printf("c");
        } else {
            return -1;
            printf("Internal error. Relaunch game or download it again.");
        }
    }
    printf("\n");
    for (int l=30; l<40; l++) {
         if (tableau[l] == 0) {
            printf("*");
        } else if (tableau[l] == 1) {
            printf("C");
        } else if (tableau[l] == 2) {
            printf("T");
        } else if (tableau[l] == 3) {
            printf("L");
        } else if (tableau[l] == 4) {
            printf("R");
        } else if (tableau[l] == 5) {
            printf("R");
        } else if (tableau[l] == 6) {
            printf("L");
        } else if (tableau[l] == 7) {
            printf("T");
        } else if (tableau[l] == 8) {
            printf("C");
        } else if (tableau[l] == 9){
            printf("c");
        } else if (tableau[l] == 10) {
            printf("t");
        } else if (tableau[l] == 11) {
            printf("l");
        } else if (tableau[l] == 12) {
            printf("r");
        } else if (tableau[l] == 13) {
            printf("r");
        } else if (tableau[l] == 14) {
            printf("l");
        } else if (tableau[l] == 15) {
            printf("t");
        } else if (tableau[l] == 16) {
            printf("c");
        } else {
            return -1;
            printf("Internal error. Relaunch game or download it again.");
        }
    }
    printf("\n");
    for (int m=40; m<50; m++) {
         if (tableau[m] == 0) {
            printf("*");
        } else if (tableau[m] == 1) {
            printf("C");
        } else if (tableau[m] == 2) {
            printf("T");
        } else if (tableau[m] == 3) {
            printf("L");
        } else if (tableau[m] == 4) {
            printf("R");
        } else if (tableau[m] == 5) {
            printf("R");
        } else if (tableau[m] == 6) {
            printf("L");
        } else if (tableau[m] == 7) {
            printf("T");
        } else if (tableau[m] == 8) {
            printf("C");
        } else if (tableau[m] == 9){
            printf("c");
        } else if (tableau[m] == 10) {
            printf("t");
        } else if (tableau[m] == 11) {
            printf("l");
        } else if (tableau[m] == 12) {
            printf("r");
        } else if (tableau[m] == 13) {
            printf("r");
        } else if (tableau[m] == 14) {
            printf("l");
        } else if (tableau[m] == 15) {
            printf("t");
        } else if (tableau[m] == 16) {
            printf("c");
        } else {
            return -1;
            printf("Internal error. Relaunch game or download it again.");
        }
    }
    printf("\n");
    for (int n=50; n<60; n++) {
         if (tableau[n] == 0) {
            printf("*");
        } else if (tableau[n] == 1) {
            printf("C");
        } else if (tableau[n] == 2) {
            printf("T");
        } else if (tableau[n] == 3) {
            printf("L");
        } else if (tableau[n] == 4) {
            printf("R");
        } else if (tableau[n] == 5) {
            printf("R");
        } else if (tableau[n] == 6) {
            printf("L");
        } else if (tableau[n] == 7) {
            printf("T");
        } else if (tableau[n] == 8) {
            printf("C");
        } else if (tableau[n] == 9){
            printf("c");
        } else if (tableau[n] == 10) {
            printf("t");
        } else if (tableau[n] == 11) {
            printf("l");
        } else if (tableau[n] == 12) {
            printf("r");
        } else if (tableau[n] == 13) {
            printf("r");
        } else if (tableau[n] == 14) {
            printf("l");
        } else if (tableau[n] == 15) {
            printf("t");
        } else if (tableau[n] == 16) {
            printf("c");
        } else {
            return -1;
            printf("Internal error. Relaunch game or download it again.");
        }
    }
    printf("\n");
    for (int o=60; o<70; o++) {
         if (tableau[o] == 0) {
            printf("*");
        } else if (tableau[o] == 1) {
            printf("C");
        } else if (tableau[o] == 2) {
            printf("T");
        } else if (tableau[o] == 3) {
            printf("L");
        } else if (tableau[o] == 4) {
            printf("R");
        } else if (tableau[o] == 5) {
            printf("R");
        } else if (tableau[o] == 6) {
            printf("L");
        } else if (tableau[o] == 7) {
            printf("T");
        } else if (tableau[o] == 8) {
            printf("C");
        } else if (tableau[o] == 9){
            printf("c");
        } else if (tableau[o] == 10) {
            printf("t");
        } else if (tableau[o] == 11) {
            printf("l");
        } else if (tableau[o] == 12) {
            printf("r");
        } else if (tableau[o] == 13) {
            printf("r");
        } else if (tableau[o] == 14) {
            printf("l");
        } else if (tableau[o] == 15) {
            printf("t");
        } else if (tableau[o] == 16) {
            printf("c");
        } else {
            return -1;
            printf("Internal error. Relaunch game or download it again.");
        }
    }
    printf("\n");
    for (int p=70; p<80; p++) {
         if (tableau[p] == 0) {
            printf("*");
        } else if (tableau[p] == 1) {
            printf("C");
        } else if (tableau[p] == 2) {
            printf("T");
        } else if (tableau[p] == 3) {
            printf("L");
        } else if (tableau[p] == 4) {
            printf("R");
        } else if (tableau[p] == 5) {
            printf("R");
        } else if (tableau[p] == 6) {
            printf("L");
        } else if (tableau[p] == 7) {
            printf("T");
        } else if (tableau[p] == 8) {
            printf("C");
        } else if (tableau[p] == 9){
            printf("c");
        } else if (tableau[p] == 10) {
            printf("t");
        } else if (tableau[p] == 11) {
            printf("l");
        } else if (tableau[p] == 12) {
            printf("r");
        } else if (tableau[p] == 13) {
            printf("r");
        } else if (tableau[p] == 14) {
            printf("l");
        } else if (tableau[p] == 15) {
            printf("t");
        } else if (tableau[p] == 16) {
            printf("c");
        } else {
            return -1;
            printf("Internal error. Relaunch game or download it again.");
        }
    }
    printf("\n");
    for (int q=80; q<90; q++) {
         if (tableau[q] == 0) {
            printf("*");
        } else if (tableau[q] == 1) {
            printf("C");
        } else if (tableau[q] == 2) {
            printf("T");
        } else if (tableau[q] == 3) {
            printf("L");
        } else if (tableau[q] == 4) {
            printf("R");
        } else if (tableau[q] == 5) {
            printf("R");
        } else if (tableau[q] == 6) {
            printf("L");
        } else if (tableau[q] == 7) {
            printf("T");
        } else if (tableau[q] == 8) {
            printf("C");
        } else if (tableau[q] == 9){
            printf("c");
        } else if (tableau[q] == 10) {
            printf("t");
        } else if (tableau[q] == 11) {
            printf("l");
        } else if (tableau[q] == 12) {
            printf("r");
        } else if (tableau[q] == 13) {
            printf("r");
        } else if (tableau[q] == 14) {
            printf("l");
        } else if (tableau[q] == 15) {
            printf("t");
        } else if (tableau[q] == 16) {
            printf("c");
        } else {
            return -1;
            printf("Internal error. Relaunch game or download it again.");
        }
    }
    printf("\n");
    for (int r=90; r<100; r++) {
         if (tableau[r] == 0) {
            printf("*");
        } else if (tableau[r] == 1) {
            printf("C");
        } else if (tableau[r] == 2) {
            printf("T");
        } else if (tableau[r] == 3) {
            printf("L");
        } else if (tableau[r] == 4) {
            printf("R");
        } else if (tableau[r] == 5) {
            printf("R");
        } else if (tableau[r] == 6) {
            printf("L");
        } else if (tableau[r] == 7) {
            printf("T");
        } else if (tableau[r] == 8) {
            printf("C");
        } else if (tableau[r] == 9){
            printf("c");
        } else if (tableau[r] == 10) {
            printf("t");
        } else if (tableau[r] == 11) {
            printf("l");
        } else if (tableau[r] == 12) {
            printf("r");
        } else if (tableau[r] == 13) {
            printf("r");
        } else if (tableau[r] == 14) {
            printf("l");
        } else if (tableau[r] == 15) {
            printf("t");
        } else if (tableau[r] == 16) {
            printf("c");
        } else {
            return -1;
            printf("Internal error. Relaunch game or download it again.");
        }
    }
    printf("\n");
    return 0;
}

//Choix du joueur : Jouer ou voir les règles.
int menu(void) {
    int choixMenu;
    printf("|------CHOIX-----|\n");
    printf("| 1 || Jouer     |\n");
    printf("| 2 || Règles    |\n");
    printf("|----------------|\n");
    printf("Votre choix > ");
    scanf("%d", &choixMenu);
    return choixMenu;
}

int main(void) {
    switch (menu()) { //On regarde le choix du joueur
        case 2: //Si le joueur veut voir les règles
            system("clear"); //On clear l'écran et on affiche les règles
            printf("Voici un rappel des règles du jeu de Traverse :\n");
            printf("Traverse se joue à deux joueurs en général.\n");
            printf("Chaque joueur possède divers pions de formes différentes. (carré, triangle, losange et rond)\n");
            printf("Le but étant de bouger ses pions dans la zone de départ adverse.\n");
            printf("Pour se faire, chaque joueur déplace, tour à tour un seul pion qu'il souhaite, tant que celui-ci ne partage pas la même case qu'un autre pion.\n");
            printf("Les mouvements des pions sont différents :\n");
            printf("- Les carrés se déplacent horizontalement et verticalement,\n");
            printf("- Les losanges se déplacent en diagonale,\n");
            printf("- Les triangles se déplacent en diagonale, vers l'avant et tout droit vers l'arrière,\n");
            printf("- Les cercles se déplacent dans les 8 directions.\n");
            printf("Passer un tour n'est pas autorisé, sauf si le joueur est piégé et ne peut bouger ses pions.\n");
            printf("(Dans ce cas, le joueur passe son tour jusqu'à ce qu'il puisse jouer un coup autorisé)\n");
            printf("Un joueur a le droit de faire sauter son pion plusieurs fois sur des autres pions (adverses ou non) sans que ces pions soient enlevés du plateau.\n");
            printf("Un pion peut librement quitter et rentrer dans sa zone d'arrivée, mais il ne peut rester dans une case de bordure sans la quitter au tour suivant.\n");
            printf("la partie s'arrête quand :\n");
            printf("- Un joueur arrive à placer l'intégralité de ses pions dans la zone de départ adverse,\n");
            printf("- Au bout du 31eme tour, un des joueurs comporte au moins un pion dans sa zone de départ,\n");
            printf("- Lorsqu'une même position de jeu se présente 3 fois, afin d'éviter les matchs interminables. La partie est alors déclarée nulle.\n");
            system("PAUSE"); //On attend que l'utilisateur appuie sur une touche
            menu(); //On fait en sorte que l'utilisateur retourne au menu principal de choix
            break;
        case 1: //Si le joueur choisi de jouer
            system("clear"); //On efface l'écran et on execute le reste de la procedure
            break;
    }
    
    //Initialisation du tableau
    int *tableau = NULL;
    tableau = malloc(100 * sizeof(int));
    if (tableau == NULL) {
        exit(0);
    }

    //Remplissage du tableau par les valeur de défaut
    for (int i = 0; i < 101; i++) {
        tableau[i] = 0;
    }

    //Remplissage du tableau par les valeurs du joueur 2
    tableau[1] = 9;
    tableau[2] = 10;
    tableau[3] = 11;
    tableau[4] = 12;
    tableau[5] = 13;
    tableau[6] = 14;
    tableau[7] = 15;
    tableau[8] = 16;
    
    //Remplissage du tableau par les valeurs du joueur 1
    tableau[91] = 1;
    tableau[92] = 2;
    tableau[93] = 3;
    tableau[94] = 4;
    tableau[95] = 5;
    tableau[96] = 6;
    tableau[97] = 7;
    tableau[98] = 8;

    int joueur = 1;
    int turn = 1;
    char choix[10];
    bool game = true;
    bool move = false;

    do {
        system("clear");
        showTable(tableau); //On affiche le tableau tel qu'il est au début du jeu

        printf("================\n");
        printf("C'est le tour numéro %d.\n", turn);
        printf("C'est au tour du joueur %d de jouer !\n", joueur);
        printf("================\n");
        printf("Faites 'undo' pour revenir en arrière.\n");
        printf("> ");
        scanf("%s", choix);
    
    nextTurn:
        if (move) {
            if (joueur == 1) {
                joueur = 2;
            } else {
                joueur = 1;
            }
            turn = turn + 1;
        }
        system("PAUSE");
    } while(game);
}