#include "philo.h"

int ft_atoi(char *str)
{
    long	a;
    int		sign;
	int		i;

	i = 0;
	a = 0;
	sign = 1;
	while (str && (str[i] >=  9 && str[i] <= 13) || str[i] == 32) 
		i++;
	while (str && (str[i] == '-' || str[i] == '+') && str[i])
	{
		sign *= ((str[i] == '-') * -1) + (str[i] == '+');
		i++;
	}
	while (str && str[i] >= '0' && str[i] <= '9' && str[i])
	{
		a = (10 * a) + (str[i] - 48);
		i++;
	}
	return ((int)(a * sign));
}
void set_data(char **av, t_data *data)
{
	data->n_o_p = ft_atoi(av[1]);
	data->t_o_d = ft_atoi(av[2]);
	data->t_o_e = ft_atoi(av[3]);
	data->t_o_s = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->n_t_e = ft_atoi(av[5]);
	else
		data->n_t_e = -1;
}
int main (int ac, char **av)
{
	t_data data;

	printf("ac == %d\n", ac);
    if (ac >= 5 && ac < 7)
    {
        set_data(av, &data);
		printf("%d %d %d %d %d \n", data.n_o_p, data.t_o_d, data.t_o_e, data.t_o_s, data.n_t_e);
    }
    else
        return (1);
}