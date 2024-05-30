#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
	pthread_mutex_t fork1;
	pthread_mutex_t fork2;
}	t_arg;
void *print_message(void *arg)
{
	t_arg *args;

	args = (t_arg *)arg;
	pthread_mutex_lock(&args->fork1);
	printf("hello anas\n");
	pthread_mutex_unlock(&args->fork1);
	pthread()
}
int main(int ac, char **av)
{
	 pthread_mutex_t fork1;
	 pthread_mutex_t fork2;
	 pthread_t t1;
	 pthread_t t2;
	 t_arg arg;
	
	pthread_mutex_init(&fork1, NULL);
	pthread_mutex_init(&fork2, NULL);
	arg.fork1 = fork1;
	arg.fork2 = fork2;
	pthread_create(&t1, NULL, print_message, &arg);
	pthread_create(&t2, NULL, print_message, &arg);

	pthread_join(&t1, NULL);
	pthread_join(&t2, NULL);

	pthread_mutex_destroy(&fork1);
	pthread_mutex_destroy(&fork2);


}