#ifndef PHILO_H
#define PHILO_H

#include "malloc.h"
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
#include <limits.h>
#include <stdbool.h>


typedef struct s_forks
{
	pthread_mutex_t forks;
}	t_forks;

typedef struct s_philo
{
	pthread_t		t_id;
	int				id;
	int				number_of_meals;
	int				last_eat_time;
	bool			die_flag;
}	t_philo;

typedef struct s_data
{
	int num_of_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_meals;
	t_philo *philos;
	t_forks *forks;
	t_malloc *safe_malloc;
}   t_data;

int ft_strlen (char *str);
void print_error(char *str);

int cheack_av_data(char **av, int ac);
int ft_atoi(char *str);
int check_data(t_data *data);

#endif