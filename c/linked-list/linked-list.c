#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void printQueue(Node *head) {
	Node *tmp = head->next;
	do {
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	} while (tmp != head->next);
}

void print(Node *head) {
	Node *tmp = head->next;
	while(tmp != NULL) {
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	};
}

Node* Queue(int n) {
	Node *head = malloc(sizeof(Node));
	head->value = n;
	head->next = head;
	return head;
}

Node* LinkedList() {
	Node *head = malloc(sizeof(Node));
	head->next = NULL;
	return head;
}

Node* search(Node *head, int n) {
	Node *temp = head->next;
	while(temp != NULL && temp->value != n) {
		temp = temp->next;	
	}
	return temp;
}

void removeByValue(Node *head, int n) {
	Node *prev = head->next;
	while(prev != NULL && prev->next->value != n) {
		prev = prev->next;
	}
	Node *tmp = prev->next;
	prev->next = tmp->next;
	free(tmp);
}

Node* append(Node *head, int n) {
	Node *new_node;
	new_node = malloc(sizeof(Node));
	new_node->value = n;
	Node *last = head;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return new_node;
}

Node* enqueue(Node *head, int n) {
	Node *new_node;
	new_node = malloc(sizeof(Node));	
	new_node->value = n;
	new_node->next = head->next;
	head->next = new_node;
	return new_node;
}

int dequeue(Node *head) {
	if (head == NULL) return -1;
	Node *tmp = head->next;
	int v = tmp->value;
	head->next = tmp->next;
	free(tmp);
	return v;
}

int main() {
	Node *linkedList = LinkedList(); // [7 | ] -> [7 | ]
	append(linkedList, 7);
	append(linkedList, 19);
	append(linkedList, 18);
	append(linkedList, 17);
	append(linkedList, 16);
	append(linkedList, 15);
	// queue = enqueue(queue, 3); // [3 | ] -> [7 | ] -> [3 | ]
	// queue = enqueue(queue, 8); // [8 | ] -> [7 | ] -> [3 | ] -> [8 | ]
	// queue =	enqueue(queue, 19); 
	// queue = enqueue(queue, 1);
	
	print(linkedList);
	removeByValue(linkedList, 17);
	Node *t = search(linkedList, 17);
	if (t == NULL) {
		printf("not found\n");
	} else {
		printf("found %d\n", t->value);
	}
	// printf("====\n");
	// printf("f %d\n", dequeue(queue));
	// printf("f %d\n", dequeue(queue));
	// printf("f %d\n", dequeue(queue));
	// printf("f %d\n", dequeue(queue));
	// printf("f %d\n", dequeue(queue));
	
	return 0;
}
