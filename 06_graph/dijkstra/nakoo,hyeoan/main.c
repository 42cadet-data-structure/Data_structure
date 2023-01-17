#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "graphhsp.h"

int main() 
{

    int i = 0;
    LinkedGraph *pG1 = NULL;
	int	*pResult = NULL;
    pG1 = createLinkedGraph(6);
    if (pG1 != NULL) {

        for(i = 0; i < 6; i++) {
            addVertex(pG1, i);
        }

        addEdgeWithWeight(pG1, 0, 1, 1);
        addEdgeWithWeight(pG1, 0, 2, 4);
        addEdgeWithWeight(pG1, 1, 2, 2);
        addEdgeWithWeight(pG1, 2, 3, 1);
        addEdgeWithWeight(pG1, 3, 4, 8);
        addEdgeWithWeight(pG1, 3, 5, 3);
        addEdgeWithWeight(pG1, 4, 5, 4);

        printf("G1:\n");
        displayLinkedGraph(pG1);

        printf("\nDijkstra :\n");
        pResult = shortestPathDijkstra(pG1, 0);
		printf("\n");
    }
    return 0;
}