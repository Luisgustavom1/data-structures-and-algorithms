#ifndef AVL_H
#define AVL_H

typedef struct _Node* Avl;
typedef struct _Node Node;

struct _Node {
	int value;
  int height;
	struct _Node* left;
	struct _Node* right;
};

Avl* createTree();

int search(Avl* root, int value);
int insert(Avl* root, int value);
int removeElement(Avl* root, int value);

void llRotation(Avl* root);
void rrRotation(Avl* root);
void lrRotation(Avl* root);
void rlRotation(Avl* root);

// utils
int balancingFactor(Node* root);
int nodeHeight(Node* root);
int higher(int a, int b);
void freeTree(Avl* root);
void freeNode(Node* node);
Node* findSmaller(Node* root);

#endif
