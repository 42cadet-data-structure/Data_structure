#include <stdio.h>
#include <stdlib.h>
#include "arrayheap.h"


void printArray(int a[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", a[i]);
    };
    printf("\n");
}

void heapSort(int *values, int count)
{
	MinHeap *pHeap = NULL;
	HeapNode node;

	pHeap = createMinHeap(count);
	if (!pHeap)
		return ;
	for (int i = 0; i < count; i++)
	{
		node.key = values[i];
		insertMinHeap(pHeap, node);
	}

	for (int i = 0; i < count; i++)
	{
		HeapNode *pNode = deleteMinHeapAH(pHeap);
		if (pNode != NULL)
		{
			values[i] = pNode->key;
			free(pNode);
		}
	}
	deleteMinHeap(pHeap);
}

void	init_values(int *values, char **av, int num)
{
	int	i = -1;

	while (++i < num)
		values[i] = atoi(av[i + 1]);
}

int	main(int ac, char **av)
{
	int	*values;

	if (!(values = malloc(sizeof(int) * (ac - 1))))
		return (0);
	init_values(values, av, ac - 1);
	printf("Before sort\n");
	printArray(values, ac - 1);

	heapSort(values, ac - 1);

	printf("After sort\n");
	printArray(values, ac - 1);

	return (0);
}