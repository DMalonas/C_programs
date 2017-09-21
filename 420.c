#include <stdio.h>


typedef struct
{
    int day;
    int month;
    int year;
}date;

typedef struct
{
     date start_date;
     date end_date;
    char name[50];
    double price;
} product;


int main(void)
{
    product product_1;


    product_1.start_date.day = 1;
    product_1.start_date.month = 1;
    product_1.start_date.year = 1940;
    strcpy(product_1.name, "Wine");
    product_1.price = 10;


    product_1.end_date.day = 1;
    product_1.end_date.month = 1;
    product_1.end_date.year = 2240;

    printf("The products life cycle is %d years\n", -product_1.start_date.year + product_1.end_date.year);
    return 0;
}
