#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define S  5
#define S2 100

int main(void)
{
    char *str[S];
    int i, pos, len, max;


    max = pos = len = 0;

    for(i = 0; i < S; i++)
    {
        str[i] = malloc(S2);
        if(NULL == str[i])
        {
            exit(1);
        }
        printf("Txt_%d :: ", i+1);
        gets(str[i]);
        len = strlen(str[i]);
        if(len > max)
        {
            max = len;
            pos = i;
        }
        free(str[i]);
    }
    printf("\nMax len %d at pos %d\n", len, pos);


    return 0;
}
