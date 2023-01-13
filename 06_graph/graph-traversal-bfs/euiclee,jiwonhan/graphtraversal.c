#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "linkedqueue.h"
#include "graphtraversal.h"

void traversalBFS(Graph *pGraph, int startVertexID) 
{
	Queue	*queue;
	QueueNode node;
	int tmpVertexID;
	ListNode *listNode;

	if (!pGraph)
		return ;
	int visited[pGraph->maxVertexCount];
	for (int i = 0;i<pGraph->maxVertexCount;i++)
		visited[i] = NOTVISITED;
	
	queue = createQueue();
	if (!queue)
		return ;
	node.data = startVertexID;
	node.pLink = NULL;
	enqueue(queue, node);
	visited[startVertexID] = VISITED;
	while (queue->currentElementCount > 0)
	{
		tmpVertexID = dequeue(queue)->data;
		printf("%d ", tmpVertexID);
		listNode = pGraph->ppEdge[tmpVertexID]->headerNode.pLink;
		while (listNode)
		{
			if (visited[listNode->data.vertexID] == NOTVISITED)
			{
				node.data = listNode->data.vertexID;
				enqueue(queue, node);
				visited[listNode->data.vertexID] = VISITED;
			}
			listNode = listNode->pLink;
		}
	}
}
