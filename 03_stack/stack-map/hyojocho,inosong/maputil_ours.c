/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputil_ours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:56:27 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/18 11:28:37 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maputil.h"
#include "mapdef.h"
#include "mapstack.h"
#include <stdio.h>
#include <unistd.h>

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (rows < 8)
	{
		cols = 0;
		while (cols < 8)
		{
			if (mazeArray[rows][cols] == NOT_VISIT || mazeArray[rows][cols] == 3)
				printf(" ");
			else if (mazeArray[rows][cols] == WALL)
				printf("*");
			else if (mazeArray[rows][cols] == VISIT)
				printf(".");
			cols++;
		}
		printf("\n");
		rows++;
	}
}

void findPath(int mazeArray[HEIGHT][WIDTH],
              MapPosition startPos,
              MapPosition endPos,
              Stack *pStack)
{
	if (mazeArray[startPos.y][startPos.x] != 0)
	{
		printf("error\n");
		return ;
	}
	StackNode	node;
	MapPosition	curpos;

	curpos.x = startPos.x;
	curpos.y = startPos.y;
	mazeArray[curpos.y][curpos.x] = 2;
	node.data = curpos;
	curpos.direction = 0;
	push(pStack, node);

	while (!(pStack->currentElementCount == 1 && mazeArray[pStack->pTopElement->data.y + 1][pStack->pTopElement->data.x] != 0 && mazeArray[pStack->pTopElement->data.y][pStack->pTopElement->data.x + 1] != 0
			&& mazeArray[pStack->pTopElement->data.y - 1][pStack->pTopElement->data.x] != 0 && mazeArray[pStack->pTopElement->data.y][pStack->pTopElement->data.x - 1] != 0))
	{
		curpos.x = pStack->pTopElement->data.x;
		curpos.y = pStack->pTopElement->data.y;
		if (mazeArray[curpos.y][curpos.x + 1] == 0 && curpos.x + 1 < WIDTH)
		{
			mazeArray[curpos.y][curpos.x + 1] = 2;
			curpos.x = curpos.x + 1;
			node.data = curpos;
			push(pStack, node);
		}
		else if (mazeArray[curpos.y + 1][curpos.x] == 0 && curpos.y + 1 < HEIGHT)
		{
			mazeArray[curpos.y + 1][curpos.x] = 2;
			curpos.y = curpos.y + 1;
			node.data = curpos;
			push(pStack, node);
		}
		else if (mazeArray[curpos.y][curpos.x - 1] == 0 && curpos.x - 1 >= 0)
		{
			mazeArray[curpos.y][curpos.x - 1] = 2;
			curpos.x = curpos.x - 1;
			node.data = curpos;
			push(pStack, node);
		}
		else if (mazeArray[curpos.y - 1][curpos.x] == 0 && curpos.y - 1 >= 0)
		{
			mazeArray[curpos.y - 1][curpos.x] = 2;
			curpos.y = curpos.y - 1;
			node.data = curpos;
			push(pStack, node);
		}
		else if (pStack->currentElementCount > 1)
		{
			mazeArray[curpos.y][curpos.x] = 3;
			pop(pStack);
		}
		if (pStack->pTopElement->data.x == endPos.x && pStack->pTopElement->data.y == endPos.y)
		{
			printf("success\n");
			return;
		}
		if (pStack->pTopElement->data.x == startPos.x && pStack->pTopElement->data.y == startPos.y)
		{
			printf("fail\n");
			return;
		}
	}
}

void showPath(Stack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode	*tmp;

	if (pStack->currentElementCount == 1)
		return;
	while (pStack->pTopElement != NULL)
	{
		tmp = peek(pStack);
		printf("(%d, %d)", tmp->data.x, tmp->data.y);
		if (pStack->pTopElement->pLink != NULL)
			printf(" <- ");
		pStack->pTopElement = pStack->pTopElement->pLink;
	}
	printf("\n");
	printMaze( mazeArray);
}
