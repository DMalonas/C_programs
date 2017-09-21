#include <stdio.h>
#include <stdlib.h>


#define SIZE 100

int mem_cmp(char *s1, char *s2, int num);

int main(void)
{
    char s1[SIZE], s2[SIZE];
    int num;

    printf("TXT1: ");
    gets(s1);
    printf("TXT2: ");
    gets(s2);
    printf("Char num to cmp: ");
    while(scanf("%d", &num) != 1)
    {
        while(getchar() != '\n');
    }
    if(0 > num)
    {
        num = -num;
    }


    num = mem_cmp(s1, s2, num);

    printf("%d\n", num);

    return 0;

}


int mem_cmp(char *s1, char *s2, int num)
{
    int i;

    for(i = 0; i < num; i++)
    {
        if((*s1) != (*s2))
        {
            return ((*s1) - (*s2));
        }
        s1++;
        s2++;
    }
    return 0;
}
