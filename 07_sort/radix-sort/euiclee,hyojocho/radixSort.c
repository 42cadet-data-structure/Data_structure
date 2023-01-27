#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

void	printArray(int *value, int num)
{
	for (int i = 0; i < num; i++)
		printf("%d ", value[i]);
	printf("\n");
}

void radixSort(int *values, int count, int radix, int digit)
{
    int i = 0, bucket = 0, d = 0, factor = 1;
    Queue **ppQueue = NULL;
    QueueNode node = {0,};

    ppQueue = (Queue **) malloc(sizeof(Queue *) * radix);
    if (!ppQueue)
        return;
    for (bucket = 0; bucket < radix; bucket++)
        ppQueue[bucket] = createQueue();
    for (d = 0; d < digit; d++)
    {
        for (i = 0; i < count; i++)
        {
            node.data = values[i];
            enqueue(ppQueue[(values[i] / factor) % radix], node);
        }
        i = 0;
        for (bucket = 0; bucket < radix; bucket++)
        {
            while(isQueueEmpty(ppQueue[bucket]) == FALSE)
            {
                QueueNode *pNode = dequeue(ppQueue[bucket]);
                if (pNode != NULL)
                {
                    values[i] = pNode->data;
                    i++;
                    free(pNode);
                }
            }
        }
        factor = factor * radix;
    }
    for (bucket = 0; bucket < radix; bucket++)
        deleteQueue(ppQueue[bucket]);
    free(ppQueue);
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

	radixSort(values, ac - 1, 10, 2);

	printf("After sort\n");
	printArray(values, ac - 1);

	return (0);
}