#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int count = 0;
void inDepth(int n, int *visited, Node **adj) {
  count++;
  visited[n] = count;
  Node* tmp = adj[n];
  while (tmp != NULL) {
    int w = tmp->value;
    if (visited[w] == 0) {
      inDepth(w, visited, adj);
    }
    tmp = tmp->next;
  }
}

int *depthFirstSearch(Graph *g) {
  int init = 0;
  int *visited = malloc(sizeof(int) * g->V);
  for (int i = 0; i < g->V; i++) {
    visited[i] = 0;
  }

  inDepth(init, visited, g->adj);
  return visited;
}

int main() {
	Graph *graph = GraphInit(6);	
	
	graph->adj[0] = LinkedList(1);
  append(graph->adj[0], 4);	

	graph->adj[1] = LinkedList(0);
  append(graph->adj[1], 2);	

	graph->adj[2] = LinkedList(1);
  append(graph->adj[2], 3);		

	graph->adj[3] = LinkedList(2);
  append(graph->adj[3], 4);
	append(graph->adj[3], 5);	
	
	graph->adj[4] = LinkedList(0);
  append(graph->adj[4], 3);
	
	graph->adj[5] = LinkedList(3);

	int *visited = depthFirstSearch(graph);
	for (int i = 0; i < graph->V; i++) {
		printf("visited %d %d\n", i, visited[i]);
	}

	return 0;
}
