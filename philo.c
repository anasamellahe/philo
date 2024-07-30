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
		data->philos[i].last_eat_time = get_current_time();
		if (data->philos[i].last_eat_time == 0)
			ft_free_malloc(data->safe_malloc);
		data->philos[i].number_of_meals = data->number_of_meals;
		data->philos[i].data = data;
		data->philos[i].die_flag = 0;
		i++;
	}
}

int get_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int get_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
void *monitoring(void *arg)
{
	t_data *data;
	int	i;

	i = 0;
	data = arg;
	while (data->flag == 0)
	{
		while (i < data->num_of_philo)
		{
			if ((data->philos[i].last_eat_time - get_current_time()) > data->time_to_die)
			{
				// data->flag = 1;
				// data->philos[i].die_flag = 1;
			}
			i++;
		}
		i = 0;
	}
	printf("anas\n");

}
void *routine(void *arg)
{
	t_philo *philo;
	t_data 	*data;
	int		min;
	int		max;

	philo = arg;
	data = philo->data;
	while (data->flag == 0)
	{
		min = get_min(philo->id, (philo->id + 1) % data->num_of_philo);
		max = get_max(philo->id, (philo->id + 1) % data->num_of_philo);
		pthread_mutex_lock(&data->forks[min].forks);
		printf("%lu %d has taken a fork\n", (get_current_time() - data->timestamp), philo->id);
		pthread_mutex_lock(&data->forks[max].forks);
		printf("%lu %d has taken a fork\n", (get_current_time() - data->timestamp), philo->id);
		go_eat(philo->id, data->flag, data);
		pthread_mutex_unlock(&data->forks[min].forks);
		pthread_mutex_unlock(&data->forks[max].forks);
		go_think(philo->id, data->flag, data);
		go_sleep(philo->id, data->flag, data);
	}
	go_die(philo->id, data->flag, data);
}
void	start_thread(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_create(&data->monitor_id, NULL, monitoring, data) != 0)
		ft_free_malloc(data->safe_malloc);
	while(i < data->num_of_philo)
	{
		data->philos[i].id = i;
		if (pthread_create(&data->philos[i].t_id, NULL, routine, &data->philos[i]) != 0)
			ft_free_malloc(data->safe_malloc);
		i++;
	}
	i = 0;
	while(i < data->num_of_philo)
	{
		data->philos[i].id = i;
		if (pthread_join(data->philos[i].t_id, NULL) != 0)
			ft_free_malloc(data->safe_malloc);
		i++;
	}
	if (pthread_join(data->monitor_id, NULL) != 0)
		ft_free_malloc(data->safe_malloc);
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
	start_thread(data);
}