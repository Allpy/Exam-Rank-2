#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int nbr = atoi(av[1]);
        int i = 2;
        if(nbr == 1)
            printf("1");
        while (i <= nbr)
        {
            if (nbr % i == 0)
            {
                printf("%d", i);
                nbr /= i;
                i = 2;
                if((i <= nbr))
                    printf("*");
            }
            else
                i++;
        }
    }
    printf("\n");
}