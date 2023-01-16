#include <stdio.h>
#include "linkedgraph.h"
#include "graphlinkedlist.h"
#include "priority_queue.h"

#define MAX 6

int main(void)
{
    /*Graph *pG1 = NULL;

    pG1 = createDirectedLinkedGraph(MAX);
    if (pG1 != NULL) {

        for(int i = 0; i < MAX; i++)
            addVertex(pG1, i);

        addEdgeWithWeight(pG1, 0, 1, 4);
        addEdgeWithWeight(pG1, 0, 2, 3);
        addEdgeWithWeight(pG1, 1, 2, 2);
        addEdgeWithWeight(pG1, 2, 3, 1);
        addEdgeWithWeight(pG1, 3, 4, 1);
        addEdgeWithWeight(pG1, 3, 5, 5);
        addEdgeWithWeight(pG1, 4, 5, 6);

        //printf("G1:\n");
        //displayLinkedGraph(pG1);

        deleteLinkedGraph(pG1);
    }*/
    PriorityQueue *pq;
    pq = createQueuPriorityQueue(MAX);
    QueueNode node1;node1.cost=3;node1.toVertex=1;
    QueueNode node2;node2.cost=3;node2.toVertex=3;
    QueueNode node3;node3.cost=2;node3.toVertex=5;
    QueueNode node4;node4.cost=1;node4.toVertex=2;
    enqueue(pq, node2);
    enqueue(pq, node1);
    enqueue(pq, node3);
    enqueue(pq, node4);
    
    QueueNode *tmp = NULL;
    while (!isQueueEmpty(pq))
    {
        tmp = dequeue(pq);
        printf("%d(%d)\n", tmp->cost, tmp->toVertex);
    }
    
    return 0;
}