#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

// Creates a new empty list and returns it as a result.
T_List create() {
	struct T_list *l = (struct T_list*) malloc(sizeof(T_List));
	l->length = 0;
	l->newest = NULL;
	l->maxLength = 10;
	return *l;
}

// Inserts a new sample (x,y,s) into the list. If the list had a length lower
// than the maximum length then a new node is inserted in the head (newest).
// Otherwise, the oldest node is reused and marked as the newest one.
void insert(T_List * pl, int x, int y, int s) {
	struct T_node n;
	n.data.posX = x;
	n.data.posY = y;
	n.data.speed = s;
	if (pl->newest == NULL) {
		pl->newest = &n;
		pl->length++;
	} else if (pl->length < pl->maxLength) {
		n.prev = pl->newest;
		n.next = pl->newest->next;
		pl->newest->next = &n;
		pl->newest = &n;
		pl->length++;
	} else {
		n.prev = pl->newest;
		n.next = pl->newest->next->next;
		pl->newest->next = &n;
		pl->newest = &n;
		pl->length++;
	}
}

// Returns the length of the list
int length(T_List l) {
	return l.length;
}

// Calculates the average value of the three components of a sample. 
// Returns the average of posX, the average of posY and the average of speed values.
struct info avg(T_List l) {
	struct info r;
	for (int i = 0; i < l.length; i++) {
		r.speed = r.speed + l.newest->data.speed;	
		r.posX = r.posX + l.newest->data.posX;	
		r.speed = r.posY + l.newest->data.posY;	
		l.newest = l.newest->next;
	}
	r.posY = r.posY / l.length;
	r.posX = r.posX / l.length;
	r.speed = r.speed / l.length;

	return r;
}

// Shows the content of the list, from the newest to the lowest
void show(T_List l) {
	for (int i = 0; i < l.length; i++) {
		printf("velocidad %i posx %i posy %i", l.newest->data.speed, l.newest->data.posX, l.newest->data.posY);	
		l.newest = l.newest->next;
	}
}

// Frees the memory used by the list and resets it (as if it were just created)
void destroy(T_List * pl) {
	struct T_node aux;
	for (int i = 0; i < pl->length; i++) {
		aux = *pl->newest->next;	
		free(pl->newest);
		pl->newest = &aux;
	}
	*pl = create();
}

// Loads a previously saved list. The resulting list must have the same content and order than the original one
T_List load(FILE * f) {

}

// Saves the list in a file: first the length and maximum length, then the 
// samples (three pieces of data per sample: posX, posY and speed)
void save(T_List l, FILE * f) {

}
