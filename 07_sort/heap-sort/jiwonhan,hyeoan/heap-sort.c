#include "arrayheap.h"

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
void heap_sort(int *array, int n)
{
	MinHeap *min_heap = NULL;
	HeapNode node;
	min_heap = createMinHeap(n);
	if (min_heap == NULL)
		return ;
	for (int i = 0; i < n; i++)
	{
		node.key = array[i];
		insertMinHeap(min_heap, node);
	}
	for (int i = 0; i < n; i++)
	{
		HeapNode *pnode = deleteMinHeapAH(min_heap);
		if (pnode == NULL)
			return ;
		array[i] = pnode->key;
		free(pnode);
	}
	deleteMinHeap(min_heap);
	//displayHeap(pHeap);
}

int main()
{
    int n;
    int array[50];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
	heap_sort(array, n);
	print_array(array, n);
    return (0);
} 