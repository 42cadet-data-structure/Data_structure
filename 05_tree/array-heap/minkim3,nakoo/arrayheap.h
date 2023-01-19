#ifndef ARRAY_HEAP_ARRAY_HEAP_H
#define ARRAY_HEAP_ARRAY_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct HeapElementType {
    int key;
    char data;
} HeapNode;

typedef struct ArrayHeapType {
    int maxElementCount;
    int currentElementCount;
    HeapNode *pElement;
} ArrayMaxHeap;

ArrayMaxHeap *createArrayMaxHeap(int maxElementCount);

void deleteArrayMaxHeap(ArrayMaxHeap *pArrayHeap);

void insertMaxHeapAH(ArrayMaxHeap *pArrayHeap, HeapNode element);

HeapNode *deleteMaxHeapAH(ArrayMaxHeap *pArrayHeap);

#endif