#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct Node* BinaryTree;

struct Node {
	int value;
	struct Node* left;
	struct Node* right;
};

BinaryTree* createTree();
void freeTree(BinaryTree* root);
void freeNode(BinaryTree node);
int search(BinaryTree* root, int value);
int insert(BinaryTree* root, int value);

#endif
