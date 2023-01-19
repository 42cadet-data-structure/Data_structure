/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:21:51 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/15 21:40:50 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. 출발노드 설정
// 2. 출발노드를 기준으로 각 노드의 최소비용을 저장
// 3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택
// 4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소비용을 갱신
// 5. 위의 3 ~ 4 과정을 반복

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max 1000000

int	number = 6;
int	visited[6] = {0, };
int	distance[6] = {0, };

int graph[6][6] = {
	{0, 2, 5, 1, max, max},
	{2, 0, 3, 2, max, max},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, max},
	{max, max, 1, 1, 0, 2},
	{max, max, 5, max, 2, 0}
};

int get_small_index() {
	int min = max;
	int index = 0;

	for (int i = 0; i < number; i++)
	{
		if ((distance[i] < min) && !visited[i])
		{
			min = distance[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start)
{
	for (int i = 0; i < number; i++)
		distance[i] = graph[start][i];
	visited[start] = 1;
	for (int i = 0; i < number - 2; i++)
	{
		int current = get_small_index();
		visited[current] = 1;
		for (int j = 0; j < 6; j++)
		{
			if (!visited[j])
			{
				if (distance[current] + graph[current][j] < distance[j])
					distance[j] = distance[current] + graph[current][j];
			}
		}
	}
}

int main()
{
	dijkstra(0);
	for (int i = 0; i < number; i++)
	{
		printf("%d ", distance[i]);
	}
}