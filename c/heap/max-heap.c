#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int HEAP_SIZE = 20;

Heap *CreateHeap(int capacity) {
  Heap* heap = malloc(sizeof(Heap));
  if (heap == NULL){
    printf("error on create heap\n");
    return NULL;
  }

  heap->arr = malloc(sizeof(int) * capacity + 1);
  heap->count = 0;
  heap->capacity = capacity + 1;
  return heap;
}

void max_heapify(Heap* heap, int v) {
  int k = heap->count;

  while ((k / 2) > 0 && v > heap->arr[k/2]) {
    heap->arr[k] = heap->arr[k/2];
    k = k/2;
  }

  heap->arr[k] = v;
}

int pop(Heap *heap) {
  if (heap->count == 0) {
    return -1;
  }

  int v = heap->arr[1];
  int last = heap->arr[heap->count];
  heap->count--;
  int k = 1;

  while(2*k <= heap->count && (last < heap->arr[2*k] && last < heap->arr[2*k + 1])) {
    if (heap->arr[2*k] > heap->arr[2*k + 1]) {
      heap->arr[k] = heap->arr[2*k];
      k = 2*k;        
    } else {
      heap->arr[k] = heap->arr[2*k + 1];
      k = 2*k + 1;
    }
  }
  heap->arr[k] = last;

  return v;
}

void insert(Heap *heap, int value) {
  heap->count++;
  max_heapify(heap, value);
}

void print(Heap *h){
  int i;
  for(i = 1; i <= h->count; i++){
    printf("%d ", h->arr[i]);
  }
  printf("\n");
}

// TODO: FIX THIS IS WRONGGG
int main(){
  int i;
  Heap *heap = CreateHeap(HEAP_SIZE);

  for (i = 1; i <= HEAP_SIZE; i++){
    insert(heap, i);
  }

  print(heap);
  printf("pop: %d\n", pop(heap));
  print(heap);
  printf("pop: %d\n", pop(heap));
  print(heap);
  printf("pop: %d\n", pop(heap));
  print(heap);
  printf("pop: %d\n", pop(heap));
  print(heap);
  printf("pop: %d\n", pop(heap));
  print(heap);

  return 0;
}
