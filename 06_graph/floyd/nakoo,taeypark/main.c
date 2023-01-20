#include <stdio.h>
#include "arraygraph.h"
#include "graphhsp.h"

#define MAX_SIZE 6

int main(void)
{
	ArrayGraph *pG1 = NULL;
	int	**floyd_dist = NULL;

	pG1 = createArrayDirectedGraph(MAX_SIZE);
	if (pG1 != NULL) {

		for(int i = 0; i < MAX_SIZE; i++)
			addVertexAG(pG1, i);

		addEdgeWithWeightAG(pG1, 0, 1, 4);
		addEdgeWithWeightAG(pG1, 0, 2, 3);
		addEdgeWithWeightAG(pG1, 1, 2, 2);
		addEdgeWithWeightAG(pG1, 2, 3, 1);
		addEdgeWithWeightAG(pG1, 3, 4, 1);
		addEdgeWithWeightAG(pG1, 3, 5, 5);
		addEdgeWithWeightAG(pG1, 4, 5, 6);

		printf("G1:\n");
		displayArrayGraph(pG1);

		printf("\nFloyd-Warshall\n");
		floyd_dist = floyd(pG1->ppAdjEdge, pG1->currentVertexCount);
		for (int from = 0, to; from < pG1->currentVertexCount; from++)
		{
			for (to = 0; to < pG1->currentVertexCount; to++)
			{
				if (floyd_dist[from][to] == 1e9)
					printf("* ");
				else
					printf("%d ", floyd_dist[from][to]);
			}
			printf("\n");
			free(floyd_dist[from]);
		}
		free(floyd_dist);
		deleteArrayGraph(pG1);
	}
	return 0;
}