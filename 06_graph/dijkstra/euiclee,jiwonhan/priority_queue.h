#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct QueueNode {
    int cost;
    int toVertex;
    struct QueueNode *pNext;
} QueueNode;

typedef struct PriorityQueue {
    int currentElementCount;
    QueueNode *pFrontNode;
    QueueNode *pRearNode;
} PriorityQueue;

PriorityQueue *createQueuPriorityQueue();

int enqueue(PriorityQueue *pq, QueueNode node);

QueueNode *dequeue(PriorityQueue *pq);

QueueNode *peek(PriorityQueue *pq);

void deleteQueue(PriorityQueue *pq);

int isQueueEmpty(PriorityQueue *pq);