#include <stdio.h>

int main()
{
    int x, ans, start, mid, end, cnt;

    cnt = 0;

    printf("Enter number[0, 1000]: ");
    while(1)
    {
        while(scanf("%d", &x) != 1)
        {
            printf("\n");
            while(getchar() != '\n');
        }
        if((x < 0) || (x > 1000))
        {
            printf("\nOut of range\n");
            continue;
        }
        break;
    }

    start = 0;
    end = 1000;
    mid = (start + end) / 2;

    while(start <= end)
    {
        printf("Is your number %d? (yes, 1) : (no, 2): ", mid);
        while(1)
        {
            while(scanf("%d", &ans) != 1)
            {
                printf("\n");
                while(getchar() != '\n');
            }
            if((1 == ans) || (2 == ans))
            {
                cnt++;
                break;
            }
            printf("\nInvalid input. Try again.\n");
        }
        if(1 == ans)
        {
            break;
        }
        printf("\nIs your number less than %d? (yes, 1) : (no, 2): ", mid);
        while(1)
        {
            while(scanf("%d", &ans) != 1)
            {
                printf("\n");
                while(getchar() != '\n');
            }
            if((1 == ans) || (2 == ans))
            {
                break;
            }
            printf("\nInvalid input. Try again.\n");
        }
        if(1 == ans)
        {
            end = mid -1;
            mid = (start + end) / 2;
            ans = -1;
        }
        if(2 == ans)
        {
            start = mid + 1;
            mid = (start + end) / 2;
            ans = -1;
        }
    }

    if(1 == ans)
    {
        printf("Number found in %d efforts\n", cnt);
    }
    else
    {
        printf("Number was not found\n");
    }

    return 0;
}
