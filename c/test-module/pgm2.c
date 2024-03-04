#include "a/a.h"
#include "b/b.h"
#include <stdio.h>

void fonctionA(){
	printf("Bien le bonjour de fonction A\n");
}

void fonctionB(){
	printf("Bonjour de fonction B\n");
}

int main(){
	fonctionA();
	fonctionB();
	return 0;
}
