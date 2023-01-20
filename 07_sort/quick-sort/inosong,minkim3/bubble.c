#include <stdio.h>

void printArray(int values[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    };
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int values[], int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (values[j] > values[j + 1])
				swap (&values[j], &values[j + 1]);
			j++;
		}
	    printf("Step = %d, ", count - i);
        printArray(values, count);
		i++;
	}
}

int main() {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    printArray(values, 8);
    bubbleSort(values, 8);
    printArray(values, 8);
    return 0;
}