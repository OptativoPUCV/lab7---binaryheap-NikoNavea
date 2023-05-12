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
  if (pq == NULL || pq->size == 0) return NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if( pq->size+1 == pq->capac){
    pq->capac = 2 * pq->capac + 1;
    pq->heapArray = (heapElem*) realloc(pq->heapArray, sizeof(heapElem) * pq->capac);
  }
  
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  
  int indice = pq->size;
  int indiceParent = (indice -1)/2;
  
  while( indice > 0 && pq->heapArray[indice].priority > pq->heapArray[indiceParent].priority){
    heapElem temp = pq->heapArray[indice];
    pq->heapArray[indice] = pq->heapArray[indiceParent];
    pq->heapArray[indiceParent] = temp;

    indice = indiceParent;
    indiceParent = (indice-1)/2;
  }
  pq->size++;
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
