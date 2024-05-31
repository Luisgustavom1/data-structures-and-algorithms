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

	// Queue: head -> [value: 1, next: ->] -> [value: 2, next: NULL]
	// 	tail -> [value: 2, next: NULL]
	q->tail->next = new_node;
	q->tail = new_node;
	// Queue: head -> [value: 1, next: ->] -> [value: 2, next: ->] -> [value: 3, next: NULL]
	//        tail -> [value: 3, next: NULL]

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

// int main() {
// 	Queue *queue = InitQueue();
// 	enqueue(queue, 7); // head -> [7 | ] / tail -> [7| ]
// 	enqueue(queue, 3); // head -> [7| ] -> [8| ] / tail -> [8| ]
// 	enqueue(queue, 8); // head -> [7| ] -> [8| ] -> [9| ] / tail -> [9| ]
// 	enqueue(queue, 19); 
// 	enqueue(queue, 1);

// 	printf("====\n");
// 	printf("f %d\n", dequeue(queue));
// 	printf("f %d\n", dequeue(queue));
// 	printf("f %d\n", dequeue(queue));
// 	printf("f %d\n", dequeue(queue));
// 	printf("f %d\n", dequeue(queue));
// 	return 0;
// }
