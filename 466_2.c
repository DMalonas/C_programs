#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define S 10

double* find_diff(double *a1, double *a2, size_t size, int *times);

int main(void)
{
    double a1[S], a2[S], *a3, *ptr;
    int elements;


    srand((unsigned int)time(NULL));

    ptr = a1;
    while((ptr - a1) < S)
    {
        *ptr = rand() % 6;
        printf("%.f ", *ptr);
        ptr++;
    }
    printf("\n");

    ptr = a2;
    while((ptr - a2) < S)
    {
        *ptr = rand() % 11;
        printf("%.f ", *ptr);
        ptr++;
    }
    printf("\n");

    elements = 0;
    a3 = find_diff(a1, a2, S, &elements);

    ptr = a3;
    while((ptr - a3) < elements)
    {
        printf("%.f ", *ptr);
        ptr++;
    }

    printf("\n|_||_||_||_||_||_| \n|_|            |_|\n|_|            |_|\n|_|            |_|\n|_|            |_|\n|_|            |_|\n |_|          |_|\n  |_|        |_|\n   |_|      |_|\n    |_|    |_|\n     |_|  |_|\n      |_||_|\n        |_|");
    free(a3);

    return 0;
}


double* find_diff(double *a1, double *a2, size_t size, int *times)
{
    double *mem, *mem2;
    int i, j, flag;

    *times = 0;

    mem = (double *) malloc(sizeof(double) * size);
    if(NULL == mem)
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

        if(0 == flag)
        {
            if(*times > 0)
            {
                for(j = 0; j < *times; j++)
                {
                    if(*(mem + j) == a1[i])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(!flag)
            {
                mem[*times] = a1[i];
                (*times)++;
            }
        }
    }
    mem2 = (double *)malloc(sizeof(double) * (*times));
    if(NULL == mem2)
    {
        exit(1);
    }

    for(i = 0; i < (*times); i++)
    {
        mem2[i] = mem[i];
    }
    free(mem);

    return mem2;
}
