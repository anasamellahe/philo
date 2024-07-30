#include "philo.h"

int ft_strlen (char *str)
{
    int i;

    i = 0;
    while (str && str[i])
        i++;
    return (i);
}

void print_error(char *str)
{
    write(2, str, ft_strlen(str));
}