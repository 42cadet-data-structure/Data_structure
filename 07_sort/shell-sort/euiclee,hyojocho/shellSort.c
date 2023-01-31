#include <stdlib.h>
#include <stdio.h>

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

void shellInsertionSort(int *values, int count, int interval) {
	int i, j;

	for (i = interval; i < count; i += interval)
	{
		for (j = i; j > 0; j -= interval)
		{
			if (values[j - interval] > values[j])
				swap(&values[j - interval], &values[j]);
			else
				break;
		}
	}
}

void shellSort(int *values, int count) {
	int i = 0, interval = 0;

	for (interval = count / 2; interval >= 1; interval /= 2)
		for (i = 0; i < interval; i++)
			shellInsertionSort(values, count - i, interval);
}

void	init_values(int *values, char **av, int num)
{
	int	i = -1;

	while (++i < num)
		values[i] = atoi(av[i + 1]);
}

int	main(int ac, char **av)
{
	int	*values;

	if (!(values = malloc(sizeof(int) * (ac - 1))))
		return (0);
	init_values(values, av, ac - 1);
	printf("Before sort\n");
	printArray(values, ac - 1);

	shellSort(values, ac - 1);

	printf("After sort\n");
	printArray(values, ac - 1);

	return (0);
}