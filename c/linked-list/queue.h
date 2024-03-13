#ifndef QUEUE_H
#define QUEUE_H
#include "linked-list.h"

typedef struct queue Queue;
struct queue {
	Node *head, *tail;
};

extern Queue* InitQueue();
extern int isEmpty(Queue *q);
extern void enqueue(Queue *q, int n);
extern int dequeue(Queue *q);

#endif
