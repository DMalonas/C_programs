#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *arr;

    arr = (char *) malloc(6);

    if( arr == NULL )
    {
        exit(1);
    }
    else{
        memcpy( arr, "ABCDE", 6);
        printf("arr = = %s\n", arr);
        free(arr);
    }

    return 0;
}
