#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void print(Node *head) {
	Node *tmp = head->next;
	do {
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	} while (tmp != head->next);
}

Node* init(int n) {
	Node *head = malloc(sizeof(Node));
	head->value = n;
	head->next = head;
	return head;
}

Node* search(Node *head, int n) {
	Node *temp = head;
	while(temp != NULL && temp->value != n) {
		temp = temp->next;	
	}
	return temp;
}

void removeByValue(Node *head, int n) {
	Node *prev = head;
	while(prev->next != NULL && prev->next->value != n) {
		prev = prev->next;
	}
	Node *tmp = prev->next;
	prev->next = tmp->next;
	free(tmp);
}

Node *enqueue(Node *head, int n) {
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

// int main() {
// 	Node *queue = init(7); // [7 | ] -> [7 | ]
// 	queue = enqueue(queue, 3); // [3 | ] -> [7 | ] -> [3 | ]
// 	queue = enqueue(queue, 8); // [8 | ] -> [7 | ] -> [3 | ] -> [8 | ]
// 	queue =	enqueue(queue, 19); 
// 	queue = enqueue(queue, 1);
	
// 	print(queue);
// 	printf("====\n");
// 	printf("f %d\n", dequeue(queue));
// 	printf("f %d\n", dequeue(queue));
// 	printf("f %d\n", dequeue(queue));
// 	printf("f %d\n", dequeue(queue));
// 	printf("f %d\n", dequeue(queue));
	
// 	return 0;
// }
