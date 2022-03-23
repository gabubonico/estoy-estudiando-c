#include <stdio.h>
#include <string.h>

int main() {
	char cadena[11] = "Hola mundo";	
	if(strcmp(cadena, "Hola mundo") == 0){
		printf("la cadena es igual\n");
	} else {
		printf("la cadena no es igual\n");
	}
}
