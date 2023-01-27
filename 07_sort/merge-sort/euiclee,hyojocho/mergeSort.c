#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int arr[INT_MAX];
int result[INT_MAX];

void	printArray(int *value, int num)
{
	for (int i = 0; i < num; i++)
		printf("%d ", value[i]);
	printf("\n");
}

void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (arr[i] > arr[j])
			result[k++] = arr[j++];
		// 양쪽 리스트에서 최솟값을 비교했는데 오른쪽 리스트가 더 컸을 경우
		// 그대로 왼쪽 리스트의 최솟값이 결과배열에 내려오면 됩니다.
		else
			result[k++] = arr[i++];
	}
	// 오른쪽 리스트에 아직 결과배열에 들어가지 못한 값이 있으면 그대로 넣어줍니다.
	if (i > mid)
		while (j <= right)
			result[k++] = arr[j++];
	else
		while (i <= mid)
			result[k++] = arr[i++];
	// 다시 원래 배열에 옮겨담는 작업
	for (int a = left; a <= right; a++)
		arr[a] = result[a];
}
void	mergeSort(int *values, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		merge(left, mid);
		merge(mid + 1, right);
		merge(left, right);
	}
}

void	init_values(int *values, char **av, int num)
{
	int	i = -1;

	while (++i < num)
		values[i] = atoi(av[i + 1]);
}

int main(int ac, char **av)
{
	int	*values;

	if (!(values = malloc(sizeof(int) * (ac - 1))))
		return (0);
	init_values(values, av, ac - 1);
	printf("Before sort\n");
	printArray(values, ac - 1);

	mergeSort(values, 0, ac - 1);

	printf("After sort\n");
	printArray(values, ac - 1);

	return (0);
}