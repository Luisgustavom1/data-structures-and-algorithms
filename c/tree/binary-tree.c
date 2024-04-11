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
  if (root == NULL) return 0;
  BinaryTree new = (BinaryTree)malloc(sizeof(BinaryTree));
  if (new == NULL) return 0;
  new->value = v;
  new->left = NULL;
  new->right = NULL;

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


Node* removeNode(BinaryTree root) {
  Node* curr, *prev;
  if (root->left == NULL) {
    curr = root->right;
    freeNode(root);
    return curr;
  }

  prev = curr;
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
  freeNode(root);

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
  return 0;
}