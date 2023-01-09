
#include "arraygraph.h"

ArrayGraph *createArrayGraph(int maxVertexCount)
{
	ArrayGraph	*array_graph;

	if (maxVertexCount < 1)
		return (NULL);
	array_graph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	if (array_graph == NULL)
		return (NULL);
	array_graph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (array_graph->pVertex == NULL)
		return(free(array_graph), NULL);
	array_graph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
	if (array_graph->ppAdjEdge == NULL)
		return(free(array_graph->pVertex), free(array_graph), NULL);
	for (int i = 0; i < maxVertexCount; i++)
	{
		array_graph->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
		if (array_graph->ppAdjEdge[i] == NULL)
		{
			for(int j = 0; j < i; j++)
				free(array_graph->ppAdjEdge[j]);
			return(free(array_graph->ppAdjEdge),free(array_graph->pVertex), free(array_graph), NULL);
		}
	}
	array_graph->graphType = GRAPH_UNDIRECTED;
	array_graph->maxVertexCount = maxVertexCount;
	array_graph->currentVertexCount = 0;
	memset(array_graph->pVertex, 0, (sizeof(int) * maxVertexCount));
	for (int i = 0; i < maxVertexCount; i++)
		memset(array_graph->ppAdjEdge[i], 0, (sizeof(int) * maxVertexCount));
	return (array_graph);
}

ArrayGraph *createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *array_direct_graph;

	array_direct_graph = createArrayGraph(maxVertexCount);
	if (array_direct_graph == NULL)
		return (NULL);
	array_direct_graph->graphType = GRAPH_DIRECTED;
	return (array_direct_graph);
}

void deleteArrayGraph(ArrayGraph *pGraph)
{
	if (pGraph == NULL)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		free(pGraph->ppAdjEdge[i]);
		pGraph->ppAdjEdge[i] = NULL;
	}
	free(pGraph->ppAdjEdge);
	pGraph->ppAdjEdge = NULL;
	free(pGraph->pVertex);
	pGraph->pVertex = NULL;
	free(pGraph);
}

int isEmptyAG(ArrayGraph *pGraph)
{
	if (pGraph == NULL)
		return (FALSE);
	return (pGraph->currentVertexCount == 0 ? TRUE : FALSE);
}

int addVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if (pGraph == NULL)
		return (FALSE);
	if (pGraph->maxVertexCount < vertexID || vertexID < 0)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
		return (FALSE);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (TRUE);
}

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (checkVertexValid(pGraph, fromVertexID) == FALSE) 
		return (FALSE);
    if (checkVertexValid(pGraph, toVertexID) == FALSE) 
		return (FALSE);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = USED;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = USED;
	return (TRUE);
}

int addEdgeWithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    if (checkVertexValid(pGraph, fromVertexID) == FALSE) 
		return (FALSE);
    if (checkVertexValid(pGraph, toVertexID) == FALSE) 
		return (FALSE);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (TRUE);
}

int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
    if (pGraph == NULL) 
		return (FALSE);
	if (pGraph->maxVertexCount < vertexID || vertexID < 0)
		return (FALSE);		
    if (pGraph->pVertex[vertexID] == USED) 
		return (TRUE);
    return (FALSE);
}

int removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if (checkVertexValid(pGraph, vertexID) == FALSE)
		return (FALSE);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		removeEdgeAG(pGraph, vertexID, i);
		removeEdgeAG(pGraph, i, vertexID);
	}
	pGraph->pVertex[vertexID] = NOT_USED;
	return (TRUE);
}

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) == FALSE)
		return (FALSE);
	if (checkVertexValid(pGraph, toVertexID) == FALSE)
		return (FALSE);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = NOT_USED;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = NOT_USED; 
	return (TRUE);
}

void displayArrayGraph(ArrayGraph *pGraph)
{
	if (pGraph == NULL)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pGraph->maxVertexCount; j++)
			printf("%d ", pGraph->ppAdjEdge[i][j]);
		printf("\n");
	}
}
