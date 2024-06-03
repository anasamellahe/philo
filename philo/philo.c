#include "philo.h"

int ft_atoi(char *str)
{
    long	a;
    int		sign;
	int		i;

	i = 0;
	a = 0;
	sign = 1;
	while (str && ((str[i] >=  9 && str[i] <= 13) || str[i] == 32)) 
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
	gettimeofday(&data->time, NULL);
	data->time_line = data->time.tv_sec * 1000 + data->time.tv_usec / 1000;
	if (av[5] != NULL)
		data->n_t_e = ft_atoi(av[5]);
	else
		data->n_t_e = -1;
}
t_philo *creat_philo(t_data *data)
{
	t_philo *philo;
	int i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->n_o_p);
	while (i < data->n_o_p)
	{
		philo[i].index = i;
		philo[i].eat_time = 0;
		philo[i].data = data;
		philo[i].last_eat = 0;
		pthread_mutex_init(&philo[i].fork_l, NULL);
		i++;
	}
	i = 0;
	while (i < data->n_o_p)
	{
		philo[i].fork_r = &philo[(i + 1) * (i + 1 < data->n_o_p)].fork_l;
		i++;
	}
	return (philo);
}

long int get_time(t_data *data)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	//printf("sleep == %ld %ld\n", (time.tv_sec * 1000 + time.tv_usec / 1000) , data->time_line);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - data->time_line);
}
void sleep_fun(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_time(philo->data), philo->index);
	usleep(philo->data->t_o_s * 1000);
}
// int die_func(t_philo *philo)
// {
// 	if (philo->eat_time == philo->data->n_t_e)
// 	{
// 		printf("philo %d die\n", philo->index);
// 		exit(1);
// 	}
// 	return (0);
// }
void think_fun(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_time(philo->data), philo->index);
}
void *print_message(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	long long time;

	while (1)
	{
		if (philo->eat_time == philo->data->n_t_e)
			return (0);
		pthread_mutex_lock(&philo->fork_l);
		printf("%ld %d has taken a fork\n", get_time(philo->data), philo->index);
		pthread_mutex_lock(philo->fork_r);
		printf("%ld %d has taken a fork\n", get_time(philo->data), philo->index);
		printf("%ld %d is eating\n", get_time(philo->data), philo->index);
		usleep(philo->data->t_o_e * 1000);
		philo->eat_time ++;
		pthread_mutex_unlock(&philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
		sleep_fun(philo);
		think_fun(arg);
	}
}
void creat_thread(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->data->n_o_p)
	{
		if (i  % 2 != 0)
			usleep(100);
		pthread_create(&philo[i].tid, NULL, print_message, &philo[i]);
		i++;
	}
	i = 0;
	while (i < philo->data->n_o_p)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
}
int main (int ac, char **av)
{
	t_data data;
	t_philo *philo;

	printf("ac == %d\n", ac);
    if (ac >= 5 && ac < 7)
    {
        set_data(av, &data);
		philo = creat_philo(&data);
		creat_thread(philo);
    }
    else
        return (1);
}