#include "priority_queue.h"

PriorityQueue *createQueuPriorityQueue(int maxElementCount)
{
	PriorityQueue *pq;
	pq = malloc(sizeof(PriorityQueue));
	if (!pq)
		return (NULL);
	memset(pq, 0, sizeof(PriorityQueue));
	return (pq);
}

int enqueue(PriorityQueue *pq, QueueNode node)
{
	QueueNode *newNode;
	QueueNode *search;
	QueueNode *searchPrev = NULL;

	if (!pq)
		return (FALSE);
	newNode = malloc(sizeof(QueueNode));
	*newNode = node;
	if (pq->currentElementCount == 0)
	{
		pq->pFrontNode = newNode;
		pq->pRearNode = newNode;
	}
	else
	{
		search = pq->pFrontNode;
		while (search && (search->cost < newNode->cost || \
		(search->cost == newNode->cost && search->toVertex < newNode->toVertex)))
		{
			searchPrev = search;
			search = search->pNext;
		}
		newNode->pNext = search;
		if (searchPrev)
			searchPrev->pNext = newNode;
		else
			pq->pFrontNode = newNode;
		if (newNode->pNext == NULL)
			pq->pRearNode = newNode;
	}
	pq->currentElementCount++;
	return (TRUE);
}

/*QueueNode *dequeue(PriorityQueue *pq);

QueueNode *peek(PriorityQueue *pq);

void deleteQueue(PriorityQueue *pq);

int isQueueFull(PriorityQueue *pq);

int isQueueEmpty(PriorityQueue *pq);
{
	return (!size);
}*/