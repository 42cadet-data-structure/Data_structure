#include "priority_queue.h"

PriorityQueue *createQueuPriorityQueue()
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
	memset(newNode, 0, sizeof(QueueNode));
	newNode->cost = node.cost;
	newNode->toVertex = node.toVertex;
	if (pq->currentElementCount == 0)
	{
		pq->pFrontNode = newNode;
		pq->pRearNode = newNode;
	}
	else
	{
		search = pq->pFrontNode;
		while (search && ((search->cost < newNode->cost) || \
		(search->cost == newNode->cost && search->toVertex < newNode->toVertex)))
		{
			searchPrev = search;
			search = search->pNext;
		}
		if (searchPrev == NULL)
		{
			newNode->pNext = pq->pFrontNode;
			pq->pFrontNode = newNode;
		}
		else
		{
			newNode->pNext = search;
			searchPrev->pNext = newNode;
		}
		if (newNode->pNext == NULL)
			pq->pRearNode = newNode;
	}
	pq->currentElementCount++;
	return (TRUE);
}

QueueNode *dequeue(PriorityQueue *pq)
{
	QueueNode *retNode;

	if (!pq || isQueueEmpty(pq))
		return (NULL);
	retNode = pq->pFrontNode;
	pq->pFrontNode = pq->pFrontNode->pNext;
	retNode->pNext = NULL;
	pq->currentElementCount--;
	return (retNode);
}

QueueNode *peek(PriorityQueue *pq)
{
	if (!pq || isQueueEmpty(pq))
		return (NULL);
	return (pq->pFrontNode);
}

void deleteQueue(PriorityQueue *pq)
{
	if (!pq || isQueueEmpty(pq))
		return ;
	while (pq->pFrontNode)
		free(dequeue(pq));
	free(pq);
}


int isQueueEmpty(PriorityQueue *pq)
{
	return (!pq->currentElementCount);
}