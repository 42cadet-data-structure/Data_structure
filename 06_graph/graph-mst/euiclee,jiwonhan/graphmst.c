#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedstack.h"
#include "linkedgraph.h"
#include "grapharrayheap.h"
#include "graphmst.h"

Graph *mstKruskal(Graph* pGraph)
{
	Graph			*ret;
	ArrayMinHeap	*heap;
	HeapNode		*heapnode;

	if (!pGraph)
		return (NULL);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		ret = createGraph(pGraph->maxVertexCount);
	else if (pGraph->graphType == GRAPH_DIRECTED)
		ret = createDirectedGraph(pGraph->maxVertexCount);
	if (!ret)
		return (NULL);
	if (!(heap = orderEdges(pGraph)))
		return (NULL);
	for (int i = 0; i < pGraph->currentEdgeCount && ret->currentVertexCount < pGraph->currentVertexCount;i++)
	{
		heapnode = deleteMinHeapAH(heap);
		if (heapnode && !checkCycle(pGraph, heapnode->fromVertexID, heapnode->toVertexID))
		{
			if (!checkVertexValid(ret, heapnode->fromVertexID))
				addVertex(ret, heapnode->fromVertexID);
			if (!checkVertexValid(ret, heapnode->toVertexID))
				addVertex(ret, heapnode->toVertexID);
			addEdgeWithWeight(ret, heapnode->fromVertexID, heapnode->toVertexID, heapnode->key);
			printf("[%d] %d->%d(%d)\n", i, heapnode->fromVertexID, heapnode->toVertexID, heapnode->key);
		}
		free(heapnode);
	}
	return (ret);
}

ArrayMinHeap *orderEdges(Graph* pGraph)
{
	ArrayMinHeap	*heap;
	HeapNode		heapnode;
	ListNode		*ListNode;

	heap = createArrayMinHeap(pGraph->currentEdgeCount);
	if (!heap)
		return (NULL);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (checkVertexValid(pGraph, i))
		{
			for(ListNode = pGraph->ppEdge[i]->headerNode.pLink; ListNode; ListNode = ListNode->pLink)
			{
				if (pGraph->graphType == GRAPH_DIRECTED || (pGraph->graphType == GRAPH_UNDIRECTED && i < ListNode->data.vertexID))
				{
					heapnode.fromVertexID = i;
					heapnode.key = ListNode->data.weight;
					heapnode.toVertexID = ListNode->data.vertexID;
					insertMinHeapAH(heap, heapnode);
				}
			}
		}
	}
	return (heap);
}

int checkCycle(Graph* pGraph, int fromVertexID, int toVertexID)
{
	Stack *stack;
	StackNode *stackNode;
	StackNode newStackNode;
	ListNode *listNode;

	stack = createStack();
	if (!stack)
		return (FALSE);
	int	visited[pGraph->maxVertexCount];
	for(int i=0;i<pGraph->maxVertexCount;i++)
		visited[i] = NOT_USED;

	newStackNode.data = fromVertexID;
	newStackNode.pLink = NULL;
	push(stack, newStackNode);
	visited[fromVertexID] = USED;
	while (!isStackEmpty(stack))
	{
		stackNode = pop(stack);
		if (stackNode && stackNode->data == toVertexID)
			return (TRUE);
		for (listNode = pGraph->ppEdge[stackNode->data]->headerNode.pLink; listNode; listNode = listNode->pLink)
		{
			if (!visited[listNode->data.vertexID])
			{
				visited[listNode->data.vertexID] = USED;
				newStackNode.data = listNode->data.vertexID;
				push(stack, newStackNode);
			}
		}
		free(stackNode);
	}
	deleteStack(stack);
	return (FALSE);
}
