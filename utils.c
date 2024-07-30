#include "philo.h"

int ft_atoi(char *str)
{
    int i;
    long nbr;
    int sign;

    i = nbr = sign = 0;
    if (!str)
        return (-1);
    sign = ((str[i] == '-') * -1) + ((str[i] != '-') * 1);
    i += (str[i] == '-' || str[i] == '+');
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10 + (str[i] - 48);
        if ((nbr * sign) < -2147483648 || (nbr * sign) >  2147483647)
            return (-1);
        i++;
    }
    return (nbr * sign);
}
int cheack_av_data(char **av, int ac)
{
    int i;
    int j;

    i = 1;
    while(av && av[i])
    {
        j = 0;
        while (av[i][j] && ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32) || av[i][j] == '-' || av[i][j] == '+')
            j++;
        while(av[i][j] >= '0' && av[i][j] <= '9')
        {
            j++;
        }
        while (av[i][j] && ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32))
            j++;
        if (av[i][j] != 0)
            return (1);
        i++;
    }
    return (0);
}
int check_data(t_data *data)
{
    if (data->num_of_philo < 0 || data->time_to_die < 0 || data->time_to_eat < 0 || data->time_to_sleep < 0)
        return (1);
    if (data->num_of_philo > 200 || data->time_to_die < 60 || data->time_to_eat < 60 || data->time_to_sleep < 60)
        return (1);
    return (0);
}
