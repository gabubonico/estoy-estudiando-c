#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "Tree.h"

const int LONG_MAX = 256;

void inicializarArbol(Tree *ptrTree) {
	*ptrTree = NULL;
}

void insertarComisaria(Tree *ptrTree, char *name, double lat, double lon) {
	if (*ptrTree == NULL) {
		*ptrTree = malloc(sizeof(struct Node));		
		(*ptrTree)->name = malloc(strlen(name) + 1);
		if ((*ptrTree) == NULL || (*ptrTree)->name == NULL) {
			perror("error pidiendo memoria");	
			exit(-1);
		}
		strcpy((*ptrTree)->name, name);
		(*ptrTree)->lat = lat;
		(*ptrTree)->lon = lon;
		(*ptrTree)->left = NULL;
		(*ptrTree)->right = NULL;
	} else if (strcmp(name, (*ptrTree)->name) < 0) {
		insertarComisaria(&((*ptrTree)->left), name, lat, lon);	
	} else if (strcmp(name, (*ptrTree)->name) > 0) {
		insertarComisaria(&((*ptrTree)->right), name, lat, lon);	
	}
}

void mostrarArbol(Tree t) {
	printf("%s (%f %f)\n", t->name, t->lat, t->lon);
	if (t->left != NULL) {
		mostrarArbol(t->left);	
	}
	if (t->right != NULL) {
		mostrarArbol(t->right);	
	}
}

void destruirArbol(Tree *ptrTree) {
	if (*ptrTree != NULL) {
		destruirArbol(&(*ptrTree)->left);
		destruirArbol(&(*ptrTree)->right);
		free((*ptrTree)->name);	
		free((*ptrTree));
		*ptrTree = NULL;
	}
}

void cargarComisarias(char *filename, Tree *ptrTree) {
	FILE * f;
	if ((f = fopen(filename, "r")) == NULL) {
		perror("no se ppuede abrir el fichero");	
		exit(-1);
	}
	char name[256];
	double lat, lon;
	while (fscanf(f, "%[^;];%lf;%lf;\n", name, &lat, &lon) == 3) {
		insertarComisaria(ptrTree, name, lat, lon);	
	}
	fclose(f);
}

void guardarRecursivo(FILE * f, Tree tree) {
	if (tree != NULL) {
		guardarRecursivo(f, tree->left);
		
		size_t tam = strlen(tree->name);
		fwrite(&tam, sizeof(size_t), 1, f);
		fwrite(tree->name, sizeof(char), tam, f);
		fwrite(&(tree->lat), sizeof(double), 1, f);
		fwrite(&(tree->lon), sizeof(double), 1, f);

		guardarRecursivo(f, tree->right);
	}
}

void guardarBinario(char *filename, Tree tree) {
	FILE * f;
	if ((f = fopen(filename, "wb")) == NULL) {
		perror("noseque");	
		exit(-1);
	}
	guardarRecursivo(f, tree);

	fclose(f);
}

// not mine lol
char *localizarComisariaCercanaDistancia(Tree t, double lat, double lon, double *distancia)
{
	if (t != NULL)
	{
		double distIzq, distDer, comCentral;
		char *comisariaIzq, *comisariaDer, *comisariaResult;
		comisariaIzq = localizarComisariaCercanaDistancia(t->left, lat, lon, &distIzq);
		comisariaDer = localizarComisariaCercanaDistancia(t->right, lat, lon, &distDer);
		// Asumimos que está en el centro
		*distancia = fabs(t->lat - lat) + fabs(t->lon - lon);
		comisariaResult = t->name;

		if ((distIzq < distDer) && (distIzq < *distancia))
		{
			*distancia = distIzq;
			comisariaResult = comisariaIzq;
		}
		else if ((distDer < distIzq) && (distDer < *distancia))
		{
			*distancia = distDer;
			comisariaResult = comisariaDer;
		}
	}
	else
	{
		*distancia = LONG_MAX;
	}
}
// Devuelve el nombre de la comisaría más cercana a dada una latitud y longitud.
// Si el árbol está vacío, se devuelve NULL.
// 2.0 pt.
char *localizarComisariaCercana(Tree t, double lat, double lon)
{
	double distancia = LONG_MAX;
	char *resultado = localizarComisariaCercanaDistancia(t, lat, lon, &distancia);
	char *comisaria = malloc(sizeof(resultado) + 1);
	strcpy(comisaria, resultado);
	return comisaria;
}
