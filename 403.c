#include <stdio.h>

void insertion_sort(int arr[], int size);

int main(void)
{
    int arr[] = {1, 10, 8, -34, 95, 8, -3, 92, 5}, i;


    insertion_sort(arr, sizeof(arr)/sizeof(int));

    for(i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}


void insertion_sort(int arr[], int size)
{
    int i, j, temp;

    for(i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i;
        while((j > 0) && (temp < arr[j - 1]))
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}
