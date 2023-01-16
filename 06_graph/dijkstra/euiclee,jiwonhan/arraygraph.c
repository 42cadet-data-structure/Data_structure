#include "arraygraph.h"

ArrayGraph *createArrayGraph(int maxVertexCount)
{
	ArrayGraph *pG;

	if (maxVertexCount < 1)
		return (NULL);
	pG = malloc(sizeof(ArrayGraph));
	if (!pG)
		return (NULL);
	memset(pG, 0, sizeof(ArrayGraph));
	pG->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (!pG->pVertex)
		return (free(pG), NULL);
	pG->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
	if (!pG->ppAdjEdge)
		return (free(pG->pVertex), free(pG), NULL);
	for (int i=0;i<maxVertexCount;i++)
	{
		pG->ppAdjEdge[i] = malloc(sizeof(int) * maxVertexCount);
		if (!pG->ppAdjEdge[i])
		{
			for (int j = 0; j < i;j++)
				free(pG->ppAdjEdge[j]);
			free(pG->ppAdjEdge);
			free(pG->pVertex); free(pG);
			return (NULL);
		}
	}
	memset(pG->pVertex, 0, sizeof(int) * maxVertexCount);
	for (int i = 0;i<maxVertexCount;i++)
		memset(pG->ppAdjEdge[i], NOT_USED, sizeof(int) * maxVertexCount);
	pG->maxVertexCount = maxVertexCount;
	pG->graphType = GRAPH_UNDIRECTED;
	return (pG);
}

ArrayGraph *createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph	*pG;
	
	pG = createArrayGraph(maxVertexCount);
	if (pG != NULL)
		pG->graphType = GRAPH_DIRECTED;
	return (pG);
}

void deleteArrayGraph(ArrayGraph *pGraph)
{
	if (!pGraph)
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
	if (!pGraph || pGraph->currentVertexCount)
		return (0);
	return (1);
}

int addVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if (!pGraph || pGraph->currentVertexCount == pGraph->maxVertexCount)
		return (FALSE);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (TRUE);
}

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph || checkVertexValid(pGraph, fromVertexID) == 0 || checkVertexValid(pGraph, toVertexID) == 0)
		return (FALSE);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = SUCCESS;
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = SUCCESS;
	}
	else if (pGraph->graphType == GRAPH_DIRECTED)
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = SUCCESS;
	return (TRUE);
}

int addEdgeWithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph || checkVertexValid(pGraph, fromVertexID) == 0 || checkVertexValid(pGraph, toVertexID) == 0)
		return (FALSE);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	return (TRUE);
}

int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
	if (!pGraph)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
			return (SUCCESS);
	return (FALSE);
}

int removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if (!pGraph || pGraph->currentVertexCount == pGraph->maxVertexCount)
		return (FALSE);
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (TRUE);
}

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph || checkVertexValid(pGraph, fromVertexID) == 0 || checkVertexValid(pGraph, toVertexID) == 0)
		return (FALSE);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = FAIL;
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = FAIL;
	}
	else if (pGraph->graphType == GRAPH_DIRECTED)
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = FAIL;
	return (TRUE);
}

void displayArrayGraph(ArrayGraph *pGraph)
{
	if (!pGraph)
		return ;
	for (int i=0;i<pGraph->maxVertexCount;i++)
	{
		for(int j=0;j<pGraph->maxVertexCount;j++)
			printf("%d ", pGraph->ppAdjEdge[i][j]);
		printf("\n");
	}
}