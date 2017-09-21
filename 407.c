#include <stdio.h>

void buble_sort(int arr[], int size);

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


void buble_sort(int arr[], int size)
{
    int i, j, temp, reorder;

    for(i = 1; i < size; i++)
    {
        reorder = 0;
        for(j = size -1; j >= i; j--)
        {
            if(arr[j] < arr[j-1])
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                reorder = 1;
            }
        }
        if(reorder == 0)
            return;
    }
}
