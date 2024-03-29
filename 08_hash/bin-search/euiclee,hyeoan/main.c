#include <stdio.h>
#include <stdlib.h>
#include "binsearch.h"

void showArray(int value[], int size)
{
    int i = 0;

    printf("position,key\n");
    printf("------------\n");
    for (i = 0; i < size; i++)
        printf("[%d] : %d\n", i, value[i]);
    printf("------------\n");
}

int main()
{
    int key = 0;
    int index = 0;
    int ascSortedArray[] = {10, 20, 50, 60, 70, 80};
    int arraySize = 6;

    showArray(ascSortedArray, arraySize);

    key = 70;
    index = binarySearchRecursive(ascSortedArray, 0, arraySize, key);
    printf("key = %d, index = %d\n", key, index);

    key = 60;
    index = binarySearchRecursive(ascSortedArray, 0, arraySize, key);
    printf("key = %d, index = %d\n", key, index);

    key = 20;
    index = binarySearch(ascSortedArray, 0, arraySize, key);
    printf("key = %d, index = %d\n", key, index);

    key = 70;
    index = binarySearch(ascSortedArray, 0, arraySize, key);
    printf("key = %d, index = %d\n", key, index);

    return 0;

}