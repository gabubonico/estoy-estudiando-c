#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "circular.h"

void Crear(LProc *lista) {
	(*lista) =	NULL;
}

void AnyadirProceso(LProc *lista, int idproc) {
	if((*lista) == NULL) {
		(*lista)->pid = idproc;
		(*lista)->sig = (*lista);
	} else {
		struct circular *aux = (struct circular*) malloc(sizeof(struct circular));
		aux->pid = idproc;
		aux->sig = (*lista);
		(*lista)--;
		(*lista)->sig = aux;
	}
}

void MostrarLista(LProc lista) {
	if (lista == NULL) {
		printf("no hay elementos en la lista");	
	} else {
		LProc p = lista;
		while (lista->sig != p) {
			printf("%i", lista->pid);	
			lista = lista->sig;
		}
	}
}

void EjecutarProceso(LProc *lista) {
	if (lista == NULL) {
		printf("la lista esta vacia");
	} else {
		struct circular *aux = (*lista)->sig;
		while (aux->sig != (*lista)) {
			aux = aux->sig;
		}
		aux->sig = (*lista)->sig;
		free(lista);
	}
}

int main(int argc, char const *argv[])
{
    LProc lista;

    Crear(&lista);
    assert(lista == NULL);

    MostrarLista(lista);

    EjecutarProceso(&lista);
    assert(lista == NULL);

    AnyadirProceso(&lista, 1);
    assert(lista->pid == 1);
    assert(lista->sig == lista);

    EjecutarProceso(&lista);
    assert(lista == NULL);

    AnyadirProceso(&lista, 1);
    AnyadirProceso(&lista, 3);
    AnyadirProceso(&lista, 5);
    assert(lista->pid == 1);
    assert(lista->sig->pid == 3);
    assert(lista->sig->sig->pid == 5);
    assert(lista->sig->sig->sig == lista);
    MostrarLista(lista); // 1 3 5

    EjecutarProceso(&lista);
    EjecutarProceso(&lista);
    assert(lista->pid == 5);
    assert(lista->sig == lista);

    MostrarLista(lista); // 5

    return 0;
}
