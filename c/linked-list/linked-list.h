#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node Node;

struct node {
	int value;
	Node *next;
};

extern void print(Node *node);
extern void insert(Node *node, int n);
extern Node* init(int n);
extern Node* search(Node *node, int n);
extern void removeByValue(Node *node, int n);

#endif
