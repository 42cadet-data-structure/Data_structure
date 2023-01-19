#include "graphhsp.h"

/* Dijkstra Algorithm에 의해 최단 경로를 찾는 함수,
입력 인자로 받은 startVertexID부터 다른 모든 노드 사이들의 최단 거리를 구한 다음에 반환한다. */
int *shortestPathDijkstra(LinkedGraph *pGraph, int startVertexID)
{
}

/* 특정 노드가 집합 S에 포함되었는지 저장하는 배열 변수 == isSelected,
현재 노드 집합 S 중에서 최단 거리를 가지는 노드 ID인 vertexID를 구한 다음 집합 S에서 지워준다. */
int getMinDistance(int *distance, int *isSelected, int maxNodeCount)
{
}

/* 간선의 가중치를 반환하는 함수 */
int getEdgeWeight(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
}
