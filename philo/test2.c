#include <sys/time.h>
#include <stdio.h>
int main()
{
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        printf("%ld\n", utime(NULL));
    }
    struct timeval time; 
    printf("----------------\n");
    for(int i = 0; i < 10; i++)
    {
        sleep(1);
        gettimeofday(&time, NULL);
        printf("%ld\n", time.tv_sec);
    }
}
