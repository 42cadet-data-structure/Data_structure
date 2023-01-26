#include <stdio.h>


int main()
{
    int n;
    int array[50];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    insertion_sort(array, n);
    return (0);
}