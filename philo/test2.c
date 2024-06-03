#include <sys/time.h>
#include <stdio.h>
int main()
{
    struct timeval time; 
    printf("----------------\n");
    for(int i = 0; i < 10; i++)
    {
        sleep(1);
        gettimeofday(&time, NULL);
        printf("cal == %ld\n", time.tv_sec * 1000 + time.tv_usec / 1000);
        printf("usec == %ld\n", time.tv_usec);
        printf("sec == %ld\n", time.tv_sec);
        printf("----------------\n");

    }
}
