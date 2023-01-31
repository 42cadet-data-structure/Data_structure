#include "seqsearch.h"

int sequentialSearchNotSorted(int *value, int size, int key)
{
	int	ret = FAIL;

	if (value == NULL || size < 0)
		return (FAIL);
	for (int i = 0; i < size; i++)
	{
		if (value[i] == key)
		{
			ret = i;
			break ;
		}
	}
	return (ret);
}

int sequentialSearchAsendingSorted(int *value, int size, int key)
{
	int	ret = FAIL;

	if (value == NULL || size < 0)
		return (FAIL);
	int i = 0;
	for (; i < size && value[i] < key; i++)
		;
	if (i < size && value[i] == key)
		ret = i;
	return (ret);
}
void showArray(int *value, int size)
{
	printf("----------------\n");
	for (int i = 0; i < size; i++)
		printf("%d ", value[i]);
	printf("\n----------------\n");
}
