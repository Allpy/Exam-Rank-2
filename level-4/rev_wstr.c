#include <unistd.h>
#include <stdlib.h>

int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == ' ');
}

char    **ft_split(char *str)
{
	int sidx = 0, arg = 0, idx = 0;
	char **res = malloc(4096);

	while(is_space(str[sidx]))
		sidx++;
	while(str[sidx])
	{
		if(str[sidx] <= 32)
			sidx++;
		else
		{
			res[arg] = malloc(1000);
			while(str[sidx] > 32)
				res[arg][idx++] = str[sidx++];
			res[arg++][idx] = '\0';
			idx = 0;
		}
	}
	return(res[arg] = NULL, res);
}

void	ft_putstr(char *s)
{
	if (!s)
		s = "(null)";
	while (*s && write(1, s++, 1));
}

int main(int ac, char *av[])
{
	char **arr;
	int i = 0;

	if (ac == 2)
	{
		arr = ft_split(av[1]);
		while (arr[i])
			i++;
		while (--i >= 0)
		{
			ft_putstr(arr[i]);
			if (i > 0)
				write(1, " ", 1);
		}
	}
	return (write(1, "\n", 1) - 1);
}