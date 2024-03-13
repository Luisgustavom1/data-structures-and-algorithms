#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* InitQueue() {
	Queue *q = malloc(sizeof(Queue));
	q->head = q->tail = NULL;
	return q;
}

int isEmpty(Queue *q) {
	return q->head == NULL && q->tail == NULL;
}

void enqueue(Queue *q, int n) {
	Node *new_node;
	new_node = malloc(sizeof(Node));	
	new_node->value = n;
	new_node->next = NULL;

	if (q->head == NULL) {
		q->head = q->tail = new_node;
		return;
	} 
	q->tail->next = new_node;
	q->tail = new_node;
	return;	
}

int dequeue(Queue *q) {
	if (q->head == NULL) return -1;
	Node *tmp = q->head;
	int v = tmp->value;
	
	q->head = q->head->next;

	if (q->head == NULL) {
		q->tail = NULL;
	}

	free(tmp);
	return v;
}

int main() {
	Queue *queue = InitQueue();
	enqueue(queue, 7); // [| ] -> [7 | ]
	enqueue(queue, 3); // [3 | ] -> [7 | ] -> [3 | ]
	enqueue(queue, 8); // [8 | ] -> [7 | ] -> [3 | ] -> [8 | ]
	enqueue(queue, 19); 
	enqueue(queue, 1);

	printf("====\n");
	printf("f %d\n", dequeue(queue));
	printf("f %d\n", dequeue(queue));
	printf("f %d\n", dequeue(queue));
	printf("f %d\n", dequeue(queue));
	printf("f %d\n", dequeue(queue));
	return 0;
}
