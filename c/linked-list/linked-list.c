#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

// TODO: head of linked list already with a value
Node* LinkedList(int v) {
	Node *head = malloc(sizeof(Node));
	head->value = v;
	head->next = NULL;
	return head;
}

void print(Node *head) {
	Node *tmp = head;
	while(tmp != NULL) {
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	};
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

// int main() {
// 	Node *linkedList = LinkedList(7);
// 	append(linkedList, 19);
// 	append(linkedList, 18);
// 	append(linkedList, 17);
// 	append(linkedList, 16);
// 	append(linkedList, 15);
	
// 	print(linkedList);
// 	removeByValue(linkedList, 17);
// 	Node *t = search(linkedList, 17);
// 	if (t == NULL) {
// 		printf("not found\n");
// 	} else {
// 		printf("found %d\n", t->value);
// 	}
	
// 	return 0;
// }
