#include "graphhsp.h"

void floydWarshall(int **graph, int max_size)
{
    int dp[max_size][max_size];
    for(int i=0;i<max_size;i++){
        for(int j = 0;j < max_size;j++)
        {
            if (graph[i][j])
                dp[i][j] = graph[i][j];
            else if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
        }
    }

    for(int i = 0;i<max_size;i++)
        for(int j = 0;j<max_size;j++)
            for(int k = 0;k<max_size;k++)
                if (dp[j][i] + dp[i][k] < dp[j][k])
                    dp[j][k] = dp[j][i] + dp[i][k];
    
    
    for(int i=0;i<max_size;i++)
    {
        for(int j = 0;j<max_size;j++)
        {
            if (dp[i][j] != INF)
                printf("%-3d ", dp[i][j]);
            else
                printf("INF ");
        }
        printf("\n");
    }
}