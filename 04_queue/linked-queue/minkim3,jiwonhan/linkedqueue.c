#include "linkedqueue.h"

Queue *createQueue()
{
    Queue   *queue;
    queue = (Queue *)malloc(sizeof(Queue));
    if (!queue)
        return (NULL);
    memset(queue, 0, sizeof(Queue));
    return (queue);
}

int enqueue(Queue *pQueue, QueueNode element)
{
    QueueNode   *new;

    if (!pQueue)
        return (FALSE);
    new = (QueueNode *)malloc(sizeof(QueueNode));
    if (!new)
        return (FALSE);
    new->data = element.data;
    new->pLink = NULL;
    if (pQueue->currentQueueCount == 0)
        pQueue->pFrontNode = new;
    else
        pQueue->pRearNode->pLink = new;
    pQueue->pRearNode = new;
    pQueue->currentQueueCount++;
    return (TRUE);
}

QueueNode *dequeue(Queue *pQueue)
{
    QueueNode   *node;
    QueueNode   *del_node;

    if (!pQueue || isQueueEmpty(pQueue))
        return (NULL);
    node->data = pQueue->pFrontNode->data;
    del_node = pQueue->pFrontNode;
    pQueue->pFrontNode = pQueue->pFrontNode->pLink;
    del_node->pLink = NULL;
    free(del_node);
    pQueue->currentQueueCount--;
    return (node);
}

QueueNode *peek(Queue *pQueue)
{
    if (!pQueue || isQueueEmpty(pQueue))
        return (NULL);
    return (pQueue->pFrontNode);
}

void deleteQueue(Queue *pQueue)
{
    if (!pQueue || isQueueEmpty(pQueue))
        return ;
    while (pQueue->pFrontNode)
    {
        free(dequeue(pQueue));
    }
    free(pQueue);
}

int isQueueEmpty(Queue *pQueue)
{
    return (!pQueue->currentQueueCount);
}