/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayheap_ours.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:14:25 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/04 21:17:48 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayheap.h"

ArrayMaxHeap *createArrayMaxHeap(int maxElementCount)
{
	ArrayMaxHeap	*heap;

	heap = (ArrayMaxHeap *)malloc(sizeof(ArrayMaxHeap));
	if (heap == NULL)
		return (NULL);

	heap->pElement = (HeapNode *)malloc(sizeof(HeapNode) * (maxElementCount + 1));
	if (heap->pElement == NULL)
	{
		free(heap);
		return (NULL);
	}
	heap->maxElementCount = maxElementCount;
	heap->currentElementCount = 0;
	return (heap);	
}

void deleteArrayMaxHeap(ArrayMaxHeap *pArrayHeap)
{
	if (pArrayHeap != NULL)
	{
		if (pArrayHeap->pElement != NULL)
		{
			free (pArrayHeap->pElement);
		}
		free(pArrayHeap);
	}
	return ;
}

void insertMaxHeapAH(ArrayMaxHeap *pArrayHeap, HeapNode element)
{
	int i = 0;
	if (pArrayHeap == NULL)
		return ;
	if (pArrayHeap->maxElementCount == pArrayHeap->currentElementCount)
		return ;
	i = ++pArrayHeap->currentElementCount;
	pArrayHeap->pElement[i] = element;
	while ((i != 1) && (element.key > pArrayHeap->pElement[i / 2].key))
	{
		pArrayHeap->pElement[i] = pArrayHeap->pElement[i / 2];
		i /= 2;
	}
	pArrayHeap->pElement[i] = element;
}

HeapNode *deleteMaxHeapAH(ArrayMaxHeap *pArrayHeap)
{
	HeapNode	*root_node = NULL;
	HeapNode	*last_node = NULL;
	int parent = 0, child = 0;

	if (pArrayHeap == NULL)
		return (NULL);
	if (pArrayHeap->currentElementCount == 0)
		return (NULL);
	root_node = (HeapNode *)malloc(sizeof(HeapNode));
	if (root_node == NULL)
		return (NULL);

	*root_node = pArrayHeap->pElement[1];
	last_node = &(pArrayHeap->pElement[pArrayHeap->currentElementCount]);
	pArrayHeap->currentElementCount--;
	parent = 1;
	child = 2;
	while (child <= pArrayHeap->currentElementCount)
	{
		if ((child <= pArrayHeap->currentElementCount) &&
			pArrayHeap->pElement[child].key < pArrayHeap->pElement[child + 1].key)
		{
			child++;
		}
		if (last_node->key >= pArrayHeap->pElement[child].key)
			break;
		pArrayHeap->pElement[parent] = pArrayHeap->pElement[child];
		parent = child;
		child *= 2;
	}
	pArrayHeap->pElement[parent] = *last_node;

	return (root_node);
}
