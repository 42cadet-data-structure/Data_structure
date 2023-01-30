#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqsearch.h"

int sequentialSearchNotSorted(int *value, int size, int key)
{
	for (int i=0;i<size;i++)
		if (value[i] == key)
			return (i);
	return (FAIL);
}

int sequentialSearchAsendingSorted(int *value, int size, int key)
{
	for (int i=0;i<size && value[i] <= key;i++)
		if (value[i] == key)
			return (i);
	return (FAIL);
}

void showArray(int *value, int size)
{
	for (int i = 0;i < size; i++)
		printf("%d ", value[i]);
	printf("\n");
}