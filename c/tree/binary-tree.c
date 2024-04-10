#include <stdio.h>
#include <stdlib.h>
#include "binary-tree.h"

BinaryTree* createTree() {
  BinaryTree* root = (BinaryTree*)malloc(sizeof(BinaryTree));
  if (root != NULL) {
    root = NULL;
  }  
  return root;
}

void freeTree(BinaryTree* root) {
  if (root == NULL) return;
  freeNode(*root);
  free(root);
}

void freeNode(BinaryTree root) {
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
  BinaryTree new = (BinaryTree)malloc(sizeof(BinaryTree));
  if (new == NULL) return 0;
  new->value = v;
  new->left = NULL;
  new->right = NULL;

  BinaryTree curr = *root;
  BinaryTree prev = NULL;
  return 1;
}

int main() {
  return 0;
}