#include "binsearch.h"

int binarySearchRecursive(int *value, int start, int end, int key)
{
	int	ret = FAIL;
	int	middle = 0;

	if (value == NULL)
		return (FAIL);
	if (start <= end)
	{
		middle = (start + end) / 2;
		if (key == value[middle])
			ret = middle;
		else if (key < value[middle])
			ret = binarySearchRecursive(value, start, middle - 1, key);
		else
			ret = binarySearchRecursive(value, middle + 1, end, key);
	}
	return (ret);
}

int binarySearch(int *value, int start, int end, int key)
{
	int ret = FAIL;
	int middle;

	if (value == NULL)
		return (FAIL);
	while (start <= end)
	{
		middle = (start + end) / 2;
		if (key == value[middle])
		{
			ret = middle;
			break;
		}
		else if (key < value[middle])
			end = middle - 1;			
		else
			start = middle + 1;
	}
	return (ret);
}
