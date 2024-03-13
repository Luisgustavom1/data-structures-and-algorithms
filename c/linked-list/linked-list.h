#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node Node;

struct node {
	int value;
	Node *next;
};

extern Node* LinkedList(int n);
extern Node* search(Node *head, int n);
extern Node* append(Node *head, int n);
extern void removeByValue(Node *head, int n);
extern void print(Node *head);

#endif
