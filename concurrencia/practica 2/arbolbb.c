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
void Insertar(T_Arbol *arbol_ptr,unsigned num)
{
	
	
	
}
// Muestra el contenido del árbol en InOrden
void Mostrar(T_Arbol arbol){

}


// Guarda en disco el contenido del arbol - recorrido InOrden
void Salvar(T_Arbol arbol, FILE *fichero){

	
}
