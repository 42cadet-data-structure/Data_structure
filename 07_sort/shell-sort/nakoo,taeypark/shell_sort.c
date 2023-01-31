#include <stdio.h>
#include <stdlib.h>

void	shell_insertion_sort(int *arr, int start, int gap, int size)
{
	int	i, j;
	int	comp;

	for (i = start + gap; i < size; i += gap)
	{
		comp = arr[i];
		for (j = i - gap; j >= start && comp < arr[j]; j -= gap)
		{
			arr[j + gap] = arr[j];
			arr[j] = comp;
		}
	}
}

void	shell_sort(int *arr, int size)
{
	int	i;
	int	gap = size / 2;

	while (gap >= 1)
	{
		for (i = 0; i < gap; i++)
			shell_insertion_sort(arr, i, gap, size);
		gap /= 2;
	}
}

void	print_arr(char *msg, int *arr, int size)
{
	fprintf(stdout, "%s", msg);
	fprintf(stdout, "\n--------------\n");
	for (int i = 0; i < size; i++)
		fprintf(stdout, "%d ", arr[i]);
	fprintf(stdout, "\n--------------\n");
}

int	main(void)
{
	int	i;
	int	*arr, size;

	fprintf(stdout, "size : ");
	fscanf(stdin, "%d", &size);
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (fprintf(stderr, "Malloc Error\n"));
	fprintf(stdout, "arr : ");
	for (i = 0; i < size; i++)
		fscanf(stdin, "%d", &arr[i]);
	print_arr("Before Shell sort", arr, size);
	shell_sort(arr, size);
	print_arr("After Shell sort", arr, size);
	free(arr);
	return (0);
}

