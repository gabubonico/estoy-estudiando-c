#include <stdio.h>
#include <stdlib.h>

int main () {
	int a[5] = {1,2,3,4,5};
	int *p;

	p = a; // esto es posible porque un array es equivalente a un puntero (posiciones contiguas de memoria)
	// no se puede hacer a = p
	for (int i = 0; i < 5; i++) {
		printf("p[%d] = %d\n", i, *p); // accedemos a un array con un puntero 
		p++; // esto no suma 1 sino que incrementa el puntero en una unidad de memoria
	}

	int *p2;
	p2 = malloc(5*sizeof(int));
	p2[2] = 5;

	for (int i = 0; i < 5; i++) {
		printf("p2[%d] = %d\n", i, p2[i]); // accedemos a un array con un puntero 
	}
	free(p2);

}
