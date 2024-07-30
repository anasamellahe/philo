#include "philo.h"

t_data *set_data(char **av, int ac)
{
	t_data  *data;
	t_malloc *safe_malloc;

	data = ft_malloc(sizeof(t_data) * 1, &safe_malloc);
	data->num_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->number_of_meals = ft_atoi(av[5]);
	else
		data->number_of_meals = -1;
	data->safe_malloc = safe_malloc;
	return (data);
}

int main (int ac, char *av[])
{
	t_data  *data;

	if (ac >= 5 && ac <= 6)
	{
		if (cheack_av_data(av, ac))
			return (print_error("invalid data\n"), 0);
		data = set_data(av, ac);
		if (check_data(data))
			return (ft_free_malloc(data->safe_malloc), print_error("invalid data\n"), 0);
		philo(data);
	}
	else
		return (print_error("invalid number of args\n"), 0);
}