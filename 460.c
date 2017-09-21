#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define S 10

int *mem_mod(int *old_mem, int old_mem_size, int next_mem_size);

int main(void)
{
    int *arr;
    int i;

    arr = (int *)malloc(sizeof(int) * S);
    if( NULL == arr )
    {
        exit(1);
    }

    srand((unsigned int)time(NULL));

    for(i = 0; i < S; i++)
    {
        *(arr + i) = rand() % 6;
    }

    arr = mem_mod(arr, S, 2 * S);

    for(i = S; i < (2 * S); i++)
    {
        *(arr + i) = 11;
    }

    for(i = 0; i < (2 * S); i++)
    {
        printf("arr[%d] == %d\n", i, *(arr + i));
    }

    free(arr);

    return 0;
}


int *mem_mod(int *old_mem, int old_mem_size, int next_mem_size)
{
    int *next_mem;
    int i;


    next_mem = (int *)malloc(sizeof(int) * next_mem_size);
    if( NULL == next_mem)
    {
        exit(1);
    }

    for(i = 0; i < old_mem_size; i++)
    {
        *(next_mem + i) = *(old_mem + i);
    }

    free(old_mem);

    return next_mem;
}
