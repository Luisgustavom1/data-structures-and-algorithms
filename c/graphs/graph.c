#include <stdlib.h>
#include "graph.h"

Graph *GraphInit(int V) {
	Graph* G = malloc(sizeof(Graph));
	G->V = V;
	G->A = 0;
	G->adj = malloc(sizeof (Node*) * V);
	for (vertex i = 0; i < V; i++) {
		G->adj[i] = NULL;
	}
	return G;
}