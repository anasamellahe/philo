#include "philo.h"

t_data *set_data(char **av, int ac)
{
	t_data  *data;
	t_malloc *safe_malloc;

	data = ft_malloc(sizeof(t_data) * 1, &safe_malloc);
	data->num_of_philo = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->number_of_meals = ft_atol(av[5]);
	else
		data->number_of_meals = 0;
	data->safe_malloc = safe_malloc;
	data->flag = 0;
	data->timestamp = get_current_time();
	if (pthread_mutex_init(&data->data_lock, NULL))
		ft_free_malloc(data->safe_malloc);
	return (data);
}
// void print_data(t_data *data)
// {
// 	printf("%d\n", data->flag);
// 	printf("%lu\n", data->num_of_philo);
// 	printf("%lu\n", data->number_of_meals);
// 	printf("%lu\n", data->time_to_die);
// 	printf("%lu\n", data->time_to_eat);
// 	printf("%lu\n", data->time_to_sleep);
// 	printf("%lu\n", data->timestamp);
// }
int main (int ac, char *av[])
{
	t_data  *data;

	if (ac >= 5 && ac <= 6)
	{
		if (cheack_av_data(av, ac))
			return (print_error("invalid data\n"), 0);
		data = set_data(av, ac);
		// print_data(data);
		// exit(10);
		if (check_data(data))
			return (ft_free_malloc(data->safe_malloc), print_error("invalid data\n"), 0);
		philo(data);
	}
	else
		return (print_error("invalid number of args\n"), 0);
}