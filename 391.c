#include <stdio.h>
#define SIZE 5

int linear_search(double arr[], int size, double num, int *times);




int main()
{
    double arr[SIZE], num;
    int times, i, pos = -1;

    times = 0;


    for(i = 0; i < SIZE; i++)
    {

        while(scanf("%lf", arr + i) != 1)
        {
            printf("\n");
            while(getchar() != '\n');
        }
    }


    printf("Enter number: ");
    while(scanf("%lf", &num) != 1)
    {
        printf("\n");
        while(getchar() != '\n');
    }


    pos = linear_search(arr, sizeof(arr)/sizeof(double), num, &times);

    if((-1) == pos)
    {
        printf("Number not found");
    }
    else
    {
        printf("Number %.2lf appears %d times (1st pos is %d)", num, times, pos);
    }
    return 0;
}




int linear_search(double arr[], int size, double num, int *times)
{
    int pos, *t, i, j;

    pos = -1;
    t = times;
    *t = 0;

    for(i = 0; i < size; i++)
    {
        if(arr[i] == num)
        {
            if((*t) == 0)
            {
                pos = i;
            }
            (*t)++;
        }
    }
    return pos;
}
