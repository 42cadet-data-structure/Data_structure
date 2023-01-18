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

int partitionQuickSort(int *values, int start, int end)

void quickSort(int values[], int start, int end)

int main() {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    printArray(values);
    quickSort(values, 0, 7);
    printArray(values);

    return 0;
}