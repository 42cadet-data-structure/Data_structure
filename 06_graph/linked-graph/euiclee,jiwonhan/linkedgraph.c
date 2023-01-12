#include "graphlinkedlist.h"
#include "linkedgraph.h"

static void	ft_free(LinkedGraph *pG, int edgePosition)
{
	if (!pG)
		return ;
	if (pG->ppAdjEdge)
	{
		for(int i = 0; i< edgePosition;i++)
			free(pG->ppAdjEdge[i]), pG->ppAdjEdge[i] = NULL;
		free(pG->ppAdjEdge);
		pG->ppAdjEdge = NULL;
	}
	if (pG->pVertex)
		free(pG->pVertex), pG->pVertex = NULL;
	free(pG);
}

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
		return (ft_free(pG, -1),  NULL);
	pG->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);
	if (!pG->ppAdjEdge)
		return (ft_free(pG, -1), NULL);
	for (int i = 0; i < maxVertexCount; i++)	
	{
		pG->ppAdjEdge[i] = createLinkedList();
		if (pG->ppAdjEdge[i] == NULL)
			return (ft_free(pG, i), NULL);
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
	ft_free(pGraph, pGraph->maxVertexCount);
}

int isEmptyLG(LinkedGraph *pGraph)
{
	if (!pGraph || pGraph->currentVertexCount)
		return (0);
	return (1);
}

int addVertexLG(LinkedGraph *pGraph, int vertexID)
{
	if (!pGraph || pGraph->currentVertexCount == pGraph->maxVertexCount \
		|| pGraph->pVertex[vertexID] == USED)
		return (FALSE);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (TRUE);
}

int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgeWithWeightLG(pGraph, fromVertexID, toVertexID, 0));
}

static int checkEdgeValid(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	int i;
	int position = -1;
	if (!pGraph)
		return (FALSE);
	position = findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	if (position >= 0)
		return (FALSE);
	return (TRUE);
}

int addEdgeWithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode node;

	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID) \
		|| checkEdgeValid(pGraph, fromVertexID, toVertexID, weight) == 0)
		return (FALSE);
	node.data.vertexID = toVertexID;
	node.data.weight = weight;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, node);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		node.data.vertexID = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID], 0, node);
	}
	pGraph->currentEdgeCount++;
	return (TRUE);
}

int checkVertexValid(LinkedGraph *pGraph, int vertexID)
{
	if (!pGraph)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
		return (TRUE);
	return (FALSE);
}

int removeVertexLG(LinkedGraph *pGraph, int vertexID)
{
	if (!pGraph)
		return (FALSE);
	pGraph->pVertex[vertexID] = NOT_USED;
	for (int i=0;i<pGraph->currentVertexCount;i++)
		deleteGraphNode(pGraph->ppAdjEdge[i], vertexID);
	clearLinkedList(pGraph->ppAdjEdge[vertexID]);
	pGraph->currentVertexCount--;
	return (TRUE);
}

int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	ListNode node;

	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID) \
		|| checkEdgeValid(pGraph, fromVertexID, toVertexID, 0))
		return (FALSE);
	node.data.vertexID = toVertexID;
	node.data.weight = FAIL;
	removeLLElement(pGraph->ppAdjEdge[fromVertexID], 0);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		node.data.vertexID = fromVertexID;
		removeLLElement(pGraph->ppAdjEdge[toVertexID], 0);
	}
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
	if (!pGraph)
		return ;
	ListNode *node;

	for (int i=0;i<pGraph->maxVertexCount;i++)
	{
		for (int j = 0;j<pGraph->maxVertexCount;j++)
		{
			node = (pGraph->ppAdjEdge[i]->headerNode.pLink);
			int tmp = 0;
			while (node)
			{
				if (j == node->data.vertexID)
				{
					tmp =  node->data.weight;
					if (node->data.weight == 0)
						tmp = 1;
					break ;
				}
				node = node->pLink;
			}
			printf("%d ", tmp);
		}printf("\n");
	}
}
