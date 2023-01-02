#include "simlinkedqueue.h"

LinkedQueue *createLinkedQueue()
{
	LinkedQueue	*queue;
	queue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (!queue)
		return (NULL);
	memset(queue, 0, sizeof(LinkedQueue));
	return (queue);
}

int enqueueLQ(LinkedQueue *pQueue, QueueNode element)
{
	QueueNode	*new;

	if (!pQueue)
		return (FALSE);
	new = (QueueNode *)malloc(sizeof(QueueNode));
	if (!new)
		return (FALSE);
	new->data = element.data;
	new->pLink = NULL;
	if (isLinkedQueueEmpty(pQueue))
		pQueue->pFrontNode = new;
	else
		pQueue->pRearNode->pLink = new;
	pQueue->pRearNode = new;
	pQueue->currentElementCount++;
	return (TRUE);
}

QueueNode *dequeueLQ(LinkedQueue *pQueue)
{
	QueueNode	*node;

	if (!pQueue || isLinkedQueueEmpty(pQueue))
		return (NULL);
	node = pQueue->pFrontNode;
	pQueue->pFrontNode = pQueue->pFrontNode->pLink;
	node->pLink = NULL;
	pQueue->currentElementCount--;
	return (node);
}

QueueNode *peekLQ(LinkedQueue *pQueue)
{
	if (!pQueue || isLinkedQueueEmpty(pQueue))
		return (NULL);
	return (pQueue->pFrontNode);
}

void deleteLinkedQueue(LinkedQueue *pQueue)
{
	if (!pQueue || isLinkedQueueEmpty(pQueue))
		return ;
	while (pQueue->pFrontNode)
	{
		free(dequeueLQ(pQueue));
	}
	free(pQueue);
}

/*int isLinkedQueueFull(LinkedQueue *pQueue)
{
	return (TRUE);
}*/

int isLinkedQueueEmpty(LinkedQueue *pQueue)
{
	return (!pQueue->currentElementCount);
}