#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int pgcd(int n, int m) {
    int a = n-m;
    if (n == m) {
        a = 0;
        return a;
    } else if (a == 1) {
        return a;
    } else if (a >= m) {
        return (pgcd(a, m));
    } else {
        return (pgcd(n, a));
    }
}

int nbrePremierPourcentage(int n) {
    int m = 0;
    for (int i = 2; i <= n; i++) {
        if (pgcd(n, i) == 1) {
            m++;
        }
    }
    m = m+1;
    int result = (m*100)/n;
    return result;
}

int main(void) {
    int n;
    printf("Entrez le nombre n choisi : ");
    scanf("%d", &n);
    int r = nbrePremierPourcentage(n);
    printf("\nIl y a %d pourcent de nombres premiers entre 2 et %d !\n", r, n);
    return 0;
}
