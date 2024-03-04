/**Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int quotient(int a, int b) {
    if (a < b) {
        return 0;
    } else {
        return 1+quotient(a-b, b);
    }
}

int main(void) {
    int a, b, c;
    printf("Entrez deux nombres entiers\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    c = quotient(a, b);
    printf("Le quotient de la division euclidienne de %d par %d est : %d\n", a, b, c);
}