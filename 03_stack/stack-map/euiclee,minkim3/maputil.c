#include "mapdef.h"
#include "mapstack.h"
#include "maputil.h"

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, Stack *pStack)
{
    StackNode	*node = NULL;
    int			isEmpty = FALSE;
	int			isFound = FALSE;
	int			i = 0;
    int			markArray[HEIGHT][WIDTH] = {0,};
    MapPosition	newPosition = startPos;
	int			x;
	int			y;
	int			direction;

    newPosition.direction = 0;
    pushMapPosition(pStack, newPosition);
    while (isEmpty == FALSE && isFound == FALSE)
	{
        node = pop(pStack);
        if (node == NULL)
			break;
        x = node->data.x;
        y = node->data.y;
        direction = node->data.direction;
        while (isFound == FALSE && direction < NUM_DIRECTIONS)
		{
            int newX = x + DIRECTION_OFFSETS[direction][0];
            int newY = y + DIRECTION_OFFSETS[direction][1];
            if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT &&
				markArray[newY][newX] == NOT_VISIT && mazeArray[newY][newX] == NOT_VISIT)
			{
				newPosition.x = x;
				newPosition.y = y;
				newPosition.direction = direction + 1;
				pushMapPosition(pStack, newPosition);
				markArray[y][x] = VISIT;

				x = newX;
				y = newY;
				direction = 0;

				if (newX  == endPos.x && newY == endPos.y)
				{
					isFound = TRUE;
					newPosition.x = newX;
					newPosition.y = newY;
					newPosition.direction = 0;
					pushMapPosition(pStack, newPosition);
					markArray[newY][newX] = VISIT;
				}
            }
			else
                direction++;
        }
        free(node);
        isEmpty = isStackEmpty(pStack);
    }
}

int	pushMapPosition(Stack *pStack, MapPosition data)
{
    StackNode node = {0,};

    node.data = data;
    return (push(pStack, node));
}

void showPath(Stack *pStack, int mazeArray[HEIGHT][WIDTH])
{
    StackNode	*node = NULL;
    int			resultArray[HEIGHT][WIDTH] = {0,};
    int			isEmpty = FALSE;
	int			y = 0;
	int			x;

    while (y < HEIGHT)
	{
		x = 0;
        while (x < WIDTH) 
		{
            resultArray[y][x] = mazeArray[y][x];
			x++;
		}
		y++;
	}
    while(isEmpty == FALSE)
	{
        node = pop(pStack);
        if (node != NULL) {
            x = node->data.x;
            y = node->data.y;
            resultArray[y][x] = VISIT;
			printf(" - ");
            printf("(%d,%d)", x, y);
            free(node);
        }
        isEmpty = isStackEmpty(pStack);
    }
    printf("\n");
    printMaze(resultArray);
}

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
    int	y = 0;
	int	x;

    while (y < HEIGHT)
	{
		x = 0;
        while (x < WIDTH)
		{
            if (mazeArray[y][x] == WALL)
                printf("*");
            else if (mazeArray[y][x] == VISIT)
                printf(".");
            else
                printf(" ");
			x++;
        }
        printf("\n");
		y++;
    }
}