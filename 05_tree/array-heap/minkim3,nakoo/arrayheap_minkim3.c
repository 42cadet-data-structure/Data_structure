#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayheap.h"

// max heap이란? 가장 큰 값이 위에 위치하고, 작은 값들이 아래에 놓이는 이진 트리
// 여기서는 편의상 array로 구현

// typedef struct HeaelementType {
//     int key;  // 정렬의 기준
//     char data;
// } HeapNode;

// typedef struct ArrayHeapType {
//     int maxElementCount;
//     int currentElementCount;
//     HeapNode *element;
// } ArrayMaxHeap;

ArrayMaxHeap *createArrayMaxHeap(int maxElementCount)
{
	// header를 보면서 하나하나 생성, 초기화
	ArrayMaxHeap *maxheap;
	if (maxElementCount < 1)
		return (NULL);
	maxheap = (ArrayMaxHeap *) malloc(sizeof(ArrayMaxHeap));
	if (!maxheap)
		return (NULL);
    memset(maxheap, 0, sizeof(ArrayMaxHeap));
	maxheap->maxElementCount = maxElementCount;
	maxheap->element = (HeapNode *) malloc(sizeof(HeapNode) * (maxElementCount + 1));
    if (maxheap->element == NULL) {
        free(maxheap);
        return NULL;
    }
    memset(maxnode->element, 0, sizeof(HeapNode) * (maxElementCount + 1));
    return maxnode;
}

void deleteArrayMaxHeap(ArrayMaxHeap *maxheap)
{
	// element와 maxheap을 free
    if (maxheap == NULL)
		return;
    if (maxheap->element != NULL)
        free(maxheap->element);
    free(maxheap);
}

void insertMaxHeapAH(ArrayMaxHeap *maxheap, HeapNode element)
{
	// element를 우선 집어넣었다고 가정한 후 정렬
    int i = 0;
    if (maxheap == NULL || maxheap->maxElementCount == maxheap->currentElementCount)
		return;
	maxheap->currentElementCount++;
    i = maxheap->currentElementCount;
    while ((i != 1) && (element.key > maxheap->element[i / 2].key))
	{
        maxheap->element[i] = maxheap->element[i / 2];
        i /= 2;
    }
    maxheap->element[i] = element;
}

HeapNode *deleteMaxHeapAH(ArrayMaxHeap *maxheap)
{
	// maxheap의 가장 큰 값을 제거하고
	// 나머지 값 정렬
    HeapNode *maxnode = NULL;
    HeapNode *tmp = NULL;
    int i = 0, parent = 0, child = 0;
    if ((maxheap == NULL) || (maxheap->currentElementCount == 0))
		return NULL;
    maxnode = (HeapNode *) malloc(sizeof(HeapNode));
    if (maxnode == NULL)
		return NULL;
    *maxnode = maxheap->pElement[1];
    i = maxheap->currentElementCount;
    tmp = &(maxheap->pElement[i]);
    maxheap->currentElementCount--;
    parent = 1;
    child = 2;
    while (child <= maxheap->currentElementCount)
	{
        if ((child <= maxheap->currentElementCount)\
		 && maxheap->pElement[child].key < maxheap->pElement[child + 1].key) {
            child++;
        }
        if (tmp->key >= maxheap->pElement[child].key) {
            break;
        }
        maxheap->pElement[parent] = maxheap->pElement[child];
        parent = child;
        child *= 2;
    }
    maxheap->pElement[parent] = *tmp;

    return maxnode;
}
