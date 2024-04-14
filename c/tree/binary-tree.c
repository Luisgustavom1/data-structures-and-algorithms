#include <stdio.h>
#include <stdlib.h>
#include "binary-tree.h"

BinaryTree* createTree() {
  BinaryTree* root = (BinaryTree*)malloc(sizeof(BinaryTree));
  return root;
}

void freeTree(BinaryTree* root) {
  if (root == NULL) return;
  freeNode(*root);
  free(root);
  root = NULL;
}

void freeNode(Node* root) {
  if (root == NULL) return;
  freeNode(root->left);
  freeNode(root->right);
  free(root);
  root = NULL;
}

int search(BinaryTree* root, int v) {
  if (root == NULL) return 0;
  BinaryTree curr = *root;
  while (curr != NULL) {
    if (v == curr->value) return 1;
    if (v < curr->value) curr = curr->left;
    else curr = curr->right;
  }
  return 0;
}

int insert(BinaryTree* root, int v) {
  if (root == NULL) return 0;
  Node* new = (Node*)malloc(sizeof(Node));
  if (new == NULL) return 0;
  new->value = v;
  new->left = NULL;
  new->right = NULL;

  if (*root == NULL) {
    *root = new;
    return 1;
  }

  BinaryTree curr = *root;
  BinaryTree prev = NULL;

  while (curr != NULL) {
    prev = curr;
    if (v == curr->value) {
      freeNode(new);
      return 0;
    }
    if (v < curr->value) curr = curr->left;
    else curr = curr->right;
  }

  if (v < prev->value) prev->left = new;
  else prev->right = new;

  return 1;
}

Node* removeNode(Node* root) {
  Node *curr, *prev;
  if (root->left == NULL) {
    curr = root->right;
    free(root);
    return curr;
  }

  prev = root;
  curr = root->left;
  while(curr->right != NULL) {
    prev = curr;
    curr = curr->right;
  }

  if (prev != root) {
    prev->right = curr->left;
    curr->left = root->left;
  }
  curr->right = root->right;

  free(root);
  return curr;
}

int removeElement(BinaryTree* root, int v) {
  if (root == NULL) return 0;

  BinaryTree curr = *root;
  BinaryTree prev = NULL;

  while(curr != NULL) {
    if (curr->value == v) {
      if (*root == curr) *root = removeNode(curr);
      else if (prev->left == curr) prev->left = removeNode(curr);
      else prev->right = removeNode(curr);

      return 1;
    }

    prev = curr;
    if (v < curr->value) curr = curr->left;
    else curr = curr->right;
  }

  return 0;
}

int main() {
    BinaryTree* tree = createTree();
    if (tree == NULL) {
        printf("[ERROR] error on create tree\n");
        return 1;
    }

    insert(tree, 25);
    insert(tree, 71);
    insert(tree, 81);
    insert(tree, 12);
    insert(tree, 20);
    insert(tree, 17);
    insert(tree, 8);

    int removeValue = 25;
    if (removeElement(tree, removeValue)) {
        printf("%d removido da árvore.\n", removeValue);
    } 

    removeValue = 71;
    if (removeElement(tree, removeValue)) {
        printf("%d removido da árvore.\n", removeValue);
    }

    if ((*tree)->right == NULL) printf("subarvore direita vazia\n");
    if ((*tree)->left == NULL) printf("subarvore esquerda vazia\n");

    freeTree(tree);
    return 0;
}