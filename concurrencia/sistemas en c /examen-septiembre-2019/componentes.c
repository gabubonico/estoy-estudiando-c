#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Componentes.h"

/*
typedef struct elemLista {
        long codigoComponente;
        char textoFabricante[MAX_CADENA];
        struct elemLista * sig;
} Componente;

typedef Componente * Lista;
*/

/*
La rutina Lista_Vacia devuelve 1 si la lista que se le pasa
como parametro esta vacia y 0 si no lo esta.
*/
int Lista_Vacia(Lista lista) {
	int resul = 0;

	if (lista == NULL) {
		resul = 1;	
	}
	return resul;
}

/*Num_Elementos es una funcion a la que se le pasa un puntero a una lista 
y devuelve el numero de elementos de dicha lista.
*/
int Num_Elementos(Lista lista) {
	int resul = 0;

	Lista ptr = lista;
	if (ptr != NULL) {
		while (ptr != NULL) {
			resul++;
			*ptr = *ptr->sig;
		}	
	}
	return resul;
}

/*
La rutina Adquirir_Componente se encarga de recibir los datos de un nuevo 
componente (codigo y texto) que se le introducen por teclado y devolverlos 
por los parametros pasados por referencia "codigo" y "texto".
*/
 void Adquirir_Componente(long *codigo, char *texto) {
	printf("Codigo: \n");
	scanf("%ld", codigo);
	printf("Texto: \n");
	scanf("%s", texto);
 }

/*
La funcion Lista_Imprimir se encarga de imprimir por pantalla la lista 
enlazada completa que se le pasa como parametro.
*/
void Lista_Imprimir(Lista lista) {
	Lista ptr = lista;

	while (ptr != NULL) {
		printf("Codigo: %ld, texto: %s \n", lista->codigoComponente, lista->textoFabricante);	
		*ptr = *ptr->sig;
	}
}

/*
La funcion Lista_Salvar se encarga de guardar en el fichero binario 
"examen.dat" la lista enlazada completa que se le pasa como parametro. 
Para cada nodo de la lista, debe almacenarse en el fichero
el código y el texto de la componente correspondiente.
*/
void Lista_Salvar(Lista lista) {

}


/*
La funcion Lista_Crear crea una lista enlazada vacia
de nodos de tipo Componente.
*/
Lista Lista_Crear() {
	return NULL;
}

/*
La funcion Lista_Agregar toma como parametro un puntero a una lista,
el código y el texto de un componente y  anyade un nodo al final de 
la lista con estos datos.
*/
void Lista_Agregar(Lista *lista, long codigo, char* textoFabricante) {
	Componente *c = malloc(sizeof(struct elemLista));
	Lista *ptr = lista;

	(*c).codigoComponente = codigo;
	strcpy((*c).textoFabricante, textoFabricante);
	(*c).sig = NULL;
	
	printf("debug, el texto intruducido es %s\n", (*ptr)->textoFabricante);

	while ((*ptr)->sig != NULL) {
		printf("debug");
		(*ptr) = (*ptr)->sig;
	}
	(*ptr) = (*ptr)->sig;
}

/*
Lista_Extraer toma como parametro un puntero a una Lista y elimina el
Componente que se encuentra en su ultima posicion.
*/
void Lista_Extraer(Lista *lista) {
	Lista *ptr = lista;
	
	while ((*ptr)->sig != NULL) {
		(*ptr) = (*ptr)->sig;
	}
	free((*ptr)->textoFabricante);
	free(*ptr);
}

/*
Lista_Vaciar es una funcion que toma como parametro un puntero a una Lista
y elimina todos sus Componentes.
*/
void Lista_Vaciar(Lista *lista) {
	while (lista != NULL) {
		Lista_Extraer(lista);
	}
}
