#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct s_data
{
    int             n_o_p;
    int             t_o_d;
    int             t_o_e;
    int             t_o_s;
    int             n_t_e;
    long int        time_line;
    struct timeval  time;
}   t_data;

typedef struct s_philo
{
    pthread_t tid;
    pthread_mutex_t fork_l;
    pthread_mutex_t *fork_r;
    t_data *data;
    int index;
    int eat_time;
    int last_eat;
}   t_philo;
#endif