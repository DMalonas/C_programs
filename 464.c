#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define S 100


void str_cat(char *fin, char *s1, char *s2);


int main(void)
{
    char *fin;
    char s1[S], s2[S];

    printf("Enter text 1: ");
    gets(s1);
    printf("Enter text 2: ");
    gets(s2);

    fin = malloc(strlen(s1) + strlen(s2) + 1);

    if(NULL == fin)
    {
        exit(1);
    }

    str_cat(fin, s1, s2);

    printf("FIN is now ::: %s\n", fin);


    free(fin);

    return 0;
}



void str_cat(char *fin, char *s1, char *s2)
{
    while(1)
    {
        if(*s1 == '\0')
        {
            break;
        }
        *fin = *s1;
        fin++;
        s1++;
    }
    while(1)
    {
        if(*s2 == '\0')
        {
            *fin = *s2;
            break;
        }
        *fin = *s2;
        fin++;
        s2++;
    }
}
