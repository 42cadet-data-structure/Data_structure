#include <stdio.h>

void printArray(int values[]) {
    for (int i = 0; i < sizeof(values); i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

int	return_key(int values[], int start, int end)
{
	int	pivot = start;
	while (start < end )
	{
		//while (start < end && values[end] > values[pivot])
		while (start < end && values[end] > values[pivot])
			end--;
		while (start < end && values[start] <= values[pivot])
			start++;
		swap(&values[start], &values[end]);
		printArray(values);
	}
	swap(&values[pivot], &values[end]);

	return (start);
}

void quickSort(int values[], int start, int end)
{
	int key;
	if (start >= end)
		return ;
	key = return_key(values, start, end);
	printArray(values);
	quickSort(values, start, key - 1);
	quickSort(values, key + 1, end);
	
}

int main() {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    printArray(values);
    quickSort(values, 0, 7);
    printArray(values);

    return 0;
}