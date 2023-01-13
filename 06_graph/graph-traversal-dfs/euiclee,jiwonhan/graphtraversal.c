#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "linkedstack.h"
#include "graphtraversal.h"

void traversalDFS(LinkedGraph* pGraph, int startVertexID)
{
	LinkedStack	*stack;
	StackNode	node;
	int	tmpVertexID;
	ListNode	*listNode;

	if (!pGraph && !checkVertexValid(pGraph, startVertexID))
		return ;
	int visited[pGraph->maxVertexCount];
	for (int i = 0;i<pGraph->maxVertexCount;i++)
		visited[i] = NOTVISITED;
	stack = createLinkedStack();
	if (!stack)
		return ;
	node.data = startVertexID;
	node.pLink = NULL;
	pushLS(stack, node);
	visited[startVertexID] = VISITED;
	while (!isLinkedStackEmpty(stack))
	{
		tmpVertexID = popLS(stack)->data;
		printf("%d ", tmpVertexID);
		listNode = pGraph->ppAdjEdge[tmpVertexID]->headerNode.pLink;
		while (listNode)
		{
			if (visited[listNode->data.vertexID] == NOTVISITED)
			{
				node.data = listNode->data.vertexID;
				pushLS(stack, node);
				visited[listNode->data.vertexID] = VISITED;
			}
			listNode = listNode->pLink;
		}
	}
}
