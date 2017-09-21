#include <stdio.h>

void add_sort(int arr[], int size, int num);

int main(void)
{
    int arr[10], i, num;

    for(i = 0; i < sizeof(arr)/ sizeof(int) - 1; i++)
    {
        arr[i] = 10 - i;
    }

    printf("arr[%d] == %d\n\n", i, arr[i]);
    printf("Enter number: ");
    while(scanf("%d", &num) != 1)
    {
        printf("\n");
        while(getchar() != '\n');
    }


    add_sort(arr, sizeof(arr)/sizeof(int), num);

    for(i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("arr[%d] = %d\n",i, arr[i]);
    }

    return 0;
}



void add_sort(int arr[], int size, int num)
{
    int i, j, temp;

    arr[size-1] = num;

    for(i = 0; i < size; i++)
    {
        for(j = i+1; j < size; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
