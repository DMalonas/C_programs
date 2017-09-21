#include <stdio.h>

#define SIZE 5
#define MAN 0
#define WOMAN 1


struct person
{
    int type;
    union
    {
        struct
        {
            char game[20];
            char movie[20];
        } man;
        struct
        {
            char tv_show[30];
            char book[30];
        } woman;
    } data;
};


int main(void)
{
    int i, type;
    struct person pers_arr[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("\nSelection: 0 for man - 1 for woman: ");
        while(1)
        {
            while(scanf("%d", &type) != 1)
            {
                while(getchar() != '\n');
            }
            if((type == 1) || (type == 0))
            {
                break;
            }
            continue;
        }
        pers_arr[i].type = type;
        getchar();
        if(type == MAN)
        {
            printf("Enter favourite game: ");
            gets(pers_arr[i].data.man.game);

            printf("Enter favourite movie: ");
            gets(pers_arr[i].data.man.movie);
        }
        else if(type == WOMAN)
        {
            printf("Enter favourite TV show: ");
            gets(pers_arr[i].data.woman.tv_show);

            printf("Enter favourite book: ");
            gets(pers_arr[i].data.woman.book);
        }
    }
    for(i = 0; i < SIZE; i++)
    {
        if(pers_arr[i].type == MAN)
        {
            printf("\nGame: %s\n", pers_arr[i].data.man.game);
            printf("\nShow = %s\n", pers_arr[i].data.man.movie);
        }
        else if(WOMAN == pers_arr[i].type)
        {
            printf("\nMovie: %s\nBook: %s\n", pers_arr[i].data.woman.tv_show, pers_arr[i].data.woman.book);
        }
    }
    return 0;
}
