#ifndef C_MINDED_H
# define C_MINDED_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct map_info
{
	char	obstacle;
	char	empty;
	char	full;
}	t_map_info;

char	**validate_inputs(char *inputs);
char	**ft_get_inputs(char *path, int count_lines);
int		get_number_in_first_line(char *str);
char	*get_first_line(char	*path);
int		ft_strlen(char *str);
int		get_number_of_columns(char *path);
void	ft_free(char **result, int count_lines);
int		get_nb_of_rows(int fd);
void	ft_print(char **result, int coord[]);
void	start_solve(char **result, int rows_count,
			int cols_count, t_map_info info);
void	ft_fill_zeroes(int *arr, int col);
int		three_min(int a, int b, int c);
void	solve_with_one_arg(void);

#endif