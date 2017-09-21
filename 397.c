#include <stdio.h>

#define SIZE 10


void sel_sort(double arr[], int size);



int main()
{

    double arr[SIZE];
    int i = 0;

    while(i < SIZE)
    {
        printf("arr[%d] : ", i);
        while(scanf("%lf", arr + i) != 1)
        {
            printf("\n");
            while(getchar() != '\n');
        }
        i++;
    }

    sel_sort(arr, SIZE);

    for(i = 0; i < SIZE; i++)
    {
        printf("arr[%d] = %.2lf\n", i, arr[i]);
    }
    while(1);
    return 0;
}


void sel_sort(double arr[], int size)
{
    double temp;
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

}
