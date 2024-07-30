#include "philo.h"

void init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i].forks, NULL) != 0)
			ft_free_malloc(data->safe_malloc);
		i++;
	}
}

void init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		data->philos[i].id = i;
		data->philos[i].last_eat_time = 0;
		data->philos[i].number_of_meals = data->number_of_meals;
		i++;
	}
}
void *routine(void *data)
{
	while (((t_data *)data)->philos[id]->die_flag == 0)
	{
		pthread_mutex_lock(dat[])
		go_eat(data);
		go_sleep(data);
		go_think(data);
	}
}
void	start_thread(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->num_of_philo)
	{
		if (pthread_create(&data->philos[i].t_id, NULL, routine, data) != 0)
			ft_free_malloc(data->safe_malloc);
		i++;
	}
	i = 0;
	while(i < data->num_of_philo)
	{
		if (pthread_join(data->philos[i].t_id, NULL) != 0)
			ft_free_malloc(data->safe_malloc);
		i++;
	}
}
int philo(t_data *data)
{
	t_philo *philo;
	t_forks *forks;

	philo = (t_philo *)ft_malloc(sizeof(t_philo) * data->num_of_philo, &data->safe_malloc);
	forks = (t_forks *)ft_malloc(sizeof(t_forks) * data->num_of_philo, &data->safe_malloc);
	data->philos = philo;
	data->forks = forks;
	init_mutex(data);
	init_philo(data);
	start_rthread(data);
}