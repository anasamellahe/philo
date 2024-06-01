#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
// typedef struct s_philos
// {
// 	pthread_mutex_t	left_fork;
// 	pthread_mutex_t	right_fork;
// 	pthread_t		tid;
// 	int				think;
// 	int 			sleep;
// 	int				eat_n;
// 	int				id;
// 	int				eat;
// }	t_philos;

typedef struct s_arg
{
	pthread_mutex_t *fork_l;
	pthread_mutex_t *fork_r;
	pthread_t tid;
	int id;
}	t_arg;
void *print_message(void *arg)
{
	t_arg *args = (t_arg *)arg;
	printf("philo id == %d\n", args->id);
	while (1)
	{
		printf("in while %d\n", args->id);
		pthread_mutex_lock(args->fork_l);
		printf("philo %d take a fork_l\n", args->id);
		pthread_mutex_lock(args->fork_r);
		printf("philo %d take a fork_r\n", args->id);
		printf("philo %d eat\n", args->id);
		pthread_mutex_unlock(args->fork_l);
		printf("philo %d unlock  a for_lk\n", args->id);
		pthread_mutex_unlock(args->fork_r);
		printf("philo %d unlock  a fork_r\n", args->id);
		usleep(200);
	}
}
int main(int ac, char **av)
{
	 t_arg arg1;
	 t_arg arg2;

	pthread_mutex_t fork_l;
	pthread_mutex_t fork_r;
	arg1.fork_l = &fork_l;
	arg1.fork_r = &fork_r;
	arg2.fork_l = &fork_l;
	arg2.fork_r = &fork_r;
	arg1.id = 0;
	arg2.id = 1;
	pthread_mutex_init(&fork_l, NULL);
	pthread_mutex_init(&fork_r, NULL);
	pthread_create(&arg1.tid, NULL, print_message, &arg1);
	usleep(800);
	pthread_create(&arg2.tid, NULL, print_message, &arg2);

	pthread_join(arg1.tid, NULL);
	pthread_join(arg2.tid, NULL);

	pthread_mutex_destroy(&fork_l);
	pthread_mutex_destroy(&fork_r);


}