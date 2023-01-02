#include "mapdef.h"
#include "mapstack.h"
#include "maputil.h"
#include <stdio.h>
#include <stdlib.h>

void findPath(int mazeArray[HEIGHT][WIDTH],
              MapPosition startPos,
              MapPosition endPos,
              Stack *pStack)
{
    int         cur_dir, next_y, next_x;
    int         visited[HEIGHT][WIDTH] = {{NOT_VISIT}, };
    MapPosition cur_pos;
    MapPosition push_pos;

    startPos.direction = 0;
    pushMapPosition(pStack, startPos);
    while (isEmptyStack(pStack) == FALSE)
    {
        cur_pos = peek(pStack)->data;
        cur_dir = cur_pos.direction;
        free(pop(pStack));
        while (cur_dir < NUM_DIRECTIONS)
        {
            next_x = cur_pos.x + DIRECTION_OFFSETS[cur_dir][0];
            next_y = cur_pos.y + DIRECTION_OFFSETS[cur_dir][1];
            if ((0 <= next_x && next_x < WIDTH)
                && (0 <= next_y && next_y < HEIGHT)
                && (mazeArray[next_y][next_x] != WALL)
                && (visited[next_y][next_x] == NOT_VISIT))
            {
                /* 방문표시 */
                visited[cur_pos.y][cur_pos.x] = VISIT;

                /* 현재 위치 스택에 푸쉬 */
                push_pos.direction = cur_dir + 1;
                push_pos.x = cur_pos.x;
                push_pos.y = cur_pos.y;
                pushMapPosition(pStack, push_pos);

                /* 현재 위치를 다음 위치로 바꾸기 */
                cur_dir = 0;
                cur_pos.x = next_x;
                cur_pos.y = next_y;
                /* 출구 도착 */
                if (next_x == endPos.x && next_y == endPos.y)
                {
                    pushMapPosition(pStack, endPos);
                    return ;
                }
            }
            else
                cur_dir++;
        }
    }
}

int pushMapPosition(Stack *pStack, MapPosition data) 
{
    StackNode   to_push;

    to_push.data = data;
    return (push(pStack, to_push));
}

void showPath(Stack *pStack, int mazeArray[HEIGHT][WIDTH]) 
{
    int         y, x;
    int         pathArray[HEIGHT][WIDTH];
    StackNode   *to_print;

    if (isEmptyStack(pStack))
    {
        write(2, "--- invaild start position or end position ---\n", 48);
        return ;
    }
    for (y = 0; y < HEIGHT; y++)
        for (x = 0; x < WIDTH; x++)
            pathArray[y][x] = mazeArray[y][x];
    to_print = pStack->pTopElement;
    while (to_print != NULL)
    {
        printf("(%d, %d)", to_print->data.x, to_print->data.y);
        pathArray[to_print->data.y][to_print->data.x] = VISIT;
        if (to_print->pLink != NULL)
            printf(" <- ");
        to_print = to_print->pLink;
    }
    printf("\n");
    printMaze(pathArray);
}

void printMaze(int mazeArray[HEIGHT][WIDTH]) 
{
    int     x;
    int     y;
    char    to_print;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (mazeArray[y][x] == WALL)
                to_print = '*';
            else if (mazeArray[y][x] == NOT_VISIT)
                to_print = ' ';
            else
                to_print = '.';
            printf("%c", to_print);
            x++;
        }
        y += printf("\n");
    }
}