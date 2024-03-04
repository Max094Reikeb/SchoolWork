/**Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**============================================================Fonction Ligne */
int ligne(int n) {
    for(int i=0; i<n; i++) {
        printf("*\n");
    }
}

/**============================================================Fonction Carré 1 */
int carre1(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

/**============================================================Fonction Triangle 1 */
int triangle1(int n) {
    for(int i=1; i<(n+1); i++) {
        for(int j=1; j<(i+1); j++) {
            printf("*");
        }
    printf("\n");
    }
}

/**============================================================Fonction Carré 2 */
int carre2(int n) {
    for(int i=0; i<n; i++) {
        printf("*");
    }
    printf("\n");
    for(int k=0; k<(n-2); k++) {
        printf("*");
        for(int l=0; l<(n-2); l++) {
            printf(" ");
        }
        printf("*\n");
    }
    for(int i=0; i<n; i++) {
        printf("*");
    }
    printf("\n");
}

/**============================================================Fonction Triangle 2 */
int triangle2(int n) {
    for(int i=1; i<(n+1); i++) {
        for(int j=1; j<(n-i+1); j++) {
            printf(" ");
        }
        for(int k=1; k<(i+1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

/**============================================================Fonction Croix */
int croix(int n) {
    int vu = n/2;
    int v = floor(vu);
    int i;
    char* buf = malloc(2*v+1);
    memset(buf,' ',2*v+1+1);
    buf[2*v+1]='\0';
    for(i=0; i<2*v+1; i++) {
        buf[i]='*';
        buf[2*v-i]='*';
        printf("%s\n",buf);
        buf[i]=' ';
        buf[2*v-i]=' ';
    }
    free(buf);
}

/**============================================================Fonction principale */
int main(){
    int n;
    char e[10];
    printf("Quelle figure voulez vous faire ? ");
    scanf("%s", e);
    printf("Quelle sera la taille de votre figure ? ");
    scanf("%d", &n);
    if (strcmp(e,(char*)"ligne") == 0) {
        ligne(n);
    } else if (strcmp(e,(char*)"carre1") == 0) {
        carre1(n);
    } else if (strcmp(e,(char*)"triangle1") == 0) {
        triangle1(n);
    } else if (strcmp(e,(char*)"carre2") == 0) {
        carre2(n);
    } else if (strcmp(e,(char*)"triangle2") == 0) {
        triangle2(n);
    } else if (strcmp(e,(char*)"croix") == 0) {
        croix(n);
    } else {
        printf("Figure invalide !");
    }
    printf("\n");
}
