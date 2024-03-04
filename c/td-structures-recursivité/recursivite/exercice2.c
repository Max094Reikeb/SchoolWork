/**Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int reste(int a, int b) {
    if ((a-b) >= b) {
        return reste(a-b, b);
    } else {
        return (a-b);
    }
}

int main(void) {
    int a, b, c;
    printf("Entrez deux nombres entiers\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    c = reste(a, b);
    printf("Le reste de la division euclidienne de %d par %d est : %d\n", a, b, c);
}