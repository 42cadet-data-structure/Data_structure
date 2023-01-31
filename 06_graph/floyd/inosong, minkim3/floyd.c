#include "floyd.h"

static void free_all(int **floyd, int count)
{
	int	i = 0;
	while (i < count)
		free(floyd[i++]);
	free (floyd);
}

static void init(ArrayGraph *Graph, int **floyd, int count)
{
    int y = 0, x = 0;

	while (y < count)
	{
		x = 0;
		while (x < count)
		{
			if (y == x)
				floyd[y][x] = 0;
			else if (Graph->ppAdjEdge[y][x] == 0)
				floyd[y][x] = 9999;
			else
				floyd[y][x] = Graph->ppAdjEdge[y][x];
			x++; 
		}
		y++;
	}
}

static int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}


int **floyd(ArrayGraph *graph, int	count)
{
	int	**floyd;
	int	i = 0;
	int	a = 0,b = 0,c = 0;

	floyd = malloc(sizeof(int *) * count);
	if (!floyd)
		return (NULL);
	while (i < count)
	{
		floyd[i] = malloc(sizeof(int) * count);
		if (floyd[i] == NULL)
		{
			free_all(floyd, i);
			return (NULL);
		}
		i++;
	}
	init(graph, floyd, count);
	while (b < count)
	{
		a = 0;
		while (a < count)
		{
			c = 0;
			while (c < count)
			{
				floyd[a][c] = min(floyd[a][c], floyd[a][b] + floyd[b][c]);
				c++;
			}
			a++;
		}
		b++;
	}
	return (floyd);
}

void display_floyd(int **floyd, int count)
{
	int y = 0, x = 0;

	while (y < count)
	{
		x = 0;
		while (x < count)
		{
			printf("%d ", floyd[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}