#include "floyd.h"

void floyd(int **graph, int max_size)
{
	int dist[max_size][max_size], a, b, c;

	for (a = 0; a < max_size; a++)
		for (b = 0; b < max_size; b++)
 			if (graph[a][b]) dist[a][b] = graph[a][b]; else dist[a][b] = INF;

	for (c = 0; c < max_size; c++) // through
		for (a = 0; a < max_size; a++) // from
			for (b = 0; b < max_size; b++)// to
				if (dist[a][c] + dist[c][b] < dist[a][b])
					dist[a][b] = dist[a][c] + dist[c][b];

	for (int a = 0; a < max_size; a++)
	{
		for (int b = 0; b < max_size; b++)
		{
			if (dist[a][b] != INF)
				printf("%d ", dist[a][b]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}
