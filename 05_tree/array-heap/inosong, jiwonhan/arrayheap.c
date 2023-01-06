#include "arrayheap.h"

ArrayMaxHeap *createArrayMaxHeap(int maxElementCount)
{
	ArrayMaxHeap *heap;
	HeapNode	*node;

	heap = malloc(sizeof(ArrayMaxHeap));
	if (!heap)
		return (NULL);
	heap->maxElementCount = maxElementCount;
	heap->currentElementCount = 0;
	node = malloc(sizeof(HeapNode) * (maxElementCount+1));
	if (!node)
	{
		free(heap);
		return (NULL);
	}
	heap->pElement = node;
	return (heap);
}

void deleteArrayMaxHeap(ArrayMaxHeap *pArrayHeap)
{
	if (pArrayHeap != NULL)
	{
		if (pArrayHeap->pElement != NULL)
		{
			free (pArrayHeap->pElement);
			pArrayHeap->pElement = NULL; // taeyang
		}
		free (pArrayHeap);
	}
}

void insertMaxHeapAH(ArrayMaxHeap *pArrayHeap, HeapNode element)
{
	int	index;

	if (!pArrayHeap || pArrayHeap->maxElementCount == pArrayHeap->currentElementCount)
		return ;
	pArrayHeap->currentElementCount++;
	index = pArrayHeap->currentElementCount;
	while (index != 1 && element.key > pArrayHeap->pElement[index/2].key)
	{
		pArrayHeap->pElement[index] = pArrayHeap->pElement[index/2];
		index /= 2;
	}
	pArrayHeap->pElement[index] = element;
}

HeapNode *deleteMaxHeapAH(ArrayMaxHeap *pArrayHeap)
{
	int key = pArrayHeap->pElement->key;
	int parent = 1, child = 2;
	HeapNode	*tmp, *ret;

	if (!pArrayHeap || !pArrayHeap->currentElementCount)
		return (NULL);
	ret = malloc(sizeof(HeapNode));
	memcpy(ret, &(pArrayHeap->pElement[1]), sizeof(HeapNode));
	tmp = &(pArrayHeap->pElement[pArrayHeap->currentElementCount]);
	pArrayHeap->currentElementCount--;
	while (child <= pArrayHeap->currentElementCount)
	{
		if (pArrayHeap->pElement[child].key < pArrayHeap->pElement[child + 1].key)
			child++;
		if (tmp->key >= pArrayHeap->pElement[child].key)
			break ;
		pArrayHeap->pElement[parent] = pArrayHeap->pElement[child];
		parent = child;
		child *= 2;
	}
	pArrayHeap->pElement[parent] = *tmp;
	return (ret);



	// while (i < pArrayHeap->currentElementCount)
	// {
	// 	if (pArrayHeap->pElement[i * 2].key > pArrayHeap->pElement[(i * 2) + 1].key)
	// 	{
	// 		if(pArrayHeap->pElement[i * 2].key > pArrayHeap->pElement[i].key);
	// 		{
	// 			tmp = pArrayHeap->pElement[i];
	// 			pArrayHeap->pElement[i] = pArrayHeap->pElement[i * 2];
	// 			pArrayHeap->pElement[i * 2] = tmp;
	// 			i = i * 2;
	// 		}
	// 		else
	// 			break ;
	// 	}
	// 	else
	// 	{
	// 		if(pArrayHeap->pElement[(i * 2) + 1].key > pArrayHeap->pElement[i].key);
	// 		{
	// 			tmp = pArrayHeap->pElement[i];
	// 			pArrayHeap->pElement[i] = pArrayHeap->pElement[(i * 2) + 1];
	// 			pArrayHeap->pElement[(i * 2) + 1] = tmp;
	// 			i = (i * 2) + 1;
	// 		}
	// 		else
	// 			break;
	// 	}
	// }
}
