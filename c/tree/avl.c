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
  freeNode(root->left);
  freeNode(root->right);
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
    // Insere no nó da ESQUERDA
    res = insert(&curr->left, v);
    if (res == 1) {
      int shouldRotate = balancingFactor(curr) >= 2;
      if (shouldRotate) {
        // analisar a subárvore em que foi inserido o valor
        Node* nodeToAnalyze = (*root)->left;
        // Se o valor entrou no nó da ESQUERDA, então a rotação é LL
        if (v < nodeToAnalyze->value) llRotation(root); // (Linked List)
        else lrRotation(root); // (zig zag)
      }
    }
  } else {
    // Insere no nó da direita
    res = insert(&curr->right, v);
    if (res == 1) {
      int shouldRotate = balancingFactor(curr) >= 2;
      if(shouldRotate) {
        // analisar a subárvore em que foi inserido o valor
        Node* nodeToAnalyze = (*root)->right;
        // Se o valor entrou no nó da DIREITA, então a rotação é LL
        if (v > nodeToAnalyze->value) rrRotation(root); // (Linked List)
        else rlRotation(root); // (zig zag)
      }
    }
  }

  curr->height = higher(nodeHeight(curr->left), nodeHeight(curr->right)) + 1;

  return res;
}

int removeElement(Avl* root, int v) {
  // Caso a arvores esteja vazia
  if (root == NULL) return 0;

  int res;
  // Se o valor é menor que o valor root então tenta remove o valor da ESQUERDA
  if (v < (*root)->value) {
    res = removeElement(&(*root)->left, v);
    if (res == 1) {
      int shouldRotate = balancingFactor(*root) >= 2;
      if (shouldRotate) {
        // Analisar a subárvore oposta a que foi inserido o valor
        Node* nodeToAnalyze = (*root)->right;
        // Analisa se depois de remover o nó da ESQUERDA é necessário rebalancear subárvore da DIREITA
        // Se a altura do nó da ESQUERDA for menor que a altura do nó da DIREITA, então a rotação é RR
        if (nodeHeight(nodeToAnalyze->left) <= nodeHeight(nodeToAnalyze->right)) rrRotation(root); // (linked list)
        else rlRotation(root); // (zig-zag)
      }
    }
  // Se o valor for maior que o valor root então tenta remover o valor da DIREITA
  } else if (v > (*root)->value) {
    res = removeElement(&(*root)->right, v);
    if (res == 1) {
      int shouldRotate = balancingFactor(*root) >= 2;
      // Analisar a subárvore oposta a que foi inserido o valor
      Node* nodeToAnalyze = (*root)->left;
      // Analisa se depois de remover o nó da DIREITA é necessário rebalancear subárvore da ESQUERDA
      // Se a altura do nó da DIREITA for menor que a altura do nó da ESQUERDA, então a rotação é LL
      if (nodeHeight(nodeToAnalyze->left) >= nodeHeight(nodeToAnalyze->right)) llRotation(root); // (linked list)
      else lrRotation(root); // (zig-zag)
    }
  } else {
    // Tem 1 ou nenhum filho
    if ((*root)->left == NULL || (*root)->right == NULL) {
      Node* aux = *root;
      if ((*root)->left != NULL) *root = (*root)->left;
      else *root = (*root)->right;
      freeNode(aux);
    // Tem 2 filhos
    } else {
      // procura o menor valor da subarvore da direita
      Node* temp = findSmaller((*root)->right);
      // copiar o valor pra cima
      (*root)->value = temp->value;
      // remover a sujeira do nó da direita que sobrou
      removeElement(&(*root)->right, (*root)->value);
      if (balancingFactor(*root) >= 2) {
        // Analise o oposto da subárvore que foi removido o valor
        Node* nodeToAnalyze = (*root)->left;
        // Se a altura do nó da DIREITA for menor que a altura do nó da ESQUERDA, então a rotação é LL
        if (nodeHeight(nodeToAnalyze->left) >= nodeHeight(nodeToAnalyze->right)) llRotation(root); // (linked list)
        else lrRotation(root); // (zig-zag)
      }
    }
  }

  return 0;
}

Node* findSmaller(Node* root) {
  Node* curr = root;
  while (curr->left != NULL) {
    curr = curr->left;
  }
  return curr;
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
  aux->height = higher(nodeHeight(aux->left), nodeHeight(aux->right)) + 1;

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
  aux->height = higher(nodeHeight(aux->right), nodeHeight(aux->left)) + 1;

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
  insert(tree, 8);
  insert(tree, 9);
  insert(tree, 7);

  printf("root %d\n", (*tree)->value);
  printf("root r %d\n", (*tree)->right->value);
  printf("root l %d\n", (*tree)->left->value);
  printf("root l l %d\n", (*tree)->left->left->value);

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