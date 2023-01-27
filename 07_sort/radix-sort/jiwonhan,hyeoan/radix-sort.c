#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

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

void radix_sort(int *array, int n, int radix)
{
	int i = 0, num = 0, d = 0, factor = 1, digit = 0;
	Queue **queue = NULL;
	QueueNode node = {0, };
	queue = (Queue **)malloc(sizeof(Queue *) * radix);

	if (queue == NULL)
		return ;
	for (num = 0; num < radix; num++)
		queue[num] = createQueue();
	digit = get_max_digit(array, n);
	for (d = 0; d < digit; d++)
	{
		for (i = 0; i < n; i++)
		{
			node.data = array[i];
			if (array[i] >= factor)
				enqueue(queue[(array[i] / factor) % radix], node);
			else
				enqueue(queue[0], node);

		}
		i = 0;
		for(num = 0; num < radix; num++)
		{
			while (isQueueEmpty(queue[num]) == FALSE)
			{
				QueueNode *pnode = dequeue(queue[num]);
				if (pnode == NULL)
					return ;
				array[i++] = pnode->data;
				free(pnode);
			}
		}
		factor = factor * radix;
	}
	for (num = 0; num < radix; num++)
		deleteQueue(queue[num]);
	free(queue);
}

int main()
{
    int n;
	int radix = 10;
    int array[50];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
	radix_sort(array, n, radix);
	print_array(array, n);
    return (0);
}