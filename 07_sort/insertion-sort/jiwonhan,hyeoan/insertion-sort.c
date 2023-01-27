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

void insertion_sort(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (array[j - 1] > array[j])
                swap(&array[j - 1], &array[j]);
            else
                break;
        }
        print_array(array, n);
    }
}

int main()
{

    int n, array[50];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    insertion_sort(array, n);

    return (0);
}