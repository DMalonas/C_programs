#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define S 5



double *find_diff(double *a1, double *a2, size_t size, int *times);



int main(void)
{
    double *a3, *i;
    double a1[S], a2[S];
    int elements;

    elements = 0;
    i = a1;

    srand((unsigned int) time (NULL));

    while((i - a1) < S)
    {
        *i = rand() % 6;
        printf("%.1f ", *i);
        i++;
    }
    printf("\n");

    i = a2;

    while((i - a2) < S)
    {
        *i = rand() % 11;
        printf("%.1f ", *i);
        i++;
    }
    printf("\n");

    a3 = find_diff(a1, a2, S, &elements);

    if( 0 == elements )
    {
        printf("No different elements");

    }
    else
    {
        printf("Number of elements that exist in a1 but not in a2 is %d\n", elements);
        i = a3;

        while((i - a3) < elements )
        {
            printf("%.1f ", *i);
            i++;
        }
    }

    free(a3);
    return 0;
}





double *find_diff(double *a1, double *a2, size_t size, int *times)
{
    double *new_mem;
    int i, j, flag;

    new_mem = (double*) malloc(size * sizeof(double));
    if(new_mem == NULL)
    {
        exit(1);
    }
    for(i = 0; i < size; i++)
    {
        flag = 0;
        for(j = 0; j < size; j++)
        {
            if(a1[i] == a2[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            new_mem[*times] = a1[i];
            (*times)++;
        }
    }
    return new_mem;
}
