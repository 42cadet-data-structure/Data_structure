#include <stdio.h>
#include <stdlib.h>

void	merge_sort(int *arr, int start, int end, int *merge_arr)
{
	int	L, R, cur_idx;
	int	mid = (start + end) / 2;

	if (start == end)
		return ;
	merge_sort(arr, 0, mid, merge_arr);
	merge_sort(arr, mid + 1, end, merge_arr);
	L = start, R = mid + 1, cur_idx = start;
	while (L <= mid && R <= end)
	{
		if (arr[L] > arr[R])
			merge_arr[cur_idx++] = arr[R++];
		else
			merge_arr[cur_idx++] = arr[L++];
	}
	if (L > mid)
		while (R <= end)
			merge_arr[cur_idx++] = arr[R++];
	else
		while (L <= mid)
			merge_arr[cur_idx++] = arr[L++];
	for (cur_idx = start; cur_idx <= end; cur_idx++)
		arr[cur_idx] = merge_arr[cur_idx];
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
	int	*merge_arr;

	fprintf(stdout, "size : ");
	fscanf(stdin, "%d", &size);
	arr = (int *)malloc(sizeof(int) * size);
	merge_arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL || merge_arr == NULL)
		return (free(arr), free(merge_arr), fprintf(stderr, "Malloc Error\n"));
	fprintf(stdout, "arr : ");
	for (i = 0; i < size; i++)
		fscanf(stdin, "%d", &arr[i]);
	print_arr("Before Merge sort", arr, size);
	merge_sort(arr, 0, size - 1, merge_arr);
	print_arr("After Merge sort", arr, size);
	free(arr);
	free(merge_arr);
	return (0);
}

