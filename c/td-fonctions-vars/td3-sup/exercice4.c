/**Packages */
#include <stdio.h>
#include <string.h>

int main() {
	char mot[32];
	int indice = 0;
	int nonEspaceTrouve = 0;
	int j = 0;

	printf("Entrez votre mot : ");
	scanf("%s", mot);

	int l = strlen(mot);

	while (! nonEspaceTrouve) {
		for (int i = 0; i < l; i++) {
			if (mot[i] == ' ') {
				indice = indice + 1;
			} else {
				nonEspaceTrouve = 1;
			}
		}
	}

	for (int j = indice; j < l; j++) {
		mot[j-indice] = mot[j];
	}

	printf("Votre mot : %s\n", mot);
}
