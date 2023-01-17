#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "graphlinkedlist.h"
#include "linkedstack.h"
#include "linkedgraph.h"
#include "graphmst.h"

/* Prim Algorithm */
LinkedGraph *mstPrim(LinkedGraph *pGraph, int vertexID)
{
    int         i;
    GraphEdge   min, tmp;
    LinkedGraph *mstPgraph;

    mstPgraph = createLinkedGraph(pGraph->maxVertexCount);
    if (mstPgraph == NULL)
        return (NULL);
    addVertex(mstPgraph, vertexID);
    while (mstPgraph->currentEdgeCount != pGraph->currentVertexCount - 1)
    {
        min.weight = INT_MAX;
        for (i = 0; i < mstPgraph->maxVertexCount; i++)
        {
            if (mstPgraph->pVertex[i] == USED)
            {
                getMinWeightEdge(pGraph, mstPgraph, i, &tmp);
                if (min.weight >= tmp.weight)
                    min = tmp;
            }
        }
        addVertex(mstPgraph, min.vertexIDTo);
        addVertex(mstPgraph, min.vertexIDFrom);
        addEdgeWithWeight(mstPgraph, min.vertexIDFrom, min.vertexIDTo, min.weight);
    }
    return (mstPgraph);
}

/* mstVertexID와 부속된 간선 중 가중치가 가장 작으면서 순환을 발생시키지 않는 간선을 선택 */
void getMinWeightEdge(LinkedGraph *pGraph, LinkedGraph *pMST, int mstVertexID, GraphEdge *pMinWeightEdge)
{
    ListNode    *move;

    pMinWeightEdge->weight = INT_MAX;
    pMinWeightEdge->vertexIDFrom = mstVertexID;
    move = pGraph->ppEdge[mstVertexID]->headerNode.pLink;
    while (move)
    {
        // 최소이고, 유효(-> 순환이 안 된다.)하면
        if (pMinWeightEdge->weight >= move->data.weight
            && checkCycle(pMST, mstVertexID, move->data.vertexID) == 0)
        {
            pMinWeightEdge->weight = move->data.weight;
            pMinWeightEdge->vertexIDTo = move->data.vertexID;
        }
        move = move->pLink;
    }
}

/* 기존의 신장 트리에 특정 간선이 존재하는지를 점검하는 함수로 getMinWeightEdge()에서 호출한다. */
// int checkEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
// {
// }

int checkCycle(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
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
