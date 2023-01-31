#include <stdio.h>

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
// 정렬한 왼쪽 절반 오른쪽 절반 배열 합치는 함수
void merging(int *array, int left_s, int left_e, int right_s, int right_e)
{
    int left_min;
    int right_min;
    int merging_array[50];
    int idx = 0;

    left_min = left_s;
    right_min = right_s;
    // 외쪽 배열과 오른쪽 배열을 비교하여 최솟값을 merging_array 배열에 넣는다.
    while (left_min <= left_e && right_min <= right_e)
    {
        if (array[left_min] <= array[right_min])
            merging_array[idx++] = array[left_min++];
        else if (array[right_min] <= array[left_min])
            merging_array[idx++] = array[right_min++];
    }
    // 왼쪽 배열과 오른쪽 배열중 한쪽의 배열을 merging_array에 다 넣어서 끝난경우
    // 배열의 남은 값들을 merging_array에 넣어줘야함
    if (left_min > left_e)
    {
        for (int i = right_min; i <= right_e; i++)
            merging_array[idx++] = array[i];
    }
    else if (right_min > right_e)
    {
        for (int i = left_min; i <= left_e; i++)
            merging_array[idx++] = array[i];
    }
    // array에 정렬이 완료된 merging_array를 복사
    for (int i = left_s; i <= right_e; i++)
        array[i] = merging_array[i - left_s];
}
// array를 start번째 값부터 end번째 값까지 합볍정렬하는 함수
void merge_sort(int *array, int start, int end)
{
    // 기저조건 : 원소가 하나만 있을때
    if (start >= end)
        return;
    else
    {
        int mid = (start + end) / 2;
        // 왼쪽 반 정렬
        merge_sort(array, start, mid);
        // 오른쪽 반 정렬
        merge_sort(array, mid + 1, end);
        // 정렬된 왼쪽 오른쪽 배열을 하나로 합치기
        merging(array, start, mid, mid + 1, end);
    }
}

int main()
{
    int n;
    int array[50];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    merge_sort(array, 0, n - 1);
    print_array(array, n);
    return (0);
}