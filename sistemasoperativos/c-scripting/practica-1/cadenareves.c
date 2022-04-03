#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(char* fuente, char** destino) {
	int n = strlen(fuente);
	int c = 0;

	destino = malloc(sizeof(char) * (n+1));

	for (int i = n; i >= 0 ; i--) {
		**(destino + c) = *(fuente);
		fuente -= i;
		c++;
	}

	return c; 
}

int main() {
  char* fuente = "Esto es una cadena de prueba.); sever la anedac al se otse Y";
  char* destino;

  printf("Número de caracteres revertido: %d\n", reverse(fuente, &destino));
  printf("Cadena original: %s\n", fuente);
  printf("Cadena revertida: %s\n", destino);
  return 0;
}
