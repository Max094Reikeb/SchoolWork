#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef int Telement;
typedef struct cel{
    Telement data;
    struct cel *next;
}Liste;

int main() {
    Liste l;
    Liste *p = &l;
    l.data = 25;
    liste l2;
    l2.data = 13;
    l2.next = NULL;
    l.next = &l2;
    while(p != NULL) {
        printf("Data: %d\n", (*p).data);
        p = (*p).next;
    }

    return 0;
}
