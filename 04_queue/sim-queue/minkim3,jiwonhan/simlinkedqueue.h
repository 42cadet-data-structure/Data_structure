#ifndef SIM_QUEUE_SIMLINKEDQUEUE_H
#define SIM_QUEUE_SIMLINKEDQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simdef.h"

#define TRUE 1
#define FALSE 0

typedef struct QueueNodeType {
	SimCustomer data;
	struct QueueNodeType *pLink;
} QueueNode;

typedef struct LinkedQueueType {
	int currentElementCount;
	QueueNode *pFrontNode;
	QueueNode *pRearNode;
} LinkedQueue;

LinkedQueue *createLinkedQueue();

int enqueueLQ(LinkedQueue *pQueue, QueueNode element);

QueueNode *dequeueLQ(LinkedQueue *pQueue);

QueueNode *peekLQ(LinkedQueue *pQueue);

void deleteLinkedQueue(LinkedQueue *pQueue);

int isLinkedQueueFull(LinkedQueue *pQueue);

int isLinkedQueueEmpty(LinkedQueue *pQueue);

#endif //SIM_QUEUE_SIMLINKEDQUEUE_H
