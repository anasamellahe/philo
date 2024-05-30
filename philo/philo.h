#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data
{
    int n_o_p;
    int t_o_d;
    int t_o_e;
    int t_o_s;
    int n_t_e;
}   t_data;

typedef struct s_philo
{
    pthread_t id;
    pthread_mutex_t fork;
    int index;
    int eat_time;
    int sleep;
    int eat;
    int think;
    t_data *data;
}   t_philo;
#endif