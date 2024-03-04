/* Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int sommeEntiers(int n, int m) {
    int r = n + m;
    printf("On a %d + %d = %d\n", n, m, r);
    return 0;
}

int permutation(int n, int m) {
    int r = n;
    n = m;
    m = r;
    printf("On a n = %d et m = %d\n", n, m);
    return 0;
}

int main(void) {
    int a = 0;
    int n = 0;
    int m = 0;
    printf("Entrez n : ");
    scanf("> %d", &n);
    printf("Entrez m : ");
    scanf("> %d", &m);
    printf("> ");
    scanf("%d", &a);
    if (a == 0) {
        sommeEntiers(n, m);
    } else if (a == 1) {
        permutation(n, m);
    } else {
        printf("ERROR");
        return 1;
    }
    return 0;
}