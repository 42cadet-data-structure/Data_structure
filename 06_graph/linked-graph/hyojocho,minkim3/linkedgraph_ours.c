/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedgraph_ours.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:34:00 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/10 12:10:32 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

LinkedGraph *createLinkedGraph(int maxVertexCount)
{
    LinkedGraph *new_graph;
    int i = 0, j = 0;
	
    new_graph = calloc(1, sizeof(LinkedGraph));
    if (new_graph == NULL)
		return NULL;
    new_graph->maxVertexCount = maxVertexCount;
    new_graph->graphType = GRAPH_UNDIRECTED;
    new_graph->pVertex = calloc(sizeof(int), maxVertexCount);
    if (new_graph->pVertex == NULL) {
        free(new_graph);
		new_graph = NULL;
        return NULL;
    }
    new_graph->ppAdjEdge = calloc(sizeof(LinkedList *), maxVertexCount);
    if (new_graph->ppAdjEdge == NULL) {
        free(new_graph->pVertex);
		new_graph->pVertex = NULL;
        free(new_graph);
		new_graph = NULL;
        return NULL;
    }
    while (i < maxVertexCount) {
        new_graph->ppAdjEdge[i] = createLinkedList();
        if (new_graph->ppAdjEdge[i] == NULL) {
            while (j < i - 1) {
                deleteLinkedList(new_graph->ppAdjEdge[j]);
				j++;
            }
            free(new_graph->ppAdjEdge);
			new_graph->ppAdjEdge = NULL;
            free(new_graph->pVertex);
			new_graph->pVertex = NULL;
            free(new_graph);
			new_graph = NULL;
        }
		i++;
    }
    return new_graph;
}

LinkedGraph *createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *new_graph = createLinkedGraph(maxVertexCount);
    if (new_graph != NULL) {
        new_graph->graphType = GRAPH_DIRECTED;
    }
    return new_graph;
}

void deleteLinkedGraph(LinkedGraph *pGraph)
{
	int i = 0;

    if (pGraph != NULL) {
        while (i < pGraph->maxVertexCount) {
            deleteLinkedList(pGraph->ppAdjEdge[i]);
			i++;
        }
        if (pGraph->ppAdjEdge != NULL)
			free(pGraph->ppAdjEdge);
			pGraph->ppAdjEdge = NULL;
        if (pGraph->pVertex != NULL) 
			free(pGraph->pVertex);
			pGraph->pVertex = NULL;
        free(pGraph);
		pGraph = NULL;
    }
}

int isEmptyLG(LinkedGraph *pGraph)
{
	return (pGraph->currentVertexCount == 0);
}

int addVertexLG(LinkedGraph *pGraph, int vertexID)
{
    if ((pGraph == NULL) || (vertexID >= pGraph->maxVertexCount)\
	|| (checkVertexValid(pGraph, vertexID) == SUCCESS))
		return FAIL;
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return SUCCESS;
}

int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    return addEdgeWithWeightLG(pGraph, fromVertexID, toVertexID, USED);
}

int addLLElementForVertex(LinkedList *pList, int position, GraphVertex vertex) {
    ListNode node = {0,};
    node.data = vertex;
    return addLLElement(pList, position, node);
}

int addEdgeWithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    if ((pGraph == NULL) || (checkVertexValid(pGraph, fromVertexID) == FAIL)\
	|| (checkVertexValid(pGraph, toVertexID) == FAIL))
		return FAIL;
    GraphVertex toNode = {0,};
    toNode.vertexID = toVertexID;
    toNode.weight = weight;
    addLLElementForVertex(pGraph->ppAdjEdge[fromVertexID], 0, toNode);
    pGraph->currentEdgeCount++;
    if (pGraph->graphType == GRAPH_UNDIRECTED) {
        GraphVertex fromNode = {0,};
        fromNode.vertexID = fromVertexID;
        fromNode.weight = weight;
        addLLElementForVertex(pGraph->ppAdjEdge[toVertexID], 0, fromNode);
        pGraph->currentEdgeCount++;
    }
    return SUCCESS;
}

int checkVertexValid(LinkedGraph *pGraph, int vertexID)
{
	return ((pGraph == NULL) || (pGraph->pVertex[vertexID] != USED));
}

int removeVertexLG(LinkedGraph *pGraph, int vertexID)
{
    if ((pGraph == NULL) || (checkVertexValid(pGraph, vertexID) == FAIL))
		return FAIL;
	int i = 0;
    while (i < pGraph->maxVertexCount) {
        removeEdgeLG(pGraph, i, vertexID);
        removeEdgeLG(pGraph, vertexID, i);
		i++;
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    return SUCCESS;
}

int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    if ((pGraph == NULL) || (checkVertexValid(pGraph, fromVertexID) == FAIL)\
	|| (checkVertexValid(pGraph, toVertexID) == FAIL))
		return FAIL;
    deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);
    if (pGraph->graphType == GRAPH_DIRECTED) {
        deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
    }
    return SUCCESS;
}

void deleteGraphNode(LinkedList *pList, int delVertexID)
{
    int position = 0;
    position = findGraphNodePosition(pList, delVertexID);
    if (position >= 0) {
        removeLLElement(pList, position);
    }
}

int findGraphNodePosition(LinkedList *pList, int vertexID)
{
    int position = 0;
    ListNode *pNode = NULL;
    pNode = pList->headerNode.pLink;
    while (pNode != NULL) {
        if (pNode->data.vertexID == vertexID) {
            return position;
        }
        pNode = pNode->pLink;
        position++;
    }
    return -1;
}

int getEdgeCountLG(LinkedGraph *pGraph)
{
	if (pGraph == NULL)
		return 0;
    return pGraph->currentEdgeCount;
}

int getVertexCountLG(LinkedGraph *pGraph)
{
    if (pGraph == NULL) return 0;
    return pGraph->currentVertexCount;
}

int getMaxVertexCountLG(LinkedGraph *pGraph)
{
    if (pGraph == NULL) return 0;
    return pGraph->maxVertexCount;
}

int getGraphTypeLG(LinkedGraph *pGraph)
{
    if (pGraph == NULL) return 0;
    return pGraph->graphType;
}

void displayLinkedGraph(LinkedGraph *pGraph)
{
    int i = 0;
    int j = 0;
    int position = 0;
    ListNode *pNode = NULL;

    if (pGraph != NULL) {
        for (i = 0; i < pGraph->maxVertexCount; i++) {
            for (j = 0; j < pGraph->maxVertexCount; j++) {
                position = findGraphNodePosition(pGraph->ppAdjEdge[i], j);

                if (position >= 0) {
                    pNode = getLLElement(pGraph->ppAdjEdge[i], position);
                    printf("%d ", pNode->data.weight);
                } else {
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
}