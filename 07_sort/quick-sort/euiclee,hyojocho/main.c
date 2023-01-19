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

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void	quickSort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
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

	//qsort(values, ac - 1, sizeof(int), compare);
	quickSort(values, 0, ac - 2);

	printf("After sort\n");
	printArray(values, ac - 1);
	free(values);

	return (0);
}