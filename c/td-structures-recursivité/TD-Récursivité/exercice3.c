/**Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int palindrome_rec(char mot[], int n) {
    if (n <= 1) {
        return 1;
    }
    return (mot[0] == mot[n-1] && palindrome_rec(mot + 1, n - 2));
}

int palindrome(char mot[]) {
    int longueur = 0;
    if (mot) {
        longueur = strlen(mot);
    }
    return (palindrome_rec(mot, longueur));
}

int main(void) {
    char mot[100];
    printf("Entrez votre mot : ");
    scanf("%s", mot);
    int a = palindrome(mot);
    if (a == 1) {
        printf("Palindrome !\n");
    } else {
        printf("Ce n'est pas un palindrome, désolé...\n");
    }
}