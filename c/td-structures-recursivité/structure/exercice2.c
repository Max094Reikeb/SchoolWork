/**Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct compAlg {
	double dbl_reel;
	double dbl_imaginaire;
}compA;

typedef struct compExpo {
	double dbl_module;
	double dbl_theta;
}compE;

compE formAlgformExpo(compA a) {
	compE n;
	n.dbl_module = sqrt(pow(a.dbl_reel, 2) + pow(a.dbl_imaginaire, 2));
	n.dbl_theta = atan(a.dbl_imaginaire / a.dbl_reel);
	return n;
}

compA formExpoformAlg(compE e) {
	compA n;
	n.dbl_reel = e.dbl_module * cos(e.dbl_theta);
	n.dbl_imaginaire = e.dbl_module * sin(e.dbl_theta);
	return n;
}

compA algPlusalg(compA a, compA b) {
	compA n;
	n.dbl_reel = a.dbl_reel + b.dbl_reel;
	n.dbl_imaginaire = a.dbl_imaginaire + b.dbl_imaginaire;
	return n;
}

compE expoPlusexpo(compE e, compE f) {
	compA n;
	compE E;
	n.dbl_reel = (e.dbl_module * cos(e.dbl_theta)) + (f.dbl_module * cos(f.dbl_theta));
	n.dbl_imaginaire = (e.dbl_module * sin(e.dbl_theta)) + (f.dbl_module * sin(f.dbl_theta));
	E = formAlgformExpo(n);
	return E;
}

int menu(void) {
    int choixMenu;
    printf("|----------------MENU----------------|\n");
    printf("| 1 || Algébrique -> Exponentielle   |\n");
    printf("| 2 || Exponentielle -> Algébrique   |\n");
    printf("| 3 || Algébrique + Algébrique       |\n");
	printf("| 4 || Exponentielle + Exponentielle |\n");
    printf("|------------------------------------|\n");
    printf("Votre choix > ");
    scanf("%d", &choixMenu);
    return choixMenu;
}

int main(void) {
	compA A, b, c;
	compE E, f, g;
    switch (menu()) {
        case 1:
			printf("Entrez votre nombre complexe a+ib\n");
			printf("a = ");
			scanf("%lf", &A.dbl_reel);
			printf("b = ");
			scanf("%lf", &A.dbl_imaginaire);
			printf("Forme algébrique : %lf+i%lf\n", A.dbl_reel, A.dbl_imaginaire);
			E = formAlgformExpo(A);
			printf("Forme exponentielle : |%lf|e^(i%lf)\n", E.dbl_module, E.dbl_theta);
            break;
        case 2:
			printf("Entrez votre nombre complexe |x|e^(iy)\n");
			printf("x = ");
			scanf("%lf", &E.dbl_module);
			printf("y = ");
			scanf("%lf", &E.dbl_theta);
			printf("Forme exponentielle : |%lf|e^(i%lf)\n", E.dbl_module, E.dbl_theta);
			A = formExpoformAlg(E);
			printf("Forme algébrique : %lf+i%lf\n", A.dbl_reel, A.dbl_imaginaire);
            break;
        case 3:
			printf("Entrez votre premier nombre complexe a1+ib1\n");
			printf("a1 = ");
			scanf("%lf", &A.dbl_reel);
			printf("b1 = ");
			scanf("%lf", &A.dbl_imaginaire);
			printf("Entrez votre second nombre complexe a2+ib2\n");
			printf("a2 = ");
			scanf("%lf", &b.dbl_reel);
			printf("b2 = ");
			scanf("%lf", &b.dbl_imaginaire);
			A = algPlusalg(A, b);
			printf("(a1+ib1) + (a2+ib2) = %lf+i%lf\n", A.dbl_reel, A.dbl_imaginaire);
            break;
		case 4:
			printf("Entrez votre premier nombre complexe |x1|e^(iy1)\n");
			printf("x1 = ");
			scanf("%lf", &E.dbl_module);
			printf("y1 = ");
			scanf("%lf", &E.dbl_theta);
			printf("Entrez votre second nombre complexe |x2|e^(iy2)\n");
			printf("x2 = ");
			scanf("%lf", &f.dbl_module);
			printf("y2 = ");
			scanf("%lf", &f.dbl_theta);
			E = expoPlusexpo(E, f);
			printf("|x1|e^(iy1) + |x2|e^(iy2) = |%lf|e^(i%lf)\n", E.dbl_module, E.dbl_theta);
			break;
        default:
            printf("Aucun choix n'a été fait\n");
            break;
    }
}

