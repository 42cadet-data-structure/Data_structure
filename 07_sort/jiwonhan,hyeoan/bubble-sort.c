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
