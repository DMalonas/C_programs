#include <stdio.h>

#define S 100

int mem_cmp(const void *s1, const void *s2, size_t size);

int main(void)
{
    int num_of_chars_to_cmp;
    char s1[S], s2[S];

    gets(s1);
    gets(s2);
    while(scanf("%d", &num_of_chars_to_cmp) != 1)
    {
        while(getchar() != '\n');
    }

    if(mem_cmp(s1, s2, num_of_chars_to_cmp) > 0)
    {
        printf("S1 > S2");
    }
    else if(mem_cmp(s1, s2, num_of_chars_to_cmp) < 0)
    {
        printf("S1 < S2");
    }
    else
    {
        printf("S1 == S2");
    }

    return 0;

}


int mem_cmp(const void *s1, const void *s2, size_t size)
{
    unsigned char *p1, *p2;

    p1 = (unsigned char*)s1;
    p2 = (unsigned char*)p2;

    while(size != 0)
    {
        if(*p1 != *p2)
        {
            return (*(p1) - *(p2));
        }
        p1++;
        p2++;
        size--;
    }
}
