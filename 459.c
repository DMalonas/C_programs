#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int number_of_currencies, i;
    double *rates;


    printf("Num of currencies: ");
    while(scanf("%d", &number_of_currencies) != 1)
    {
        while(getchar() != '\n');
    }
    if(0 > number_of_currencies)
    {
        number_of_currencies = -number_of_currencies;
    }

    rates = (double *) malloc(number_of_currencies * sizeof(double));

    for(i = 0; i < number_of_currencies; i++)
    {
        printf("Curr_%d: ", i + 1);
        while(scanf("%lf", rates + i) != 1)
        {
            while(getchar() != '\n');
        }
    }

    for(i = 0; i < number_of_currencies; i++)
    {
        printf("curr_%d == %.2lf\t", i + 1, *(rates + i));
    }

    return 0;
}
