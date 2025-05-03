#include "c_minded.h"

void	print_solution(char **result, int tab[], t_map_info info, int coord[])
{
	int	i;
	int	j;

	i = tab[0];
	while (i > tab[0] - tab[2])
	{
		j = tab[1];
		while (j > tab[1] - tab[2])
		{
			result[i][j] = info.full;
			j--;
		}
		i--;
	}
	ft_print(result, coord);
}

void	fill_tab(int tab[], int a, int b, int c)
{
	tab[0] = a;
	tab[1] = b;
	tab[2] = c;
}

int	change_table(int **arr, int i, int j)
{
	return (1 + three_min(arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1]));
}

void	solve(char **result, int **arr, int coord[], t_map_info info)
{
	int	i;
	int	j;
	int	tab[3];

	i = 0;
	fill_tab(tab, 0, 0, -1);
	while (i < coord[0])
	{
		j = 0;
		while (j < coord[1])
		{
			if (result[i][j] == info.empty)
			{
				if (i - 1 < 0 || j - 1 < 0)
					arr[i][j] = 1;
				else
					arr[i][j] = change_table(arr, i, j);
				if (arr[i][j] > tab[2])
					fill_tab(tab, i, j, arr[i][j]);
			}
			j++;
		}
		i++;
	}
	print_solution(result, tab, info, coord);
}

void	start_solve(char **result, int rows_count
		, int cols_count, t_map_info info)
{
	int		**arr;
	int		i;
	int		coord[2];

	i = 0;
	arr = (int **) malloc(sizeof(int *) * rows_count);
	while (i < rows_count)
	{
		arr[i] = (int *)malloc(sizeof(int) * cols_count);
		ft_fill_zeroes(arr[i], cols_count);
		i++;
	}
	coord[0] = rows_count;
	coord[1] = cols_count;
	solve(result, arr, coord, info);
}
