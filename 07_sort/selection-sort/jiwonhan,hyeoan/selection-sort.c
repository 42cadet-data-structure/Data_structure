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

void selection_sort(int *array, int n)
{
	for (int i = 0, min = 0; i < n; i++)
	{
		min = i;
		for (int j = i; j < n; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		swap(&array[min], &array[i]);
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
	selection_sort(array, n);

	return (0);
}
