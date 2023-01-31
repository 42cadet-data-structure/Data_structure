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

void insertionSort(int *values, int count)
{
	int i = 0, j = 0, temp = 0;

	for (i = 1; i < count; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (values[j] > values[i])
			{
				swap(&values[j], &values[i]);
				i--;
			}
		}
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

	insertionSort(values, ac - 1);

	printf("After sort\n");
	printArray(values, ac - 1);

	return (0);
}