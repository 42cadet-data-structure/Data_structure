/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputil_ours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inosong <inosong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:56:27 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/17 19:55:22 by inosong          ###   ########.fr       */
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
			if (mazeArray[rows][cols] == 0 || mazeArray[rows][cols] == 3)
				printf(" ");
			else if (mazeArray[rows][cols] == 1)
				printf("*");
			else if (mazeArray[rows][cols] == 2)
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
	MapPosition	*check;

	curpos.x = startPos.x;
	curpos.y = startPos.y;
	mazeArray[curpos.y][curpos.x] = 2;
	node.data = curpos;
	curpos.direction = 0;
	push(pStack, node);
	printf(" x:%d y:%d ",pStack->pTopElement->data.x,pStack->pTopElement->data.y);
	
	// check = &(pStack->pTopElement->data);
	// printf ("ab %d",check->x);
	while (!(pStack->currentElementCount == 1 && mazeArray[pStack->pTopElement->data.y + 1][pStack->pTopElement->data.x] != 0 && mazeArray[pStack->pTopElement->data.y][pStack->pTopElement->data.x + 1] != 0
			&& mazeArray[pStack->pTopElement->data.y - 1][pStack->pTopElement->data.x] != 0 && mazeArray[pStack->pTopElement->data.y][pStack->pTopElement->data.x - 1] != 0))
	{
		if ((pStack->currentElementCount == 1 && mazeArray[pStack->pTopElement->data.y + 1][pStack->pTopElement->data.x] != 0 && mazeArray[pStack->pTopElement->data.y][pStack->pTopElement->data.x + 1] != 0
			&& mazeArray[pStack->pTopElement->data.y - 1][pStack->pTopElement->data.x] != 0 && mazeArray[pStack->pTopElement->data.y][pStack->pTopElement->data.x - 1] != 0))
			break;
		check = &(pStack->pTopElement->data); // 생략되는지확인
		if (mazeArray[check->y][check->x + 1] == 0 && check->x + 1 < WIDTH)
		{
			mazeArray[check->y][check->x + 1] = 2;
			curpos.x = check->x + 1;
			curpos.y = check->y;
			curpos.direction = 0;
			node.data = curpos;
			push(pStack, node);
			printf("->");
			write(1, "R ", 2);
			printf(" x:%d y:%d ",pStack->pTopElement->data.x,pStack->pTopElement->data.y);
			// printf("%d",pStack->currentElementCount);
		}
		else if (mazeArray[check->y + 1][check->x] == 0 && check->y + 1 < HEIGHT)
		{
			mazeArray[check->y + 1][check->x] = 2;
			curpos.x = check->x;
			curpos.y = check->y + 1;
			curpos.direction = 3;
			node.data = curpos;
			push(pStack, node);
			printf("V");
			write(1, "D ", 2);
				printf(" x:%d y:%d ",pStack->pTopElement->data.x,pStack->pTopElement->data.y);
		}
		else if (mazeArray[check->y][check->x - 1] == 0 && check->x - 1 >= 0)
		{
			mazeArray[check->y][check->x - 1] = 2;
			curpos.x = check->x - 1;
			curpos.y = check->y;
			curpos.direction = 2;
			node.data = curpos;
			push(pStack, node);
			printf("<-");
			write(1, "L ", 2);
				printf(" x:%d y:%d ",pStack->pTopElement->data.x,pStack->pTopElement->data.y);
		}
		else if (mazeArray[check->y - 1][check->x] == 0 && check->y - 1 >= 0)
		{
			mazeArray[check->y - 1][check->x] = 2;
			curpos.x = check->x;
			curpos.y = check->y - 1;
			curpos.direction = 1;
			node.data = curpos;
			push(pStack, node);
			printf("^");
			write(1, "U ", 2);
			printf(" x:%d y:%d ",pStack->pTopElement->data.x,pStack->pTopElement->data.y);
		}
		// else
		// 	break;
		else if (pStack->currentElementCount > 0)
		{
			mazeArray[check->y][check->x] = 3;
			pop(pStack);
			write(1, "B ", 2);
			printf(" x:%d y:%d ",curpos.x,curpos.y);
		}
		if (pStack->pTopElement->data.x == endPos.x && pStack->pTopElement->data.y == endPos.y)
		{
			printf("success, cnt : %d\n", pStack->currentElementCount);
			printMaze( mazeArray);
			return;
		}
}
	// pop(pStack);
	// write(1, "B ", 2);
	// printf(" x:%d y:%d ",pStack->pTopElement->data.x,pStack->pTopElement->data.y);
	// pop(pStack);
	// write(1, "B ", 2);
	// printf(" x:%d y:%d ",pStack->pTopElement->data.x,pStack->pTopElement->data.y);
	// pop(pStack);
	// write(1, "B ", 2);
	// printf(" x:%d y:%d ",pStack->pTopElement->data.x,pStack->pTopElement->data.y);
	// check = &(pStack->pTopElement->data);
	// mazeArray[check->y + 1][check->x] = 2;
	// 		curpos.x = check->x;
	// 		curpos.y = check->y + 1;
	// 		curpos.direction = 3;
	// 		node.data = curpos;
	// 		push(pStack, node);
	// 		printf("V");
	// 		write(1, "D ", 2);
	// printf("^&^ x:%d y:%d ",pStack->pTopElement->data.x,pStack->pTopElement->data.y);
	
	// printf ("%d\n",pStack->currentElementCount);
	printMaze( mazeArray);
	// if (curpos.x == endPos.x && curpos.y == endPos.y)
	// 	printf("success, cnt : %d\n", pStack->currentElementCount);
	printf("error\n");
}
