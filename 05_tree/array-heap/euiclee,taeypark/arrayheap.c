#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayheap.h"

ArrayMaxHeap *createArrayMaxHeap(int maxElementCount)
{
	ArrayMaxHeap	*heap;

	if(!(heap = (ArrayMaxHeap *)malloc(sizeof(ArrayMaxHeap))))
		return	(NULL);
	if (!(heap->pElement = (HeapNode *)malloc(sizeof(HeapNode) * (maxElementCount + 1))))
		return (free(heap), NULL);
	heap->maxElementCount = maxElementCount;
	heap->currentElementCount = 0;
	return (heap);
}

void deleteArrayMaxHeap(ArrayMaxHeap *pArrayHeap)
{
	free(pArrayHeap->pElement);
	pArrayHeap->pElement = NULL;
	free(pArrayHeap);
}

void insertMaxHeapAH(ArrayMaxHeap *pArrayHeap, HeapNode element)
{
	int	i;

	if (pArrayHeap->currentElementCount >= pArrayHeap->maxElementCount)
		return ;
	pArrayHeap->currentElementCount++;
	i = pArrayHeap->currentElementCount;
	while ((i != 1) && (element.key > pArrayHeap->pElement[i / 2].key)) 
	{
		pArrayHeap->pElement[i] = pArrayHeap->pElement[i / 2];
		i /= 2;
	}
	pArrayHeap->pElement[i] = element;
}

HeapNode *deleteMaxHeapAH(ArrayMaxHeap *pArrayHeap)
{
	HeapNode	*ret, *tmp;
	int			parent, child;

	if (pArrayHeap->currentElementCount <= 0 || !(ret = (HeapNode *)malloc(sizeof(HeapNode))))
		return (free(ret), NULL);
	*ret = pArrayHeap->pElement[1];
	tmp = &(pArrayHeap->pElement[pArrayHeap->currentElementCount]);
	pArrayHeap->currentElementCount--;
	parent = 1, child = 2;
	while (child <= pArrayHeap->currentElementCount)
	{
		//child가 범위에 있고, child의 형제가 child보다 우선순위가 크면 child의 형제와 비교
		if ((child <= pArrayHeap->currentElementCount)
			&& (pArrayHeap->pElement[child].key < pArrayHeap->pElement[child + 1].key))
			child++;
		if (tmp->key >= pArrayHeap->pElement[child].key)
			break ;
		pArrayHeap->pElement[parent] = pArrayHeap->pElement[child];
		parent = child;
		child *= 2;
	}
	pArrayHeap->pElement[parent] = *tmp;
	return (ret);
}
