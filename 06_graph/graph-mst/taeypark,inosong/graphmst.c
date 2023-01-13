#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedstack.h"
#include "linkedgraph.h"
#include "grapharrayheap.h"
#include "graphmst.h"

Graph *mstKruskal(Graph* pGraph)
{
	int				i;
    Graph           *mstKgraph;
	ArrayMinHeap	*sorted_edge;
	HeapNode		*cur_edge;

	if (pGraph->graphType == GRAPH_UNDIRECTED)
		mstKgraph = createGraph(pGraph->maxVertexCount);
	else
		mstKgraph = createDirectedGraph(pGraph->maxVertexCount);
	sorted_edge = orderEdges(pGraph);
	if (sorted_edge == NULL)
		return (NULL);
	for (i = 0; i < pGraph->currentEdgeCount; i++)
	{
		cur_edge = deleteMinHeapAH(sorted_edge);
		printf("[%d], : (%d,%d)->%d\n",
			i, cur_edge->fromVertexID, cur_edge->toVertexID, cur_edge->key);
		if (mstKgraph->pVertex[cur_edge->fromVertexID] == NOT_USED)
			addVertex(mstKgraph, cur_edge->fromVertexID);
		if (mstKgraph->pVertex[cur_edge->toVertexID] == NOT_USED)
			addVertex(mstKgraph, cur_edge->toVertexID);
		if (checkCycle(mstKgraph, cur_edge->fromVertexID,
				cur_edge->toVertexID) == FALSE)
			addEdgeWithWeight(mstKgraph, cur_edge->fromVertexID, cur_edge->toVertexID, cur_edge->key);
	}
	deleteArrayMinHeap(sorted_edge);
    return (mstKgraph);
}

ArrayMinHeap *orderEdges(Graph* pGraph)
{
	int				y;
    ArrayMinHeap    *minheap;
	ListNode		*move;
    HeapNode		heap_node = {0, };

    minheap = createArrayMinHeap(pGraph->currentEdgeCount);
	if (minheap == NULL)
		return (NULL);
	for (y = 0; y < pGraph->maxVertexCount; y++)
	{
		if (pGraph->pVertex[y] == USED)
		{
			for (move = pGraph->ppEdge[y]->headerNode.pLink; move; move = move->pLink)
			{
				heap_node.key = move->data.weight;
				heap_node.fromVertexID = y;
				heap_node.toVertexID = move->data.vertexID;
				insertMinHeapAH(minheap, heap_node);
			}
		}
	}
	return (minheap);
}

int checkCycle(Graph* pGraph, int fromVertexID, int toVertexID)
{
	int			is_linked = 0;
	ListNode	*move;

	//방문했다면 0 리턴
	if (pGraph->pVertex[fromVertexID] == NOT_USED)
		return (0);
	//도착했다면 1 리턴
	if (fromVertexID == toVertexID)
		return (1);
	//방문 했다고 표시
	pGraph->pVertex[fromVertexID] = NOT_USED;
	move = pGraph->ppEdge[fromVertexID]->headerNode.pLink;
	while (move)
	{
		is_linked = checkCycle(pGraph, move->data.vertexID, toVertexID);
		if (is_linked)
			break ;
		move = move->pLink;
	}
	//이거는 원래대로 복구
	pGraph->pVertex[fromVertexID] = USED;
	return (is_linked);
}
