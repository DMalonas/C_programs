#include <stdio.h>

int binary_search(int arr[], int size, int num);


int main()
{
    int arr[] = {1, 2, 3, 3, 3, 6, 7, 8, 9, 10}, num;

    printf("Enter number (range [1, 10]): ");
    while(1)
    {
        while(scanf("%d", &num) != 1)
        {
            printf("\n");
            while(getchar() != '\n');
        }

        if((num < 0) || (num > 10))
        {
            printf("\nOut of range\n");
            continue;
        }
        break;
    }

    printf("Number %d appears in position %d\n", num, binary_search(arr, sizeof(arr) / sizeof(int), num));
    return 0;
}


int binary_search(int arr[], int size, int num)
{
    int start, mid, end;

    start = arr[0];
    end = arr[size-1];
    mid = (start + end) / 2;

    while(start <= end)
    {
        if(arr[mid] == num)
        {
            return mid;
        }
        if(arr[mid] < num)
        {
            start = mid + 1;
            mid = (start + end) / 2;
        }
        if(arr[mid] > num)
        {
            end = mid -1;
            mid = (start + end) / 2;
        }
    }
    return -1;
}
