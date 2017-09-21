#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    double **arr;
    int i, j, rows, cols;


    for(;;)
    {
        printf("Enter number of rows and columns: ");
        while(scanf("%d%d", &rows, &cols) != 2)
        {
            while(getchar() != '\n');
        }
        if((-200 == rows) && (-200 == cols))
        {
            exit(1);
        }
        if(0 == rows || 0 == cols)
        {
            continue;
        }
        if(0 > cols)
        {
            cols = -cols;
        }
        if(0 > rows)
        {
            rows = -rows;
        }


        arr = (double**)malloc(sizeof(double*) * rows);
        if(NULL == arr)
        {
            exit(1);
        }

        for(i = 0; i < rows; i++)
        {
            arr[i] = (double *)malloc(sizeof(double) * cols);
            if(NULL == arr[i])
            {
                exit(1);
            }
        }

        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                printf("\narr[%d][%d] :: ", i, j);
                while(scanf("%lf", &arr[i][j]) != 1)
                {
                    while(getchar() != '\n');
                }
            }
        }

        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                printf("%.f ", arr[i][j]);
            }
            printf("\n");
        }


        for(i = 0; i < rows; i++)
        {
            free(arr[i]);
        }
        free(arr);
    }
    return 0;
}
