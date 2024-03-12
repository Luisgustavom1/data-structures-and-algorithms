#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node Node;

struct node {
	int value;
	Node *next;
};

extern Node* Queue(int n);
extern Node* enqueue(Node *head, int n);
extern int dequeue(Node *head);
extern void printQueue(Node *head);

#endif