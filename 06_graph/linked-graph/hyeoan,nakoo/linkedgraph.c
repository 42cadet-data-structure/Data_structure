#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"

LinkedGraph *createLinkedGraph(int maxVertexCount)
{
	LinkedGraph	*linked_graph;

	if (maxVertexCount < 1)
		return (NULL);
	linked_graph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	if (linked_graph == NULL)
		return (NULL);
	linked_graph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (linked_graph->pVertex == NULL)
		return (free(linked_graph), NULL);
	linked_graph->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);
	if (linked_graph->ppAdjEdge == NULL)
		return (free(linked_graph->pVertex), free(linked_graph), NULL);
	for (int i = 0; i < maxVertexCount; i++)
	{
		linked_graph->ppAdjEdge[i] = createLinkedList();
		if (linked_graph->ppAdjEdge[i] == NULL)
		{
			for(int j = 0; j < i; j++)
				free(linked_graph->ppAdjEdge[j]);
			return(free(linked_graph->ppAdjEdge),free(linked_graph->pVertex), free(linked_graph), NULL);	
		}
	}
	linked_graph->maxVertexCount = maxVertexCount;
	linked_graph->currentEdgeCount = 0;
	linked_graph->currentVertexCount = 0;
	linked_graph->graphType = GRAPH_UNDIRECTED;
	memset(linked_graph->pVertex, 0, (sizeof(int) * maxVertexCount));
	return (linked_graph);
}

LinkedGraph *createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph	*linked_direct_graph;

	if (maxVertexCount < 1)
		return (NULL);
	linked_direct_graph = createLinkedGraph(maxVertexCount);
	if (linked_direct_graph == NULL)
		return (NULL);
	linked_direct_graph->graphType = GRAPH_DIRECTED;
	return (linked_direct_graph);
}

void deleteLinkedGraph(LinkedGraph *pGraph)
{
	ListNode *del_node = NULL;

	if (pGraph == NULL)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
        deleteLinkedList(pGraph->ppAdjEdge[i]);
		pGraph->ppAdjEdge[i] = NULL;
	}
	free(pGraph->ppAdjEdge);
	pGraph->ppAdjEdge = NULL;
	free(pGraph->pVertex);
	pGraph->pVertex = NULL;
	free(pGraph);
}

int isEmptyLG(LinkedGraph *pGraph)
{
	if (pGraph == NULL)
		return (FALSE);
	return (pGraph->currentEdgeCount == 0 ? TRUE : FALSE);	
}

int addVertexLG(LinkedGraph *pGraph, int vertexID)
{
	if (pGraph == NULL)
		return (FALSE);
	if (vertexID < 0 || vertexID >= pGraph->maxVertexCount)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
		return (FALSE);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (TRUE);
}

int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	ListNode	element;

    if (checkVertexValid(pGraph, fromVertexID) == FALSE) 
		return (FALSE);
    if (checkVertexValid(pGraph, toVertexID) == FALSE) 
		return (FALSE);
	element.data.vertexID = toVertexID;
	element.data.weight = USED;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, element);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		element.data.vertexID = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID], 0, element);
	}
	pGraph->currentEdgeCount++;
	return (TRUE);
}

int addEdgeWithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode	element;

    if (checkVertexValid(pGraph, fromVertexID) == FALSE) 
		return (FALSE);
    if (checkVertexValid(pGraph, toVertexID) == FALSE) 
		return (FALSE);
	element.data.vertexID = toVertexID;
	element.data.weight = weight;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, element);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		element.data.vertexID = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID], 0, element);
	}
	pGraph->currentEdgeCount++;
	return (TRUE);
}

int checkVertexValid(LinkedGraph *pGraph, int vertexID)
{
	if (pGraph == NULL)
		return (FALSE);
	if (vertexID < 0 || vertexID > pGraph->maxVertexCount)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
		return (TRUE);
	return (FALSE);
}

int removeVertexLG(LinkedGraph *pGraph, int vertexID)
{
	if (checkVertexValid(pGraph, vertexID) == FALSE)
		return (FALSE);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		removeEdgeLG(pGraph,vertexID, i);
		removeEdgeLG(pGraph, i, vertexID);
	}
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (TRUE);
}

int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) == FALSE)
		return (FALSE);
	if (checkVertexValid(pGraph, toVertexID) == FALSE)
		return (FALSE);
	if (findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID) == toVertexID)
		removeLLElement(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		if (findGraphNodePosition(pGraph->ppAdjEdge[toVertexID], fromVertexID) == fromVertexID)
			removeLLElement(pGraph->ppAdjEdge[toVertexID], fromVertexID);
	}
	pGraph->currentEdgeCount--;
	return (TRUE);
}

void deleteGraphNode(LinkedList *pList, int delVertexID)
{
	if (pList == NULL) 
		return;
	if (findGraphNodePosition(pList, delVertexID) == delVertexID)
    	removeLLElement(pList, delVertexID);
}

int findGraphNodePosition(LinkedList *pList, int vertexID)
{
	ListNode	*find_node = NULL;
	int			pos = 0;

	find_node = pList->headerNode.pLink;
	while (find_node != NULL)
	{
		if (find_node->data.vertexID == vertexID)
			return (pos);
		find_node = find_node->pLink;
		pos++;
	}
	return (-1);
}

int getEdgeCountLG(LinkedGraph *pGraph)
{
	if (pGraph == NULL)
		return (FALSE);
	return (pGraph->currentEdgeCount);
}

int getVertexCountLG(LinkedGraph *pGraph)
{
	if (pGraph == NULL)
		return (FALSE);
	return (pGraph->currentVertexCount);
}

int getMaxVertexCountLG(LinkedGraph *pGraph)
{
	if (pGraph == NULL)
		return (FALSE);
	return (pGraph->maxVertexCount);
}

int getGraphTypeLG(LinkedGraph *pGraph)
{
	if (pGraph == NULL)
		return (FALSE);
	return (pGraph->graphType);
}

void displayLinkedGraph(LinkedGraph *pGraph)
{
	ListNode	*cur_node = NULL;
	int			pos = 0;
	if (pGraph == NULL)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			pos = findGraphNodePosition(pGraph->ppAdjEdge[i], j);
			if (pos >= 0)
			{
				cur_node = getLLElement(pGraph->ppAdjEdge[i], pos);
				printf("%d ", cur_node->data.weight);
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}