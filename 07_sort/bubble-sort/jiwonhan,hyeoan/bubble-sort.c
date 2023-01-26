#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void bubble_sort(int *array, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n - i - 1); j++)
		{
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		}
		print_array(array, n);
	}
}

int main()
{
    int n;
    int array[50];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    bubble_sort(array, n);

	return (0);
}
