#include <stdio.h>

#define SIZE 25
#define NUMBER_OF_STUDENTS 5
typedef struct
{
    char name[SIZE];
    float grd;
    int code;
} student;

void sort_grades(student st[]);
void show_overachieving_student(student st[]);

int main(void)
{
    student st[NUMBER_OF_STUDENTS], *s;

    s = st;

    while(s <= (st + NUMBER_OF_STUDENTS - 1))
    {
        printf("_Student %d_\nName: ", s - st + 1);
        gets(s->name);
        printf("Grade: ");
        while(scanf("%f", &(s->grd)) != 1)
        {
            while(getchar() != '\n');
        }
        while(getchar() != '\n');
        printf("Code: ");
        while(scanf("%d", &(s->code)) != 1)
        {
            while(getchar() != '\n');
        }
        while(getchar() != '\n');
        printf("s == %d\n\n", (s + 1 - st));
        s++;
    }

    sort_grades(st);
    show_overachieving_student(st);
    return 0;
}

void sort_grades(student st[])
{
    student temp;
    int i, j;

    for(i = 0; i < (NUMBER_OF_STUDENTS); i++)
    {
        for(j = i + 1; j < (NUMBER_OF_STUDENTS); j++)
        {
            if((st[i].grd) > (st[j].grd))
            {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
}


void show_overachieving_student(student st[])
{
    float g, avg;
    int i;

    g = 0;


    for(i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        g += st[i].grd;
    }
    avg = g / i;

    printf("Average is %.2f\n", avg);
    for(i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        if(st[i].grd > avg)
        {
            printf("Student_%d with grd: %.2f\n", i+1, st[i].grd);
        }
    }
}
