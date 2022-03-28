#include <stdio.h>

int vg; // variable global esta en memoria

int main () {
	int vl; // variable local esta en el stack
	int * p; // variable puntero a entero
	vl = 5; // asi la direccion de memoria donde esta alocada vl vale 5
	p = &vl; // ahora el puntero p apunta a la direccion de memoria de vl

	printf("%p %p %p %d %d\n", &vl, &p, p, vl, *p);
	
	*p = 8;

	printf("%p %p %p %d %d\n", &vl, &p, p, vl, *p);
}
