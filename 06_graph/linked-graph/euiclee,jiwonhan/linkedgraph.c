#include "graphlinkedlist.h"
#include "linkedgraph.h"

LinkedGraph *createLinkedGraph(int maxVertexCount)
{
	LinkedGraph	*pG;

	if (maxVertexCount < 1)
		return (NULL);
	pG = malloc(sizeof(LinkedGraph));
	if (!pG)
		return (NULL);
	memset(pG, 0, sizeof(LinkedGraph));
	pG->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (!pG->pVertex)
		return (free(pG), NULL);
	pG->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);
	if (!pG->ppAdjEdge)
		return (free(pG->pVertex), free(pG), NULL);
	for (int i = 0; i < maxVertexCount; i++)	
	{
		pG->ppAdjEdge[i] = createLinkedList();
		if (pG->ppAdjEdge[i] == NULL)
		{
			for (int j = 0; j < i;j++)
				free(pG->ppAdjEdge[j]);
			free(pG->ppAdjEdge); 
			free(pG->pVertex); free(pG);
			return (NULL);
		}
	}
	memset(pG->pVertex, 0, sizeof(int) * maxVertexCount);
	pG->maxVertexCount = maxVertexCount;
	pG->graphType = GRAPH_UNDIRECTED;
	return (pG);
}

LinkedGraph *createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph	*pG;

	pG = createLinkedGraph(maxVertexCount);
	if (pG != NULL)
		pG->graphType = GRAPH_DIRECTED;
	return (pG);
}

void deleteLinkedGraph(LinkedGraph *pGraph)
{
	if (!pGraph)
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
	if (!pGraph || pGraph->currentVertexCount)
		return (0);
	return (1);
}

int addVertexLG(LinkedGraph *pGraph, int vertexID)
{
	if (!pGraph || pGraph->currentVertexCount == pGraph->maxVertexCount)
		return (FALSE);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (TRUE);
}

int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	ListNode node;

	if (!pGraph || checkVertexValid(pGraph, fromVertexID) == 0 || checkVertexValid(pGraph, toVertexID) == 0)
		return (FALSE);
	node.data.vertexID = toVertexID;
	node.data.weight = SUCCESS;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, node);
		node.data.vertexID = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID], 0, node);
	}
	else if (pGraph->graphType == GRAPH_DIRECTED)
		addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, node);
	pGraph->currentEdgeCount++;
	return (TRUE);
}

int addEdgeWithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode node;

	if (!pGraph || checkVertexValid(pGraph, fromVertexID) == 0 || checkVertexValid(pGraph, toVertexID) == 0)
		return (FALSE);
	node.data.vertexID = toVertexID;
	node.data.weight = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, node);
		node.data.vertexID = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID], 0, node);
	}
	else if (pGraph->graphType == GRAPH_DIRECTED)
		addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, node);
	pGraph->currentEdgeCount++;
	return (TRUE);
}

int checkVertexValid(LinkedGraph *pGraph, int vertexID)
{
	if (!pGraph)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
			return (SUCCESS);
	return (FALSE);
}

int removeVertexLG(LinkedGraph *pGraph, int vertexID)
{
	if (!pGraph || pGraph->currentVertexCount == pGraph->maxVertexCount)
		return (FALSE);
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (TRUE);
}

int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	ListNode node;

	if (!pGraph || checkVertexValid(pGraph, fromVertexID) == 0 || checkVertexValid(pGraph, toVertexID) == 0)
		return (FALSE);
	node.data.vertexID = toVertexID;
	node.data.weight = FAIL;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		removeLLElement(pGraph->ppAdjEdge[fromVertexID], 0);
		node.data.vertexID = fromVertexID;
		removeLLElement(pGraph->ppAdjEdge[toVertexID], 0);
		pGraph->currentEdgeCount--;
	}
	else if (pGraph->graphType == GRAPH_DIRECTED)
		removeLLElement(pGraph->ppAdjEdge[fromVertexID], 0);
	pGraph->currentEdgeCount--;
	return (TRUE);
}

void deleteGraphNode(LinkedList *pList, int delVertexID)
{
	int	position;

	position = findGraphNodePosition(pList, delVertexID);
	if (position >= 0)
	removeLLElement(pList, position);
}

int findGraphNodePosition(LinkedList *pList, int vertexID)
{
	int	position = 0;
	ListNode *tmp;

	if (!pList)
		return (0);
	tmp = pList->headerNode.pLink;
	while (tmp)
	{
		if (tmp->data.vertexID == vertexID)
			return (position);
		tmp = tmp->pLink;
		++position;
	}
	return (-1);
}

int getEdgeCountLG(LinkedGraph *pGraph)
{
	return (pGraph->currentEdgeCount);
}

int getVertexCountLG(LinkedGraph *pGraph)
{
	return (pGraph->currentVertexCount);
}

int getMaxVertexCountLG(LinkedGraph *pGraph)
{
	return (pGraph->maxVertexCount);
}

int getGraphTypeLG(LinkedGraph *pGraph)
{
	return (pGraph->graphType);
}

void displayLinkedGraph(LinkedGraph *pGraph)
{
	int	position;
	if (!pGraph)
		return ;
	for (int i=0;i<pGraph->maxVertexCount;i++)
	{
		for (int j=0;j<pGraph->maxVertexCount;j++)
		{
			position = findGraphNodePosition(pGraph->ppAdjEdge[i], j);
			if (position >= 0)
				printf("%d ", getLLElement(pGraph->ppAdjEdge[i], position)->data.weight);
			else
				printf("0 ");
		}
		printf("\n");
	}
}
