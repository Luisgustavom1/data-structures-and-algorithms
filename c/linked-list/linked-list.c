#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void print(Node *head) {
	if (head != NULL) {
		printf("%d\n", head->value);
		print(head->next);
	}
}

void insert(Node *head, int n) {
	Node *new_node;
	new_node = malloc(sizeof(Node));	
	new_node->value = n;
	new_node->next = head->next;
	head->next = new_node;
}

Node* init(int n) {
	Node *head = malloc(sizeof(Node));
	head->value = n;
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

// int main() {
//	Node *linked_list = init(7);
//	insert(linked_list, 3);
//	insert(linked_list, 8);
//	insert(linked_list, 19);
//	insert(linked_list, 1);
//	print(linked_list);
//	printf("removing...\n");
//	removeByValue(linked_list, 8);
//	print(linked_list);

//	return 0;
//}
