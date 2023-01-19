#include <stdio.h>

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int get_left_cnt(int *array, int start, int end, int pivot, int *left)
{
    // array의 시작부터 끝까지 숫자중 pivot보다 작거나 같은 값을 result에 채운 후 작거나 같은 원소의 개수를 반환한다.
    int idx = 0;
    for (int i = start; i <= end; i++)
    {
        if (array[i] <= pivot)
            left[idx++] = array[i];
    }
    return (idx);
}

int get_right_cnt(int *array, int start, int end, int pivot, int *right)
{
    // array의 시작부터 끝까지 숫자중 pivot보다 큰 값을 result에 채운 후 큰 원소의 개수를 반환한다.
    int idx = 0;
    for (int i = start; i <= end; i++)
    {
        if (array[i] > pivot)
            right[idx++] = array[i];
    }
    return (idx);
}

void quick_sort(int *array, int start, int end)
{
    // 종료 조건
    if (start >= end)
        return;

    int pivot = array[start];
    int left[50];
    int right[50];
    int left_count = get_left_cnt(array, start + 1, end, pivot, left);
    int right_count = get_right_cnt(array, start + 1, end, pivot, right);

    /*
        (step 1)
        80 50 70 10 60 20 40 30
        pivot 80

        left 50 ~ 30 까지 80 보다 작거나 같은 수를 left 배열에 넣기
        left -> 50 70 10 60 20 40 30
        left_count = 7

        right 50 ~ 30 까지 80보다 큰 수를 right 배열에 넣기
        right -> x
        right_count = 0

        array 50 70 10 60 20 40 30
        array 50 70 10 60 20 40 30 80

        (step 2)
        50 70 10 60 20 40 30 80
        pivot 50

        left -> 10 20 40 30
        left_count = 4

        right -> 70 60 80
        right_count 3

        array 10 20 40 30
        array 10 20 40 30 50
        array 10 20 40 30 50 70 60 80

        (step 3)
        10 20 40 30 50 70 60 80
        pivot 10

        left -> x
        left_count = 0

        right -> 20 40 30 50 70 60 80
        right_count = 7

        array 10 20 40 30 50 70 60 80

        (step 4)
        10 20 40 30 50 70 60 80
        lc = 0
        return ;
        (step 5)
        10 20 40 30 50 70 60 80
        pivot 20

        left -> x
        left_count = 0

        right -> 40 30 50 70 60 80
        right_count = 6

        10 20 40 30 50 70 60 80
        (step 6)
        return ;
        (step 7)
        10 20 40 30 50 70 60 80
        pivot 40
        left 30 , 1
        right 50 70 60 80 , 4

        10 20 30
        10 20 30 40
        10 20 30 40 50 70 60 80

        ...

        pivot 70
        start = 5 end = 7
        left = 60 , 1
        right = 80 , 1
        10 20 30 40 50 60
        10 20 30 40 50 60 70
        10 20 30 40 50 60 70 80


    */
    for (int i = 0; i < left_count; i++)
        array[start + i] = left[i];

    array[start + left_count] = pivot;

    for (int i = 0; i < right_count; i++)
        array[start + left_count + 1 + i] = right[i];

    quick_sort(array, start, start + left_count - 1); // 피봇을 기준으로 왼쪽은 전부 피봇보다 작기 때문에 피봇 하나 전까지 퀵 정렬
    quick_sort(array, start + left_count + 1, end);   // 피봇을 기준으로 오른쪽은 전부 피봇보다 크기 때문에 피봇 이후에 값부터 퀵 정렬
}

int main()
{
    int n;
    int array[50];
    // 값 입력
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    quick_sort(array, 0, n - 1);
    print_array(array, n);
    return (0);
}