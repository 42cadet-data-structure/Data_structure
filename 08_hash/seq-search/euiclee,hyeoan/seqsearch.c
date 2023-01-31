#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqsearch.h"

int sequentialSearchNotSorted(int *value, int size, int key)
{
    for (int index = 0; index < size; index++)
        if (value[index] == key)
            return index;
    return FAIL;
}

int sequentialSearchAsendingSorted(int *value, int size, int key)
{
    for (int index = 0; index < size; index++)
    {
        if (value[index] == key)
            return index;
        if (value[index] > key)
            break;
    }

    return FAIL;
}

void showArray(int *value, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", value[i]);
    printf("\n");
}
