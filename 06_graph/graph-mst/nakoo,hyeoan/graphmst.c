#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "graphlinkedlist.h"
#include "linkedstack.h"
#include "linkedgraph.h"
#include "grapharrayheap.h"
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
	for (int i = 0; i < pGraph->currentEdgeCount; i++)
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
		if (mst_graph->currentVertexCount == pGraph->currentVertexCount)
			break ;
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
			printf("이거 아무도 못 찾았을텐데 우리팀은 찾아냄 ㅎㅎ 이거 왜 안되는줄 앎 ? 안알랴줌 (%d,%d)\n",fromVertexID, toVertexID);
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

