#include <stdio.h>
#include <string.h>

void str_cpy(char d[], char s[]);

typedef struct
{
    char name[50];
    float grd;
} student;


int main()
{
    student stud, *stud_ptr;

    stud.grd = 6;
    str_cpy(stud.name, "Loui");

    stud_ptr = &stud;
    printf("name : %s\tgrade : %.2f\n", stud_ptr -> name, stud_ptr -> grd);
    return 0;
}


void str_cpy(char d[], char s[])
{
    int i = 0;
    while(s[i] != '\0')
    {
        d[i] = s[i];
        i++;
    }
    d[i] = '\0';
}
