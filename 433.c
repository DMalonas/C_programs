#include <stdio.h>

typedef struct
{
    int secs;
    int mins;
    int hours;
} time;

time mk_time(int *ptr);

int main(void)
{
    int secs;
    time t;

    printf("Enter seconds: ");
    while(scanf("%d", &secs) != 1)
    {
        printf("\n");
        while(getchar() != '\n');
    }

    if(secs < 0)
    {
        secs = -secs;
    }


    t = mk_time(&secs);

    printf("\nH:%d M:%d S:%d\n", t.hours, t.mins, t.secs);
    return 0;
}

time mk_time(int *ptr)
{
    time t;
    int hours, secs, mins;

    t.hours = (*ptr) / 3600;
    t.mins = (((*ptr) % 3600) / 60);
    t.secs = (((*ptr) % 3600) % 60);
    return t;
};
