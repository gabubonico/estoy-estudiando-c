#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	char cad[256] = "hola";
	char *p;
	p = cad;

	printf("%s \n", p);

	strcpy(cad, "adios");

	char *p2;
	p2 = malloc(256 * sizeof(char));
	p2 = "adios";

	if (p == p2) printf("Iguales \n");
	else printf("Diferentes \n"); // da diferente porque apuntan a direcciones diferentes

	// TODO mirar strdup
}
