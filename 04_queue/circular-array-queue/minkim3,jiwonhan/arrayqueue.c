#include "arrayqueue.h"

Queue *createQueue(int maxElementCount)
{
    Queue   *queue;
    queue = (Queue *)malloc(sizeof(Queue));
    if (!queue)
        return (NULL);
    queue->pElement = (QueueNode *)malloc(sizeof(QueueNode) * maxElementCount);
    if (!queue->pElement)
    {
        free(queue);
        return (NULL);
    }
    queue->currentElementCount = 0;
    queue->maxElementCount = maxElementCount;
    queue->front = 0;
    queue->rear = 0;
    return (queue);
}

int enqueue(Queue *pQueue, QueueNode element)
{
    if (!pQueue || isQueueFull(pQueue))
        return (FALSE);
    pQueue->pElement[pQueue->rear] = element;
    pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
    pQueue->currentElementCount++;
    return (TRUE);
}

QueueNode *dequeue(Queue *pQueue)
{
    if (!pQueue || isQueueEmpty(pQueue))
        return (NULL);
    QueueNode *node;
    node->data = pQueue->pElement[pQueue->front].data;
    pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
    pQueue->currentElementCount--;
    return(node);
}


QueueNode *peek(Queue *pQueue)
{
    if (!pQueue || isQueueEmpty(pQueue))
        return (NULL);
    return(&pQueue->pElement[pQueue->front]);
}

void deleteQueue(Queue *pQueue)
{
    if (!pQueue)
        return ;
    if (pQueue->pElement != NULL)
    {
        free(pQueue->pElement);
        pQueue->pElement = NULL;
    }
    free(pQueue);
}

int isQueueFull(Queue *pQueue)
{
    if (!pQueue)
        return (FALSE);
    return (pQueue->currentElementCount == pQueue->maxElementCount);
}

int isQueueEmpty(Queue *pQueue)
{
    if (!pQueue)
        return (FALSE);
    return (!pQueue->currentElementCount);
}