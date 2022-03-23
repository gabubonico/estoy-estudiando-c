#include <stdio.h>

struct str_libro {
	char titulo[200];
	char autor [200];
	int paginas;
	float precio;
};

int main() {
	struct str_libro libro;

	libro.precio = 5132.51;

	printf("titulo: %s\nAutor: %s\nPrecio: %f\n euros", libro.titulo, libro.autor, libro.precio);
}
