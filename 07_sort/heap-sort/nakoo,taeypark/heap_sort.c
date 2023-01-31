#include <stdio.h>
#include <stdlib.h>
#include "arrayheap.h"

void	heap_sort(int *arr, int size, ArrayMaxHeap *heap)
{
	int			i;
	HeapNode	*node;

	for (i = 0; i < size; i++)
	{
		node = deleteMaxHeapAH(heap);
		arr[i] = -node->key;
		free(node);
	}
}

void	print_arr(char *msg, int *arr, int size)
{
	fprintf(stdout, "%s", msg);
	fprintf(stdout, "\n--------------\n");
	for (int i = 0; i < size; i++)
		fprintf(stdout, "%d ", arr[i]);
	fprintf(stdout, "\n--------------\n");
}

int	main(void)
{
	int				i;
	int				*arr, size;
	HeapNode		node;
	ArrayMaxHeap	*heap;

	fprintf(stdout, "size : ");
	fscanf(stdin, "%d", &size);
	heap = createArrayMaxHeap(size);
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL || heap == NULL)
		return (free(arr), deleteArrayMaxHeap(heap),
			fprintf(stderr, "Malloc Error\n"));
	fprintf(stdout, "arr : ");
	for (i = 0; i < size; i++)
	{
		fscanf(stdin, "%d", &node.key);
		node.key *= -1;
		insertMaxHeapAH(heap, node);
		arr[i] = -node.key;
	}
	print_arr("Before Heap sort", arr, size);
	heap_sort(arr, size, heap);
	print_arr("After Heap sort", arr, size);
	free(arr);
	deleteArrayMaxHeap(heap);
	return (0);
}
