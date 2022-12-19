//
// Created by sanguk on 08/08/2017.
//

#ifndef STACK_MAP_MAPUTIL_H
#define STACK_MAP_MAPUTIL_H

typedef struct vals {
    MapPosition startPos;
    MapPosition endPos;
    int	visited[HEIGHT][WIDTH];
    int valid_path;
}   vals;

enum check{
    NOT_VISITED = 0,
    VISITED
};

void findPath(int mazeArray[HEIGHT][WIDTH],
              MapPosition startPos,
              MapPosition endPos,
              Stack *pStack);

int pushMapPosition(Stack *pStack, MapPosition data);

void showPath(Stack *pStack, int mazeArray[HEIGHT][WIDTH]);

void printMaze(int mazeArray[HEIGHT][WIDTH]);


#endif //STACK_MAP_MAPUTIL_H
