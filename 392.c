#include <stdio.h>

#define SIZE 10

int number_of_occurences(int arr[]);


int main(void)
{
    int i, arr[SIZE];

    for(i = 0; i < (sizeof(arr)/sizeof(int)); i++)
    {
        printf("arr[%d] : ", i);
        while(scanf("%d", arr + i) != 1)
        {
            printf("\n");
            while(getchar() != '\n');
        }
    }

    printf("The maximum number of occurrences is %d\n", number_of_occurences(arr));

    return 0;
}







int number_of_occurences(int arr[])
{
    int i, j;
    int frequency_of_occurence[SIZE] = {0};

    for(i = 0; i < SIZE; i++)
    {
        for(j = (i + 1); j < SIZE; j++)
        {
            if(arr[i] == arr[j])
            {
                frequency_of_occurence[i]++;
            }
        }
    }

    j = frequency_of_occurence[0];
    for(i = 1; i < SIZE; i++)
    {
        if(frequency_of_occurence[i] > j)
        {
            j = frequency_of_occurence[i];
        }
    }

    return (j + 1);
}
