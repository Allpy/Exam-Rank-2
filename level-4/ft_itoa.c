#include <stdlib.h>

int ft_countnbr(int nbr)
{
    int count = 0;
    if (nbr == 0)
        count++;
    if (nbr < 0)
    {
        nbr = -nbr;
        count++;
    }
    while (nbr > 9)
    {
        nbr /= 10;
        count++;
    }
    if(nbr < 10)
        count++;
    return(count);
}

char *ft_itoa(int nbr)
{
    int i = ft_countnbr(nbr);
    char *res = malloc (i + 1);
    res[i] = '\0';
    i--;
    if (nbr == 0)
        res[0] = '0';
    if (nbr < 0)
    {
        res[0] = '-';
        nbr = -nbr;
    }
    while (nbr > 0)
    {
        res[i] = (nbr % 10) + 48;
        nbr /= 10;
        i--;
    }
    return (res);
}