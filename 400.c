#include <stdio.h>

#define R 5
#define C 15

int str_comp(char s1[], char s2[]);
void str_cp(char s1[], char s2[]);
void sort_names(char names[][C]);


int main(void)
{
    int  i, j;

    char names[R][C];


    for(i = 0; i < R; i++)
    {
        printf("Name %d: ", i+1);
        gets(names[i]);
    }

    sort_names(names);

    for(i = 0; i < R; i++)
    {
        printf("%d :: %s\n",i, names[i]);
    }

    return 0;
}








void sort_names(char names[][C])
{
    int i, j;
    char temp[C];

    for(i = 0; i < R; i++)
    {
        for(j = i+1; j < R; j++)
        {
            if(str_comp(names[i], names[j]) > 0)
            {
                str_cp(temp, names[i]);
                str_cp(names[i], names[j]);
                str_cp(names[j], temp);
            }
        }
    }
}

int str_comp(char s1[], char s2[])
{
    while ((*s1) == (*s2) && ((*s1) != '\0'))
    {
        s1++;
        s2++;
    }
    if ((*s1) > (*s2))
        return 1;
    else if ((*s1) < (*s2))
        return -1;
    else
        return 0;

}
void str_cp(char s1[], char s2[])
{
    while((*s2) != '\0')
    {
        (*s1) = (*s2);
        s1++;
        s2++;
    }
    (*s1) = '\0';
}



