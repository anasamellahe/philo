#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int i;
    long nbr;
    int sign;

    i = nbr = sign = 0;
    if (!str)
        return (-1);
    sign = ((str[i] == '-') * -1) + ((str[i] != '-') * 1);
    i += (str[i] == '-' || str[i] == '+');
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10 + (str[i] - 48);
        if ((nbr * sign) < -2147483648 || (nbr * sign) >  2147483647)
            return (-1);
        i++;
    }
    return (nbr * sign);
}

int main ()
{
    printf("%d\n", atoi("   --12566 -P11 87"));
    printf("%d\n", ft_atoi("120"));
    printf("%d\n", ft_atoi("10"));
    printf("%d\n", ft_atoi("-252"));
    printf("%d\n", ft_atoi("2147483647"));
}