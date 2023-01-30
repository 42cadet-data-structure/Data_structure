#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqindexsearch.h"

int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key)
{
    int ret = FAIL;
    int i, start, end;

    if (key < value[0] && key > value[size - 1])
        return (ret);
    for (i=0;i<indexSize && key >= index[i].key;i++)
        ;
    if (i >= indexSize)
        ret = sequentialRangeSearchAsendingSorted(value, index[i - 1].position, \
        size - 1, key);
    else
        ret = sequentialRangeSearchAsendingSorted(value, index[i - 1].position, \
        index[i].position - 1, key);
    return (ret);
}

int sequentialRangeSearchAsendingSorted(int value[], int start, int end, int key)
{
    int ret = FAIL;

    for(int i = 0;i<=end && value[i] <= key;i++)
        if (value[i] == key)
            return (i);
    return (ret);
}

IndexTable *createIndexTable(int value[], int size, int indexSize)
{
    IndexTable *ret;
    int ratio;

    ret = malloc(sizeof(IndexTable) * indexSize);
    if (!ret)
        return (NULL);
    ratio = size / indexSize;
    for (int i=0;i<size;i++)
    {
        ret[i].position = i * ratio;
        ret[i].key = value[i * ratio];
    }
    return (ret);
}

void showIndexTable(IndexTable *pIndexTable, int indexSize)
{
    for (int i=0;i<indexSize;i++)
        printf("[%d] %d\n", pIndexTable[i].position, pIndexTable[i].key);
}