/* Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "aTM.h"

void aTM(int *newTable, int sizeofTable) {
    printf("Votre tableau :\n");
    for (int i = 0; i < sizeofTable; i++) {
        printf("| %d ", newTable[i]);
    }
    printf("|\n");
    free(newTable);
}