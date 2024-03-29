#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../linked-list/queue.h"

int *breadthSearch(Graph *g) {
	int *visited = malloc(sizeof(int) * g->V);
	int w;
	int v = 0;
	int count = 1;
	Queue *q = InitQueue(); 
	enqueue(q, v);

	for (int i = 0; i < g->V; i++) {
		visited[i] = 0;
	}
	visited[v] = count;

	while (isEmpty(q) == 0){
		v = dequeue(q);
		Node *aux = g->adj[v];

		while (aux != NULL) {
			w = aux->value;
			if (visited[w] == 0) {
				count++;
				visited[w] = count;
				enqueue(q, w);
			}	
			aux = aux->next;
		}
	}	

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

	int *visited = breadthSearch(graph);
	for (int i = 0; i < graph->V; i++) {
		printf("visited %d %d\n", i, visited[i]);
	}

	return 0;
}
