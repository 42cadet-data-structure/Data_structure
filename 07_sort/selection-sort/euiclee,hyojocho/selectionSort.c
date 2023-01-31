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

void	selectionSort(int *value, int num)
{
	int	min = 0;

	for (int i = 0; i < num; i++)
	{
		min = i;
		for (int j = i + 1; j < num; j++)
		{
			if (value[j] < value[min])
				min = j;
		}
		swap(&value[min], &value[i]);
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

int	main(int ac, char **av)
{
	int	*values;

	if (!(values = malloc(sizeof(int) * (ac - 1))))
		return (0);
	init_values(values, av, ac - 1);
	printf("Before sort\n");
	printArray(values, ac - 1);

	selectionSort(values, ac - 1);

	printf("After sort\n");
	printArray(values, ac - 1);
	free(values);

	return (0);
}
