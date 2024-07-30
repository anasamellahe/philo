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
#include <sys/time.h>

typedef struct s_forks
{
	pthread_mutex_t forks;
}	t_forks;

typedef struct s_philo
{
	pthread_t		t_id;
	struct s_data 	*data;
	unsigned long	last_eat_time;
	int				id;
	int				number_of_meals;
	bool			die_flag;
}	t_philo;

typedef struct s_data
{
	bool		flag;
	int			id;
	pthread_mutex_t		data_lock;
	unsigned long		timestamp;
	unsigned long 		num_of_philo;
	unsigned long 		time_to_die;
	unsigned long 		time_to_eat;
	unsigned long 		time_to_sleep;
	unsigned long 		number_of_meals;
	pthread_t			monitor_id;
	t_philo 			*philos;
	t_forks 			*forks;
	t_malloc 			*safe_malloc;
}   t_data;

int				ft_strlen (char *str);
void			print_error(char *str);

int				cheack_av_data(char **av, int ac);
int				check_data(t_data *data);
unsigned long 	ft_atol(char *str);


void			*routine(void *arg);
void			start_thread(t_data *data);
void			init_philo(t_data *data);
void			init_mutex(t_data *data);
int				get_max(int a, int b);
int				get_min(int a, int b);
int				philo(t_data *data);
unsigned long	get_current_time();



void    go_eat(int t_id, int flag, t_data *data);
void    go_think(int t_id, int flag, t_data *data);
void    go_sleep(int t_id, int flag, t_data *data);
void	go_die(int t_id, int flag, t_data *data);
#endif