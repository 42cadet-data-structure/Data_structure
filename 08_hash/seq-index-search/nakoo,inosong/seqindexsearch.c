#include "seqindexsearch.h"

int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key)
{
	int	gap = size / indexSize;
	int i;

	if (value == NULL || size < 0 || index == NULL || indexSize < 0)
		return (FAIL);
	for (i = 0; i < indexSize; i++)
	{
		if (key == index[i].key)
			return (i);
		else if (key < index[i].key)
			return (sequentialRangeSearchAsendingSorted(value, (i - 1) * gap, i * gap, key));
	}
	return (FAIL);
}

int sequentialRangeSearchAsendingSorted(int value[], int start, int end, int key)
{
	if (start < 0)
		return (FAIL);
	for (int i = start; i < end; i++)
	{
		if (value[i] == key)
			return (i);
	}
	return (FAIL);
}

IndexTable *createIndexTable(int value[], int size, int indexSize)
{
	int i = size / indexSize;
	IndexTable *indextable;

	indextable = (IndexTable *)malloc(sizeof(IndexTable) * indexSize);
	if (indextable == NULL)
		return (NULL);
	for (int j = 0; j < indexSize; j++)
	{
		indextable[j].key = value[j * i]; 
		indextable[j].position = j * i;
	}
	return (indextable);
}

void showIndexTable(IndexTable *pIndexTable, int indexSize)
{
	for (int i = 0; i < indexSize; i++)
        printf("[%d] : %d\n", pIndexTable[i].position, pIndexTable[i].key);
}
