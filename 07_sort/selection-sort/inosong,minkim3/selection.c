#include <stdio.h>

void printArray(int value[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", value[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int value[], int count)\
{
	int i;
	int j;
	int min;

	i = 0;
	while (i < count)
	{
		min = i;
		j = i + 1;
		while (j < count)
		{
			if (value[min] > value[j])
				min = j;
			j++;
		}
		swap(&value[min], &value[i]);
	    printf("Step = %d, ", i);
        printArray(value, count);
		i++;
	}
}

int main() {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};

    printf("Before sort\n");
    printArray(values, 8);

    selectionSort(values, 8);

    printf("After sort\n");
    printArray(values, 8);

    return 0;
}