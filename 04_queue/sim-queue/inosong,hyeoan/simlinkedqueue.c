
#include "simlinkedqueue.h"

LinkedQueue *createLinkedQueue()
{
	LinkedQueue	*	queue;

	queue  = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	memset(queue, 0, sizeof(LinkedQueue));
	if (queue == NULL)
		return (NULL);
	return (queue);	
}

int enqueueLQ(LinkedQueue *pQueue, QueueNode element)
{
	QueueNode	*queue_node;

	queue_node	= (QueueNode *)malloc(sizeof(QueueNode));
	if (queue_node == NULL)
		return (FALSE);
	*queue_node = element;
	if (pQueue->currentElementCount == 0)
	{
		pQueue->pFrontNode = queue_node;
		pQueue->pRearNode = queue_node;
		queue_node->pLink = NULL;
	}
	queue_node->pLink = pQueue->pRearNode->pLink;
	pQueue->pRearNode->pLink = queue_node;
	pQueue->pRearNode = queue_node;
	pQueue->currentElementCount++;
	return (TRUE);
}

QueueNode *dequeueLQ(LinkedQueue *pQueue)
{
	QueueNode *del_node;

	if (isLinkedQueueEmpty(pQueue) == FALSE)
	{
		del_node = pQueue->pFrontNode;
		pQueue->pFrontNode = pQueue->pFrontNode->pLink;
		del_node->pLink = NULL;
		pQueue->currentElementCount--;
		return (del_node);
	}
	return (NULL);
}

QueueNode *peekLQ(LinkedQueue *pQueue)
{
	if (isLinkedQueueEmpty(pQueue) == FALSE)
	{
		return(pQueue->pFrontNode);
	}
	return (NULL);
}

void deleteLinkedQueue(LinkedQueue *pQueue)
{
	QueueNode	*del_node;
	
	for(int i = 0; i < pQueue->currentElementCount; i++)
	{
		del_node = pQueue->pFrontNode;
		pQueue->pFrontNode = pQueue->pFrontNode->pLink;
		free (del_node);
	}
	free (pQueue);
}

int isLinkedQueueEmpty(LinkedQueue *pQueue)
{
	return (pQueue->currentElementCount == 0);
}
