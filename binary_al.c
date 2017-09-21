#include <stdio.h>

int main()
{
    int ans, x, mid, start, end, cnt;

    cnt = 0;
    ans = -1;
    printf("Enter num [0 - 1000]: ");
    while(1)
    {
        while(scanf("%d", &x) != 1)
        {
            printf("Enter num [0 - 1000]: ");
            while(getchar() != '\n');
        }
        if((x < 0) || (x > 1000))
        {
            printf("\nRange is [0 - 1000]\n");
        }
        else
        {
            break;
        }
    }

    start = 0;
    end = 1000;
    mid = (start + end) / 2;


    while(start <= end)
    {
        if((-10) == ans)
        {
            break;
        }
        while(1)
        {
            printf("\nIs your number %d? (Yes,1) | (No, 2): ", mid);
            while(scanf("%d", &ans) != 1)
            {
                printf("(Yes, 1) | (No, 2)\n");
                while(getchar() != '\n');
            }
            if((1 != ans) && (2 != ans))
            {
                printf("Acceptable answers are 1 and 2\n");
            }
            if(1 == ans)
            {
                cnt++;
                printf("The number was found in %d efforts ",cnt);
                ans = -10;
            }
            break;
        }
        if(2 == ans)
        {
            cnt++;
            while(1)
            {
                printf("\nIs your number less than %d: (Yes,1) | (No, 2): ", mid);
                while(scanf("%d", &ans) != 1)
                {
                    printf("(Yes, 1) | (No, 2)\n");
                    while(getchar() != '\n');
                }
                if((1 != ans) && (2 != ans))
                {
                    printf("Acceptable answers are 1 and 2\n");
                }
                if((1 == ans) || (2 == ans))
                {
                    if(1 == ans)
                    {
                        end = mid - 1;
                        mid = (start + end) / 2;
                    }
                    if(2 == ans)
                    {
                        start = mid + 1;
                        mid = (start + end) / 2;
                    }

                    break;
                }
            }
        }
    }
        return 0;
}
