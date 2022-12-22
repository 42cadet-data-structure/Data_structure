#ifndef CIRCULAR_ARRAY_QUEUE_ARRAYQUEUE_H
#define CIRCULAR_ARRAY_QUEUE_ARRAYQUEUE_H

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNodeType {
    char data;
} QueueNode;

typedef struct QueueType {
    int currentElementCount;
    int maxElementCount;
    int front;
    int rear;
    QueueNode *pElement;
} Queue;


Queue *createQueue(int maxElementCount);

int enqueue(Queue *pQueue, QueueNode element);

QueueNode *dequeue(Queue *pQueue);

QueueNode *peek(Queue *pQueue);

void deleteQueue(Queue *pQueue);

int isQueueFull(Queue *pQueue);

int isQueueEmpty(Queue *pQueue);

#endif //CIRCULAR_ARRAY_QUEUE_ARRAYQUEUE_H
