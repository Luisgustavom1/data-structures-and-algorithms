#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

Avl* createTree() {
  Avl* root = (Avl*)malloc(sizeof(Avl));
  return root;
}

void freeTree(Avl* root) {
  if (root == NULL) return;
  freeNode(*root);
  free(root);
  root = NULL;
}

void freeNode(Avl root) {
  if (root == NULL) return;
  //FIXME: freeNode(root->left);
  // freeNode(root->left);
  //FIXME: freeNode(root->left);
  // freeNode(root->right);
  free(root);
  root = NULL;
}

int search(Avl* root, int v) {
  if (root == NULL) return 0;
  Avl curr = *root;
  while (curr != NULL) {
    if (v == curr->value) return 1;
    if (v < curr->value) curr = curr->left;
    else curr = curr->right;
  }
  return 0;
}

int insert(Avl* root, int v) {
  int res;
  // Caso o nó root seja vazio, só cria um novo nó
  // Inicializa os valores desse novo nó e o root aponta para ele
  if (*root == NULL) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) return 0;
    node->value = v;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    *root = node;
    return 1;
  }

  Node* curr = *root;

  if (v == curr->value) {
    printf("valor duplicado");
    return 0;
  }

  // Para respeitar a regra da árvore binária
  if (v < curr->value) {
    // Insere no nó da esquerda
    res = insert(&curr->left, v);
    if (res == 1) {
      int shouldRotate = balancingFactor(curr) >= 2;
      if (shouldRotate) {
        // Se o valor entrou no nó (esquerda do root) da esquerda, então a rotação é LL (Linked List)
        if (v < (*root)->left->value) llRotation(root);
        // Se o valor entrou no nó (esquerda do root) da direita, então a rotação é LR (zig zag)
        else lrRotation(root);
      }
    }
  } else {
    // Insere no nó da direita
    res = insert(&curr->right, v);
    if (res == 1) {
      int shouldRotate = balancingFactor(curr) >= 2;
      if(shouldRotate) {
        // Se o valor entrou no nó (direita do root) da direita, então a rotação é LL (Linked List)
        if (v > (*root)->right->value) rrRotation(root);
        // Se o valor entrou no nó (direita do root) da esquerda, então a rotação é LR (zig zag)
        else rlRotation(root);
      }
    }
  }

  curr->height = higher(nodeHeight(curr->left), nodeHeight(curr->right)) + 1;

  return res;
}

Node* removeNode(Node* root) {
  Node* curr, *prev;
  if (root->left == NULL) {
    curr = root->right;
    freeNode(root);
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
  freeNode(root);

  return curr;
}

int removeElement(Avl* root, int v) {
  if (root == NULL) return 0;

  Avl curr = *root;
  Avl prev = NULL;

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

int nodeHeight(Node* node) {
  if (node == NULL) return -1;
  return node->height;
}

int balancingFactor(Node* node) {
  int diff = nodeHeight(node->left) - nodeHeight(node->right);
  if (diff < 0) return diff * -1;
  return diff;
}
 
int higher(int a, int b) {
  if (a > b) return a;
  return b;
}
 
void llRotation(Avl* root) {
  Node* aux = (*root)->left;
  // A esquerda do root recebe o nó da direita do aux
  (*root)->left = aux->right;
  // O nó da esquerda do root recebe o root em seu nó direito
  aux->right = *root;

  // Como mudou os filhos do root a gente atualiza a altura do nó root
  (*root)->height = higher(nodeHeight((*root)->left), nodeHeight((*root)->right)) + 1;
  // Como mudou os filhos do nó esquerdo do root a gente atualiza a altura desse nó
  // TODO: verify if root->height can be aux->right
  aux->height = higher(nodeHeight(aux->left), (*root)->height) + 1;

  // O root passa a ser o nó da esquerda
  (*root) = aux;
}

void rrRotation(Avl* root) {
  Node* aux = (*root)->right;
  // A direita do root recebe o nó da esquerda do aux
  (*root)->right = aux->left;
  // O nó da direita do root recebe o root em seu nó esquerdo
  aux->left = *root;

  // Como mudou os filhos do root a gente atualiza a altura do nó root
  (*root)->height = higher(nodeHeight((*root)->left), nodeHeight((*root)->right)) + 1;
  // Como mudou os filhos do nó direito do root a gente atualiza a altura desse nó
  // TODO: verify if root->height can be aux->left
  aux->height = higher(nodeHeight(aux->right), (*root)->height) + 1;

  // O root passa a ser o nó da direita
  (*root) = aux;
}

void lrRotation(Avl* root) {
  // Rotação RR no nó da esquerda
  rrRotation(&(*root)->left);
  // Rotação LL no nó root
  llRotation(root);
}

void rlRotation(Avl* root) {
  // Rotação LL no nó da direita
  llRotation(&(*root)->right);
  // Rotação RR no nó root
  rrRotation(root);
}

int main() {
  Avl* tree = createTree();
  insert(tree, 10);
  insert(tree, 9);
  insert(tree, 8);

  printf("root %d\n", (*tree)->value);
  printf("root l %d\n", (*tree)->left->value);
  printf("root r %d\n", (*tree)->right->value);

  int searchValue = 8;
  if (search(tree, searchValue)) {
    printf("%d encontrado na árvore.\n", searchValue);
  }

  int removeValue = 9;
  if (removeElement(tree, removeValue)) {
    printf("%d removido da árvore.\n", removeValue);
  }

  if (!search(tree, removeValue)) {
    printf("%d não existe na árvore após remoção.\n", removeValue);
  }

  freeTree(tree);
  return 1;
}