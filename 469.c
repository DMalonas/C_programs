#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *rvs_str;
    int i, j, len;

    if(argc == 1)
    {
        printf("No string args");
    }
    else
    {
        for(i = 1; i < argc; i++)
        {
            len = strlen(argv[i]);
            rvs_str = malloc(len + 1);
            if(NULL == rvs_str)
            {
                exit(1);
            }
            for(j = 0; j < len; j++)
            {
                rvs_str[j] = argv[i][len-1-j];
            }
            rvs_str[j] = '\0';
            printf("Reversee of %s is: %s\n", argv[i], rvs_str);
            free(rvs_str);
        }
        free(rvs_str);
    }
}
