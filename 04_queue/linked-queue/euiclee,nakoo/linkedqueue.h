#ifndef LINKED_QUEUE_LINKEDQUEUE_H
#define LINKED_QUEUE_LINKEDQUEUE_H

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNodeType {
    char data;
    struct QueueNodeType *pLink;
} QueueNode;

typedef struct QueueType {
    int currentQueueCount;
    QueueNode *pFrontNode;
    QueueNode *pRearNode;

} Queue;

Queue *createQueue();

int enqueue(Queue *pQueue, QueueNode element);

QueueNode *dequeue(Queue *pQueue);

QueueNode *peek(Queue *pQueue);

void deleteQueue(Queue *pQueue);

int isQueueEmpty(Queue *pQueue);

#endif //LINKED_QUEUE_LINKEDQUEUE_H
