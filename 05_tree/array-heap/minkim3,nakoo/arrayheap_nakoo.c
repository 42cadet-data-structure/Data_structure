#include "arrayheap.h"

ArrayMaxHeap *createArrayMaxHeap(int maxElementCount)
{
	ArrayMaxHeap	*maxHeap;

	maxHeap = (ArrayMaxHeap *)malloc(sizeof(ArrayMaxHeap));
	if (!maxHeap)
		return (NULL);
	maxHeap->pElement = (HeapNode *)malloc(sizeof(HeapNode) * maxElementCount);
	if (!maxHeap->pElement)
		return (free(maxHeap), NULL);
	maxHeap->maxElementCount = maxElementCount;
	maxHeap->currentElementCount = 0;
	return (maxHeap);
}

void deleteArrayMaxHeap(ArrayMaxHeap *pArrayHeap)
{
	free(pArrayHeap->pElement);
	pArrayHeap->pElement = NULL;
	free(pArrayHeap);
}

void insertMaxHeapAH(ArrayMaxHeap *pArrayHeap, HeapNode element)
{
	int	tmp;
	int	i;

	if (pArrayHeap->currentElementCount >= pArrayHeap->maxElementCount)
		return ;
	pArrayHeap->currentElementCount++;
	i = pArrayHeap->currentElementCount;
	pArrayHeap->pElement[i] = element;
	while (i != 1 && pArrayHeap->pElement[i / 2].key < pArrayHeap->pElement[i].key)
	{
		tmp = pArrayHeap->pElement[i / 2].key;
		pArrayHeap->pElement[i / 2].key = pArrayHeap->pElement[i].key;
		pArrayHeap->pElement[i].key = tmp;
		i /= 2;
	}
}

HeapNode *deleteMaxHeapAH(ArrayMaxHeap *pArrayHeap)
{
	HeapNode	*delNode;
	HeapNode	minNode;
	int			comp;
	int			i;

	if (pArrayHeap->currentElementCount == 0 && pArrayHeap->pElement == NULL)
		return (NULL);
	delNode = (HeapNode *)malloc(sizeof(HeapNode));
	if (!delNode)
		return (NULL);
	/* 반환할 루트 노드를 저장한다. */
	*delNode = pArrayHeap->pElement[1];
	/* 단말 노드를 저장한다. */
	minNode = pArrayHeap->pElement[pArrayHeap->currentElementCount];
	pArrayHeap->currentElementCount--;
	i = 1;
	comp = 2;
	while (i <= pArrayHeap->currentElementCount)
	{
		if (minNode.key > pArrayHeap->pElement[i].key)
			break ;
		if (pArrayHeap->pElement[comp].key < pArrayHeap->pElement[comp + 1].key)
			comp++;
		pArrayHeap->pElement[i].key = pArrayHeap->pElement[comp].key;
		i = comp;
		comp *= 2;
	}
	pArrayHeap->pElement[i].key = minNode.key;
	return (delNode);
}