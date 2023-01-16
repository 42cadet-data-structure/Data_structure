#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graphlinkedlist.h"
#include "grapharrayheap.h"
#include "linkedstack.h"
#include "linkedgraph.h"
#include "graphmst.h"

Graph *mstKruskal(Graph* pGraph)
{
	Graph			*mst_graph = NULL;
	ArrayMinHeap	*sorted_heap = NULL;
	HeapNode		*min_node = NULL;

	if (pGraph == NULL)
		return (NULL);
	mst_graph = createGraph(pGraph->maxVertexCount);
	if (mst_graph == NULL)
		return (NULL);
	sorted_heap = orderEdges(pGraph);
	if (sorted_heap == NULL)
		return (free(mst_graph), NULL);
	/* 왜 pGraph->currentEdgeCount로 했을 땐, 안됐는지 ? 
	-> 교재의 예시에 의하면, <pGraph->maxVertexCount == 6>  <pGraph->currentEdgeCount == 7> 즉 한번 더 참조를 해서
	segmentation fault가 발생한다. checkcycle에서 visited를 maxVertexCount만큼 만들었기 때문에 간선이 더 많은 경우 
	에러가 발생하는게 아닌지 ? - x */
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		min_node = deleteMinHeapAH(sorted_heap);
		if (checkCycle(mst_graph, min_node->fromVertexID, min_node->toVertexID) == FALSE)
		{
			addVertex(mst_graph, min_node->fromVertexID);
			addVertex(mst_graph, min_node->toVertexID);
			addEdgeWithWeight(mst_graph, min_node->fromVertexID, min_node->toVertexID, min_node->key);
			printf("idx- %d (%d, %d) key - %d\n", i, min_node->fromVertexID, min_node->toVertexID, min_node->key);
		}
		free(min_node);
		min_node = NULL;
	}
	return (mst_graph);
}

ArrayMinHeap *orderEdges(Graph* pGraph)
{
	ArrayMinHeap	*sorted_heap = NULL;
	HeapNode		heap_node = {0, };
	ListNode		*list_node = NULL;
	List			*list = NULL;

	if (pGraph == NULL)
		return (NULL);
	sorted_heap = createArrayMinHeap(pGraph->currentEdgeCount);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (checkVertexValid(pGraph, i) == TRUE)
		{
			list = pGraph->ppEdge[i];
			list_node = pGraph->ppEdge[i]->headerNode.pLink;
			while (list_node != NULL)
			{
				if (pGraph->graphType == GRAPH_UNDIRECTED && i < list_node->data.vertexID)
				{
					heap_node.fromVertexID = i;
					heap_node.toVertexID = list_node->data.vertexID;
					heap_node.key = list_node->data.weight;
					insertMinHeapAH(sorted_heap, heap_node);
				}
				list_node = list_node->pLink;
			}
		}
	}
	return (sorted_heap);
}


int pushLSForDFS(Stack* pStack, int nodeID)
{
    StackNode node = {0,};
    node.data = nodeID;
    return push(pStack, node);
}

int checkCycle(Graph* pGraph, int fromVertexID, int toVertexID)
{
	Stack		*stack = NULL;
	StackNode	*stack_node = NULL;
	ListNode	*list_node = NULL;
	int			*visited = NULL;
	int			ret = FALSE;

	if (pGraph == NULL)
		return (FALSE);
	stack = createStack();
	if (stack == NULL)
		return (FALSE);
	visited = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
	if (visited == NULL)
		return (free(stack), FALSE);

	memset(visited, 0, sizeof(int) * (pGraph->maxVertexCount));
	memset(stack, 0 ,sizeof(Stack));
	pushLSForDFS(stack, fromVertexID);
	visited[fromVertexID] = TRUE;
	while (isStackEmpty(stack) == FALSE)
	{
		stack_node = pop(stack);
		if (stack_node == NULL)
			break;
		if (stack_node->data == toVertexID)
		{
			printf("순환 되는 구조 - (%d, %d)\n",fromVertexID, toVertexID);
        	ret = TRUE;
            break;			
		}
		list_node = pGraph->ppEdge[stack_node->data]->headerNode.pLink;
		while (list_node != NULL)
		{
			if (visited[list_node->data.vertexID] == FALSE)
			{
				visited[list_node->data.vertexID] = TRUE;
				pushLSForDFS(stack, list_node->data.vertexID);
			}
			list_node = list_node->pLink;
		}
	}
	free(visited);
	deleteStack(stack);
	return (ret);
}
