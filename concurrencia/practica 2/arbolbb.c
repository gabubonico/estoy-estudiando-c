/*
 * arbolbb.c
 *
 *  Created on: 15 mar. 2021
 *      Author: Laura
 */
#include <stdio.h>
#include <stdlib.h>
#include "arbolbb.h"


// Inicializa la estructura a NULL.
void Crear(T_Arbol* arbol_ptr){
	arbol_ptr = NULL;
}

// Destruye la estructura utilizada.
// recursividad: primero se propaga y luego se libera
void Destruir(T_Arbol *arbol_ptr){
	if ((*arbol_ptr)->izq != NULL && (*arbol_ptr)->der != NULL) {
		Destruir((*arbol_ptr)->izq);	
		Destruir((*arbol_ptr)->der);	
	}
	free(arbol_ptr);
}

// Inserta num en el arbol

int buscar (T_Arbol * a, unsigned num){
	if (a == NULL) {
		return 0;
	} else if ((*a)->dato < num) {
		return buscar((*a)->der, num);
	} else if ((*a)->dato > num) {
		return buscar((*a)->izq, num);
	} else {
		return 1;
	}
}

void insertar_recursivo(T_Arbol * a, unsigned num) {
	if (a == NULL) {
		(*a)->dato = num;
	} else if ((*a)->dato < num) {
		insertar_recursivo((*a)->der, num);	
	} else if ((*a)->dato > num) {
		insertar_recursivo((*a)->izq, num);	
	}
}

void insertar(T_Arbol *arbol_ptr,unsigned num)
{
	if (arbol_ptr == NULL) {
		(*arbol_ptr)->dato = num;
	} else {
		if (buscar(arbol_ptr, num) == 1) {
			exit(0);
		} else {
			insertar_recursivo(arbol_ptr, num);
		}
	}
	
	
}
// Muestra el contenido del árbol en InOrden
void Mostrar(T_Arbol arbol){

}


// Guarda en disco el contenido del arbol - recorrido InOrden
void Salvar(T_Arbol arbol, FILE *fichero){

	
}
