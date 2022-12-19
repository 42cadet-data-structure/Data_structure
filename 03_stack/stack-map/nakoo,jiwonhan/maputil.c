#include <stdio.h>
#include <stdlib.h>

#include "mapdef.h"
#include "mapstack.h"
#include "maputil.h"

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	char pos_char[] = {' ', '*', '.'};

	for (int i=0;i<HEIGHT;i++)
	{
		for (int j = 0;j<WIDTH;j++)
			printf("%c", pos_char[mazeArray[i][j]]);
		printf("\n");
	}
}

int pushMapPosition(Stack *pStack, MapPosition data)
{
	StackNode newNode;
	newNode.data = data;
	newNode.data.direction = VISIT;

	return (push(pStack, newNode));
}

void showPath(Stack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode *tmp;
	int	visitedMaze[HEIGHT][WIDTH];

	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
			visitedMaze[i][j] = mazeArray[i][j];
	tmp = pStack->pTopElement;
	while (tmp)
	{
		if (tmp == pStack->pTopElement)
			printf("[%d %d] ", tmp->data.y, tmp->data.x);
		else
			printf("<- [%d %d] ",tmp->data.y, tmp->data.x);
		visitedMaze[tmp->data.y][tmp->data.x] = VISIT;
		tmp = tmp->pLink;
	}
	printf("\n");
	printMaze(visitedMaze);
}

static void	init_vals(vals *vals, MapPosition startPos, MapPosition endPos)
{
	vals->valid_path = FALSE;
	vals->startPos = startPos;
	vals->endPos = endPos;
	for(int i=0;i<HEIGHT;i++)
		for(int j=0;j<WIDTH;j++)
			vals->visited[i][j] = 0;
}

static int	dfs(int mazeArray[HEIGHT][WIDTH], vals *vals, Stack *pStack, MapPosition nowPos)
{
	MapPosition	nextPos;
	
	vals->visited[nowPos.y][nowPos.x] = VISITED;
	if (vals->valid_path == FALSE)
	{
		if (!pushMapPosition(pStack, nowPos))
			exit(0);
	}
	if (nowPos.y == vals->endPos.y && nowPos.x == vals->endPos.x)
	{
		vals->valid_path = TRUE;
		return (TRUE);
	}
	for (int i = 0; i < 4; i++)
	{
		nextPos.x = nowPos.x + DIRECTION_OFFSETS[i][1];
		nextPos.y = nowPos.y + DIRECTION_OFFSETS[i][0];
		if (nextPos.x < 0 || nextPos.x > WIDTH || nextPos.y < 0 || nextPos.y > HEIGHT)
			continue;
		if (vals->visited[nextPos.y][nextPos.x] == NOT_VISITED && mazeArray[nextPos.y][nextPos.x] != WALL)
			dfs(mazeArray, vals, pStack, nextPos);
	}
	return (FALSE);
}

void findPath(int mazeArray[HEIGHT][WIDTH],
              MapPosition startPos,
              MapPosition endPos, 
			  Stack *pStack)
{
	vals	vals;
	init_vals(&vals ,startPos, endPos);
	dfs(mazeArray, &vals, pStack, startPos);
	if (vals.valid_path == FALSE)
		clearStack(pStack);
}
