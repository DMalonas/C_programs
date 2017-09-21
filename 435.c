#include <stdio.h>
#include <string.h>

#define NUM_OF_PRODUCTS 5

typedef struct
{
    char name[50];
    float prc;
    int code;
} product;

typedef enum
{
    LESS = -1,
    EQUAL,
    LARGER
}comparison;

typedef enum
{
    NOT_FOUND = 0,
    FOUND
}name_check;

product *check(product p[], int code);
name_check check_name(product p[], int counter);
int str_cmp(char *s1, char *s2);


int main(void)
{
    product *pro;
    product prod[NUM_OF_PRODUCTS];
    comparison comp;
    name_check chk_name;
    int increment_counter;
    int code;

    increment_counter = 0;

    while(increment_counter < 5)
    {
        printf("P_%d Name: ", increment_counter + 1);
        comp = EQUAL;
        chk_name = NOT_FOUND;
        while(1)
        {
            gets(prod[increment_counter].name);
            if(comp == str_cmp(prod[increment_counter].name, " "))
            {
                continue;
            }
            if(increment_counter != 0)
            {
                if(chk_name != check_name(prod, increment_counter))
                {
                    printf("Name taken\n");
                    continue;
                }
            }
            break;
        }
        printf("P_%d Prce: ", increment_counter + 1);
        while(1)
        {
            while(scanf("%f", &prod[increment_counter].prc) != 1)
            {
                printf("\n");
                while(getchar() != '\n');
            }
            if(prod[increment_counter].prc < 0)
            {
                prod[increment_counter].prc = - prod[increment_counter].prc;
            }
            else if(0 == prod[increment_counter].prc)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        while(getchar() != '\n');
        printf("P_%d Code: ", increment_counter + 1);
        while(scanf("%d", &prod[increment_counter].code) != 1)
        {
            printf("\n");
            while(getchar() != '\n');
        }
        while(getchar() != '\n');

        if((-1) == prod[increment_counter].code)
        {
            break;
        }
        increment_counter++;
    }


    printf("Enter code: ");
    while(scanf("%d", &code) != 1)
    {
        printf("\n");
        while(getchar() != '\n');
    }

    pro = check(prod, code);
    if(NULL == pro)
    {
        printf("Code not in the list\n");
    }
    else
    {
        printf("Product ::: N: %s\tP: %.2f\tC: %d\n", pro->name, pro->prc, pro->code);
    }

    return 0;
}





product *check(product p[], int code)
{
    product pro;
    int increment_counter;

    for(increment_counter = 0; increment_counter < NUM_OF_PRODUCTS; increment_counter++)
    {
        if(code == p[increment_counter].code)
        {
            return &p[increment_counter];
        }
    }
    return NULL;
}


name_check check_name(product p[], int counter)
{
    product pro;
    name_check chk_name;
    comparison comp;
    int increment_counter;


    comp = EQUAL;
    for(increment_counter = 0; increment_counter < counter; increment_counter++)
    {
        if(comp == str_cmp(p[increment_counter].name, p[counter].name))
        {
            chk_name = FOUND;
            return chk_name;
        }
    }
    chk_name = NOT_FOUND;
    return chk_name;
}

int str_cmp(char *s1, char *s2)
{
    comparison comp;
    while(((*s1) != '\0') && (((*s2)) != '\0'))
    {
        if((*s1) == (*s2))
        {
            s1++;
            s2++;
        }
        if((*s1) > (*s2))
        {
            comp = LARGER;
            return comp;
        }
        if((*s1) < (*s2))
        {
            comp = LESS;
            return comp;
        }
    }
    if(((*s1) == '\0') && ((*s2) == '\0'))
    {
        comp = EQUAL;
        return comp;
    }
    if(((*s1) == '\0') && ((*s2) != '\0'))
    {
        comp = LESS;
        return comp;
    }
    comp = LARGER;
    return comp;
}
