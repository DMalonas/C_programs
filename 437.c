#include <stdio.h>


typedef struct
{
    float x;
    float y;
}coord;

typedef struct
{
    coord pointA;
    coord pointB;
}rectangle;


float area(rectangle *rec);

int main(void)
{

    rectangle rec;

    while(1)
    {
        printf("x1: ");
        while(scanf("%f", &rec.pointA.x) != 1)
        {
            while(getchar() != '\n');
        }
        printf("\ny1: ");
        while(scanf("%f", &rec.pointA.y) != 1)
        {
            while(getchar() != '\n');
        }
        printf("\nx2: ");
        while(scanf("%f", &rec.pointB.x) != 1)
        {
            while(getchar() != '\n');
        }
        printf("\ny2: ");
        while(scanf("%f", &rec.pointB.y) != 1)
        {
            while(getchar() != '\n');
        }
        break;
    }
    printf("The area of the rectangle with diagonal points A(%.1f, %.1f) and B(%.1f, %.1f) is :::: \
            %.2f\n", rec.pointA.x, rec.pointA.y, rec.pointB.x, rec.pointB.y, area(&rec));

    return 0;
}


float area(rectangle *rec)
{
    float len, wid;

    if(rec->pointA.x > rec->pointB.x)
    {
        len = rec->pointA.x - rec->pointB.x;
    }
    else
    {
        len = rec->pointB.x - rec->pointA.x;
    }

    if(rec->pointA.y > rec->pointB.y)
    {
        wid = rec->pointA.y - rec->pointB.y;

    }
    else
    {
        wid = rec->pointB.y - rec->pointA.y;
    }
    return (wid * len);
}
