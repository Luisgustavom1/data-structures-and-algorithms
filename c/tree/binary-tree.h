#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct _Node* BinaryTree;
typedef struct _Node Node;

struct _Node {
	int value;
	struct _Node* left;
	struct _Node* right;
};

BinaryTree* createTree();
void freeTree(BinaryTree* root);
void freeNode(BinaryTree node);
int search(BinaryTree* root, int value);
int insert(BinaryTree* root, int value);
int removeElement(BinaryTree* root, int value);

#endif
