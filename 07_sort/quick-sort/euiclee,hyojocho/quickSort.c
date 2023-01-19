#include <stdio.h>
#include <stdlib.h>

void	printArray(int *value, int num)
{
	for (int i = 0; i < num; i++)
		printf("%d ", value[i]);
	printf("\n");
}

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

void	quickSort(int *arr, int start, int end)
{
	if (start >= end)
		return ;
	int pivot = start, i = pivot + 1, j = end;


	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			++i;
		while (j > start && arr[j] >= arr[pivot])
			--j;
		if (i >= j)
			break ;
		swap(&arr[j], &arr[i]);
	}
	swap(&arr[j], &arr[pivot]);
	quickSort(arr, start, j - 1);
	quickSort(arr, j + 1, end);
}

void	init_values(int *values, char **av, int num)
{
	int	i = 0;

	while (i < num)
	{
		values[i] = atoi(av[i + 1]);
		i++;
	}
}

int compare(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;

	return (x - y);
}

int main(int ac, char **av)
{
	int	*values;

	if (!(values = malloc(sizeof(int) * (ac - 1))))
		return (0);
	init_values(values, av, ac - 1);
	printf("Before sort\n");
	printArray(values, ac - 1);

	//qsort(values, ac - 1, sizeof(int), compare);
	quickSort(values, 0, ac - 2);

	printf("After sort\n");
	printArray(values, ac - 1);
	free(values);

	return (0);
}