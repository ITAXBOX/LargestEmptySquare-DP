#include "c_minded.h"

void	ft_fill_zeroes(int *arr, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		arr[i] = 0;
		i++;
	}
}

int	three_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	ft_print(char **result, int coord[])
{
	int	i;
	int	j;

	i = 0;
	while (i < coord[0])
	{
		j = 0;
		while (j < coord[1])
		{
			write(1, &result[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
