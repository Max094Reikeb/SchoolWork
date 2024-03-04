#include <stdio.h>

int main(int argc, char** argv) {
    if (argc == 0)
        printf("programme lancé sans arguments\n");
    else
    {
        for(int i=0; i<argc; i++)
            printf("argument n° %d est : %s\n", i, argv[i]);
    }
    return 0;
}
