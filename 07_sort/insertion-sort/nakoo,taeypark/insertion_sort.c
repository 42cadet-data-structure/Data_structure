#include <stdio.h>
#include <stdlib.h>

void	insertion_sort(int *arr, int size)
{
	int	i,j;
	int	comp;

	for (i = 1; i < size; i++)
	{
		comp = arr[i];
		for (j = i - 1; j >= 0 && comp < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = comp;
		}
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
	print_arr("Before insertion sort", arr, size);
	insertion_sort(arr, size);
	print_arr("After insertion sort", arr, size);
	free(arr);
	return (0);
}
