#ifndef HEAP_C
#define HEAP_C

typedef struct heap {
  int *arr;
  int count;
  int capacity;
} Heap;

Heap *CreateHeap(int capacity);
void insert(Heap *h, int value);
int pop(Heap *h);
void print(Heap *h);

#endif
