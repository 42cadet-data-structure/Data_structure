#include "graphhsp.h"

int **create_2D(int v_cnt)
{
    int **ret;
    int from, to;

    ret = (int **)malloc(sizeof(int *) * v_cnt);
    if (ret == NULL)
        return (NULL);
    for (from = 0; from < v_cnt; from++)
    {
        ret[from] = (int *)malloc(sizeof(int) * v_cnt);
        if (ret[from] == NULL)
        {
            for (to = 0; to < from; to++)
                free(ret[from]);
            return (free(ret), NULL);
        }
    }
    return (ret);
}

int **floyd(int **graph, int v_cnt)
{
    int **floyd_dist;
    int mid, from, to;

    floyd_dist = create_2D(v_cnt);
    if (floyd_dist == NULL)
        return (NULL);
    for (from = 0; from < v_cnt; from++)
    {
        for (to = 0; to < v_cnt; to++)
        {
            if (graph[from][to] == 0)
                floyd_dist[from][to] = 1e9;
            else
                floyd_dist[from][to] = graph[from][to];
        }
    }
    for (mid = 0; mid < v_cnt; mid++)
        for (from = 0; from < v_cnt; from++)
            for (to = 0; to < v_cnt; to++)
                if (floyd_dist[from][to] > floyd_dist[from][mid] + floyd_dist[mid][to])
                    floyd_dist[from][to] = floyd_dist[from][mid] + floyd_dist[mid][to];
    return (floyd_dist);
}
