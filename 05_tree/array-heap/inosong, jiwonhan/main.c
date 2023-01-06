#include <stdio.h>
#include <stdlib.h>
#include "arrayheap.h"

void displayArrayHeap(ArrayMaxHeap *pHeap) {
    if (pHeap != NULL) {
        for (int i = 1; i <= pHeap->currentElementCount; i++) {
            printf("[%d],%d\n", i, pHeap->pElement[i].key);
        }
    }
}

int main() {
    int maxHeapSize = 20;

    ArrayMaxHeap *pHeap1 = NULL;

    HeapNode *pNode = NULL;
    HeapNode e1 = {10};
    HeapNode e2 = {20};
    HeapNode e3 = {30};
    HeapNode e4 = {40};
    HeapNode e5 = {50};
    HeapNode e6 = {60};
    HeapNode e7 = {70};
    HeapNode e8 = {80};
    HeapNode e9 = {90};

    pHeap1 = createArrayMaxHeap(maxHeapSize);
    if (pHeap1 != NULL) {
        insertMaxHeapAH(pHeap1, e1);
        insertMaxHeapAH(pHeap1, e4);
        insertMaxHeapAH(pHeap1, e3);
        insertMaxHeapAH(pHeap1, e2);
        insertMaxHeapAH(pHeap1, e5);
        insertMaxHeapAH(pHeap1, e8);
        insertMaxHeapAH(pHeap1, e6);
        insertMaxHeapAH(pHeap1, e9);
        insertMaxHeapAH(pHeap1, e7);

        printf("Max Heap:\n");
        displayArrayHeap(pHeap1);

        pNode = deleteMaxHeapAH(pHeap1);
        if (pNode != NULL) {
            printf("deleteMaxHeapAH()-[%d]\n", pNode->key);
            free(pNode);
        }

        printf("Max Heap:\n");
        displayArrayHeap(pHeap1);

        deleteArrayMaxHeap(pHeap1);
    }

    return 0;
}
