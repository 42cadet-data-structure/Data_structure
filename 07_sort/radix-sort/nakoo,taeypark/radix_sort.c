#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

int	get_max_digit(int *array, int size)
{
	int max_val = 0;
	for(int i = 0 ; i < size ; i++)
	{
		if(max_val < array[i])
			max_val = array[i];
	}
	
	int max_radix = 1;
	while(max_val / 10 > 0)
	{
		max_val /= 10;
		max_radix++;
	}
	return (max_radix);
}

void	radix_sort(int *arr, int size, int radix)
{
	int			digit, i, j, k, factor = 1;
	QueueNode	node, *del_node;
	Queue		**queue;

	queue = (Queue **)malloc(sizeof(Queue *) * radix);
	if (queue == NULL)
		return (perror("malloc error "));
	digit = get_max_digit(arr, size);
	for (i = 0; i < radix; i++)
	{
		queue[i] = createQueue();
		if (queue[i] == NULL)
		{
			for (j = 0; j < i; j++)
				deleteQueue(queue[j]);
			return (perror("malloc error "),free(queue));
		}
	}
	for (i = 0; i < digit; i++)
	{
		for (j = 0; j < size; j++)
		{
			node.data = arr[j];
			enqueue(queue[(arr[j] / factor) % radix], node);
		}
		k = 0;
		for (j = 0; j < radix; j++)
		{
			while (isQueueEmpty(queue[j]) == FALSE)
			{
				del_node = dequeue(queue[j]);
				arr[k++] = del_node->data;
				free(del_node);
			}
		}
		factor *= radix;
	}
	for (i = 0; i < size; i++)
		deleteQueue(queue[i]);
	free(queue);
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
	int	i;
	int	*arr, size;

	fprintf(stdout, "size : ");
	fscanf(stdin, "%d", &size);
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (fprintf(stderr, "Malloc Error\n"));
	fprintf(stdout, "arr : ");
	for (i = 0; i < size; i++)
		fscanf(stdin, "%d", &arr[i]);
	print_arr("Before Radix sort", arr, size);
	radix_sort(arr, size, 10);
	print_arr("After Radix sort", arr, size);
	free(arr);
	return (0);
}
