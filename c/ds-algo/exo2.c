#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct stat {
    char c;
    int n;
};

int initialiserTable(char tableChar[], char tableInt[]) {
    tableChar[0] = "a";
    tableChar[1] = "b";
    tableChar[2] = "c";
    tableChar[3] = "d";
    tableChar[4] = "e";
    tableChar[5] = "f";
    tableChar[6] = "g";
    tableChar[7] = "h";
    tableChar[8] = "i";
    tableChar[9] = "j";
    tableChar[10] = "k";
    tableChar[11] = "l";
    tableChar[12] = "m";
    tableChar[13] = "n";
    tableChar[14] = "o";
    tableChar[15] = "p";
    tableChar[16] = "q";
    tableChar[17] = "r";
    tableChar[18] = "s";
    tableChar[19] = "t";
    tableChar[20] = "u";
    tableChar[21] = "v";
    tableChar[22] = "w";
    tableChar[23] = "x";
    tableChar[24] = "y";
    tableChar[25] = "z";
    for (int i = 0; i < 26; i++) {
        tableInt[i] = i+1;
    }
}
    
int afficheTable(char tableChar[], char tableInt[]) {
    int n;
    char e;
    printf("|");
    for (int i = 0; i <= 26; i++) {
        e = tableChar[i];
        printf("%c|", e);
    }
    printf("\n");
    printf("|");
    for (int i = 0; i <= 26; i++) {
        n = tableInt[i];
        printf("%d|", n);
    }
    printf("\n");
    return 0;
}

int main(void) {
    char tableChar[26];
    char tableInt[26];
    initialiserTable(tableChar, tableInt);
    afficheTable(tableChar, tableInt);
}
