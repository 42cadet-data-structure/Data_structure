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

int main()
{
    int n;
    int array[50];
    // 값 입력
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    // 정렬
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
