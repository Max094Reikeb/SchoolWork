#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

int saisieEntier(){
	char term;
	int n;
	if(scanf("%d%c", &n, &term)!= 2 || !(term=='\n' || term==' ' || term=='\t')){
		fprintf(stderr,"Erreur de saisie");
		exit -1;
	}
	else
		return n;
}

int main(int argc, char** argv){
	int nb;
	nb=saisieEntier();
	printf("%d\n", nb);
	nb=saisieEntier();
	printf("%d\n", nb);
	return 0;
}
	
