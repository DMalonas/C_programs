#include <stdio.h>
#include <string.h>

#define SIZE 100000

int main(void)
{
    int i, arr[SIZE], arr2[SIZE];

    for(i = 0; i < SIZE; i++ )
    {
        arr[i] = i + 1;
    }

    memcpy( arr2, arr, SIZE );

    for(i = 0; i < SIZE; i++ )
    {
        printf("arr2 = = %d\n", *(arr2 + i));
    }

    return 0;
}
