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

int partitionQuickSort(int *values, int start, int end) {
    int pivot = 0, left = 0, right = 0;
    left = start;
    right = end;
    pivot = end;
    while(left < right){
        while(left < right && values[left] < values[pivot]){
            left++;
        }
        while(left < right && values[right] >= values[pivot]){
            right--;
        }
        if (left < right){
            swap(&values[left], &values[right]);
        }
    }
    swap(&values[pivot], &values[right]);
    return right;
}

void quickSort(int *values, int start, int end) {
    int pivot = 0;
    if (start < end) {
        pivot = partitionQuickSort(values, start, end);
        quickSort(values, start, pivot - 1);
        quickSort(values, pivot + 1, end);
    }

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

	qsort(values, ac - 1, sizeof(int), compare);
	//quickSort(values, 0, 7);

	printf("After sort\n");
	printArray(values, ac - 1);
	free(values);

	return (0);
}