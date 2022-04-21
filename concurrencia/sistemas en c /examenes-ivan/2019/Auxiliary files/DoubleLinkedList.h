#ifndef _DoubleLL_
#define _DoubleLL_

#include <stdio.h>
#include <stdlib.h>

struct info {
	int posX;
	int posY;
	int speed;
};
typedef struct T_node {
	struct info data;
	struct T_node * prev, * next;
} T_Node;
typedef struct T_list {
	struct T_node * newest;
	int length;
	int maxLength;
} T_List;

T_List create();
void insert(T_List * pl, int x, int y, int s);
int length(T_List l);
void show(T_List l);
struct info avg(T_List l);
void destroy(T_List * pl);
T_List load(FILE * f);
void save(T_List l, FILE * f);

#endif