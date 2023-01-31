/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selecionSort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:26:54 by nakoo             #+#    #+#             */
/*   Updated: 2023/01/20 12:30:28 by nakoo            ###   ########.fr       */
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

void	selection_sort(int *arr, int size)
{
	for (int i = 0, j; i < size - 1; i++)
		for(j = i + 1; j < size; j++)
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
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
	print_arr("Before Selection sort", arr, size);
	selection_sort(arr, size);
	print_arr("After Selection sort", arr, size);
	free(arr);
	return (0);
}