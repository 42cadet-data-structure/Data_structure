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

void shell_insertion_sort(int *array, int start, int end, int interval)
{
    int i = 0;
    int temp = 0, j = 0;
    for (i = start + interval; i <= end; i = i + interval) 
	{
        temp = array[i];
        j = i - interval;
        while ((j >= start) && array[i] < array[j]) 
		{
            array[i] = array[j];
            j = j - interval;
        }
        array[j + interval] = temp;
    }
}

void shell_sort(int *array, int n)
{
	int interval;

	interval = n / 2;
	while (interval >= 1)
	{
		for (int i = 0; i < interval; i++)
			shell_insertion_sort(array, i, n - 1, interval);
		interval /= 2;
	}
}

int main()
{

    int n, array[50];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    shell_sort(array, n);
	print_array(array, n);
    return (0);
}