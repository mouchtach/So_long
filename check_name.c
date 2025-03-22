
#include "so_long.c"

void  check_name(char *name)
{
    int i;

    i = 0;
    while(name[i])
    {
        if(name[i] == '/' && name[i + 1] == '/')
        {
            printf("Error name\n");
            exit(1);
        }
        if(name[i] == '.' && ft_strcmp(name + i, "ber"))
        {
            printf("Error name\n");
            exit(1);
        }
        i++;
    }
}