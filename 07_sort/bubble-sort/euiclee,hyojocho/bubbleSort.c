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

void	bubbleSort(int *value, int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num - 1; j++)
		{
			if (value[j] > value[j + 1])
				swap(&value[j], &value[j + 1]);
		}
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

	bubbleSort(values, ac - 1);

	printf("After sort\n");
	printArray(values, ac - 1);
	free(values);

	return (0);
}
