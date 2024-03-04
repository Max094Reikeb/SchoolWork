/**Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int tableMultiplication(int n) {
	for (int i = 0; i < 11; i++) {
		int z = n*i;
		printf("%d * %d = %d", n, i, z);
		printf("\n");
	}
}

float fonction(float x) {
    float z = pow(x, 3);
    float y = 12*(pow(x, 2));
    float result = z + y + 1;
    return result;
}

float doublesolEquation(void) {
    float a = -15;
    float b = -10;
    float m;
    float e = pow(10, -5);
    while (((b) - (a)) > e) {
        m = (a + b) / 2;
        float result1 = fonction(a);
        float result2 = fonction(m);
        if ((result1 * result2) < 1) {
            b = m;
        } else {
            a = m;
        }
    }
    printf("x1 = %f\n", a);
    printf("x2 = %f\n", b);
    return 0;
}

int factorielle(int n) {
	int z = 1;
	if (n >= 2) {
		for (int i = 2; i <= n; i++) {
			z = z*i;
		}
	}
	printf("La factorielle de %d est %d\n", n, z);	
}

int menu(void) {
    int choixMenu;
    printf("|-------------MENU-------------|\n");
    printf("| 1 || Table de Multiplication |\n");
    printf("| 2 || Solution de l'équation  |\n");
    printf("| 3 || Factorielle             |\n");
    printf("|------------------------------|\n");
    printf("Votre choix > ");
    scanf("%d", &choixMenu);
    return choixMenu;
}

int main(void) {
	int n;
    switch (menu()) {
        case 1:
            printf("Entrez le nombre dont vous voulez voir la table de multiplication : ");
            scanf("%d", &n);
            tableMultiplication(n);
            break;
        case 2:
            doublesolEquation();
            break;
        case 3:
            printf("Entrez le nombre dont vous voulez voir la factorielle : ");
            scanf("%d", &n);
            factorielle(n);
            break;
        default:
            printf("Aucun choix n'a été fait\n");
            break;
    }
}
