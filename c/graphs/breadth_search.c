#include <stdio.h>
#include <stdlib.h>
#include "../linked-list/linked-list.h"

#define vertex int

typedef struct graph {
	int V;
	int A;
	Node** adj;	
} Graph;

Graph *GraphInit(int V) {
	Graph* G = malloc(sizeof(Graph));
	G->V = V;
	G->A = 0;
	G->adj = malloc(sizeof (vertex) * V);
	for (vertex i = 0; i < V; i++) {
		G->adj[i] = NULL;
	}
	return G;
}

int main() {
	Node *graph = LinkedList(0);
	append(graph, 1);
	append(graph, 2);
	append(graph, 3);
	print(graph);
	return 0;
}
