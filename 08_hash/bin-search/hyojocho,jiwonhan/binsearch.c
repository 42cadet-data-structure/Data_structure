#include "binsearch.h"

int binarySearchRecursive(int *value, int start, int end, int key)
{
	int mid;
	int ret = FAIL;

	if (start <= end)
	{
		mid = (start + end) / 2;
		if (key < value[mid])
			ret = binarySearchRecursive(value, start, mid - 1, key);
		else if (key == value[mid])
			return (mid);
		else if (key > value[mid])
			ret = binarySearchRecursive(value, mid + 1, end, key);
	}
	return (ret);
}

int binarySearch(int *value, int start, int end, int key)
{
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (key < value[mid])
			end = mid - 1;
		else if (key == value[mid])
			return (mid);
		else if (key > value[mid])
			start = mid + 1;
	}
	return (FAIL);
}