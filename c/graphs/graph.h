#ifndef GRAPH_H
#define GRAPH_H
#include "../linked-list/linked-list.h"

#define vertex int

typedef struct adj {
	int V;
	int A;
	Node** adj;	
} Graph;

extern Graph *GraphInit(int V);

#endif
