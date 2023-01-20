/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:39:48 by nakoo             #+#    #+#             */
/*   Updated: 2023/01/20 13:00:32 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_arr(char *msg, int *arr, int size)
{
	fprintf(stdout, "%s", msg);
	fprintf(stdout, "\n--------------\n");
	for (int i = 0; i < size; i++)
		fprintf(stdout, "%d ", arr[i]);
	fprintf(stdout, "\n--------------\n");
}

void	swap(int * restrict a, int * restrict b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot, l, r;

	if (start >= end)
		return ;
	pivot = start;
	l = pivot + 1;
	r = end;
	while (l <= r)
	{
		while (l <= end && arr[l] <= arr[pivot])
			l++;
		while (r > start && arr[r] >= arr[pivot])
			r--;
		if (l > r)
			swap(&arr[r], &arr[pivot]);
		else
			swap(&arr[l], &arr[r]);
	}
	quick_sort(arr, start, r - 1);
	quick_sort(arr, l + 1, end);
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
	print_arr("Before Quick sort", arr, size);
	quick_sort(arr, 0, size - 1);
	print_arr("After Quick sort", arr, size);
	free(arr);
	return (0);
}