#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if (pq == NULL || pq->heapArray[0].data == NULL) return NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* heap = (Heap*) malloc(sizeof(Heap));
  if(heap == NULL) exit(EXIT_FAILURE);
  heap->capac = 3;
  heap->size = 0;
  heap->heapArray = malloc(heap->capac * sizeof(heapElem));
  if (heap->heapArray == NULL) exit(EXIT_FAILURE);
  heap->heapArray->data = NULL;
  heap->heapArray->priority = 0;
  return heap;
}
