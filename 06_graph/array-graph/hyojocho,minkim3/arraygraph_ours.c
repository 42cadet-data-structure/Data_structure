/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraygraph_ours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:26:54 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/10 11:39:48 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraygraph.h"

static void deleteArrayNode(ArrayGraph *pGraph, int num)
{
	int	i = 0;
	if (pGraph == NULL)
		return ;
	while (num > i)
	{
		free(pGraph->ppAdjEdge[i]);
		pGraph->ppAdjEdge[i] = NULL;
		i++;
	}
	free(pGraph->ppAdjEdge);
	pGraph->ppAdjEdge = NULL;
	free(pGraph->pVertex);
	pGraph->pVertex = NULL;
	free(pGraph);
	pGraph = NULL;
}

ArrayGraph *createArrayGraph(int maxVertexCount)
{
    ArrayGraph *new_node = NULL;
    int i = 0, j = 0;
	
    if (maxVertexCount < 1)
		return NULL;
    new_node = calloc(1, sizeof(ArrayGraph));
    if (new_node == NULL)
		return NULL;
    new_node->graphType = GRAPH_UNDIRECTED;
    new_node->maxVertexCount = maxVertexCount;
    new_node->pVertex = calloc(sizeof(int), maxVertexCount);
    if (new_node->pVertex == NULL) {
        free(new_node);
		new_node = NULL;
        return NULL;
    }
    new_node->ppAdjEdge = calloc(sizeof(int *), maxVertexCount);
    if (new_node->ppAdjEdge == NULL) {
        free(new_node->pVertex);
		new_node->pVertex = NULL;
        free(new_node);
		new_node = NULL;
        return NULL;
    }
    for (i = 0; i < maxVertexCount; i++) {
        new_node->ppAdjEdge[i] = calloc(sizeof(int), maxVertexCount);
        if (new_node->ppAdjEdge[i] == NULL) {
            deleteArrayNode(new_node, i);
        }
    }
    return new_node;
}


ArrayGraph *createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *new_array;

	new_array = createArrayGraph(maxVertexCount);
	if (!new_array)
		return (NULL);
	new_array->graphType = GRAPH_DIRECTED;
	return (new_array);
}

void deleteArrayGraph(ArrayGraph *pGraph)
{
	deleteArrayNode(pGraph, pGraph->currentVertexCount);
}

int isEmptyAG(ArrayGraph *pGraph)
{
	if (pGraph == NULL) return FAIL;
	return (pGraph->currentVertexCount == 0);
}

int addVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if (pGraph == NULL || (vertexID > pGraph->maxVertexCount)\
	|| (pGraph->pVertex[vertexID] == USED)) 
		return FAIL;
	pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return SUCCESS;
}

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	return addEdgeWithWeightAG(pGraph, fromVertexID, toVertexID, USED);
}

int addEdgeWithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    if (pGraph == NULL || (checkVertexValid(pGraph, fromVertexID) == FAIL)\
	|| (checkVertexValid(pGraph, toVertexID) == FAIL)) 
		return FAIL;
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
    if (pGraph->graphType == GRAPH_UNDIRECTED) {
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
    }
    return SUCCESS;
}

int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
	if (pGraph == NULL) return FAIL;
    if (pGraph->pVertex[vertexID] == USED) return SUCCESS;
    return FAIL;
    //return (pGraph != NULL && (pGraph->pVertex[vertexID] == USED));
}

int removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
    int i = 0;
    if ((pGraph == NULL) || (checkVertexValid(pGraph, vertexID) == FAIL))
		return FAIL;
	while (i < pGraph->maxVertexCount)
	{
		removeEdgeAG(pGraph, vertexID, i);
        removeEdgeAG(pGraph, i, vertexID);
		i++;
	}
    pGraph->pVertex[vertexID] = NOT_USED;
    return SUCCESS;
}

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    if ((pGraph == NULL) || (checkVertexValid(pGraph, fromVertexID) == FAIL)\
	|| (checkVertexValid(pGraph, toVertexID) == FAIL) )
		return FAIL;
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = NOT_USED;
    if (pGraph->graphType == GRAPH_UNDIRECTED) {
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = NOT_USED;
    }
    return SUCCESS;
}

void displayArrayGraph(ArrayGraph *pGraph)
{
    int i = 0, j = 0;
    if (pGraph == NULL)
		return;
    for (i = 0; i < pGraph->maxVertexCount; i++) {
        for (j = 0; j < pGraph->maxVertexCount; j++) {
            printf("%d ", pGraph->ppAdjEdge[i][j]);
        }
        printf("\n");
    }
}