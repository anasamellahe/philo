#include "philo.h"

void    go_eat(int t_id, int flag, t_data *data)
{
    if (!flag)
    {
        printf("%lu %d is eating\n", (get_current_time() - data->timestamp), t_id);
        usleep(data->time_to_eat);
        data->philos[t_id].last_eat_time = get_current_time();
    }
}
void    go_think(int t_id, int flag, t_data *data)
{
    if (!flag)
        printf("%lu %d is thinking\n", (get_current_time() - data->timestamp), t_id);
}

void    go_sleep(int t_id, int flag, t_data *data)
{
    if (!flag)
    {
        printf("%lu %d is sleeping\n", (get_current_time() - data->timestamp), t_id);
        usleep(data->time_to_sleep);
    }
}

void go_die(int t_id, int flag, t_data *data)
{
    if (data->philos[t_id].die_flag == 1)
        printf("%lu %d died\n", (get_current_time() - data->timestamp), t_id);
}