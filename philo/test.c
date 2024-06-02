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
	pthread_mutex_t fork_l;
	pthread_mutex_t *fork_r;
	pthread_t tid;
	int id;
}	t_arg;
void sleep_fun(t_arg *arg)
{
	printf("philo %d is sleeping\n", arg->id);
	usleep(100);
}

void think_fun(t_arg *arg)
{
	printf("philo %d is thinking\n", arg->id);
	usleep(100);
}

void *print_message(void *arg)
{
	t_arg *args = (t_arg *)arg;
	while (1)
	{
		pthread_mutex_lock(&args->fork_l);
		printf("philo %d take a fork_l\n", args->id);
		pthread_mutex_lock(args->fork_r);
		printf("philo %d take a fork_r\n", args->id);
		printf("-------------------------\n");
		printf("philo %d eat\n", args->id);
		printf("-------------------------\n");
		usleep(60);
		pthread_mutex_unlock(&args->fork_l);
		printf("philo %d unlock  a fork_l\n", args->id);
		pthread_mutex_unlock(args->fork_r);
		printf("philo %d unlock  a fork_r\n", args->id);
		sleep_fun(arg);
		//think_fun(arg);
	}
}
int main(int ac, char **av)
{
	t_arg arg1;
	t_arg arg2;
	t_arg arg3;
	t_arg arg4;
	
	arg1.id = 0;
	arg2.id = 1;
	arg3.id = 2;
	arg4.id = 3;

	pthread_mutex_init(&arg1.fork_l, NULL);
	pthread_mutex_init(&arg2.fork_l, NULL);
	pthread_mutex_init(&arg3.fork_l, NULL);
	//pthread_mutex_init(&arg4.fork_l, NULL);


	arg1.fork_r = &arg2.fork_l;
	arg2.fork_r = &arg3.fork_l;
	arg3.fork_r = &arg1.fork_l;
	//arg4.fork_r = &arg1.fork_l;

	pthread_create(&arg1.tid, NULL, print_message, &arg1);
	pthread_create(&arg3.tid, NULL, print_message, &arg2);
	usleep(800);
	pthread_create(&arg2.tid, NULL, print_message, &arg3);
	//pthread_create(&arg4.tid, NULL, print_message, &arg4);

	pthread_join(arg1.tid, NULL);
	pthread_join(arg2.tid, NULL);
	pthread_join(arg3.tid, NULL);
	pthread_join(arg4.tid, NULL);	

	pthread_mutex_destroy(&arg1.fork_l);
	pthread_mutex_destroy(&arg2.fork_l);
	pthread_mutex_destroy(&arg3.fork_l);
	pthread_mutex_destroy(&arg4.fork_l);


}