#include "c_minded.h"

void	fill_struct(char *first_line, t_map_info *info)
{
	int		length;

	length = ft_strlen(first_line);
	info->empty = first_line[length - 3];
	info->obstacle = first_line[length - 2];
	info->full = first_line[length - 1];
}

char	*fill_and_start(char	**result, t_map_info info, char *str)
{
	char		*first_line;

	first_line = get_first_line(str);
	fill_struct(first_line, &info);
	start_solve(result, get_number_in_first_line(first_line),
		get_number_of_columns(str), info);
	return (first_line);
}

void	create_new_file(void)
{
	char	*buf;
	int		len;
	int		fd;
	int		bytes;

	buf = malloc(4096);
	if (!buf)
		return ;
	len = 0;
	bytes = 1;
	while (bytes > 0 && len < 4096 - 1)
	{
		bytes = read(0, buf + len, 4096 - len - 1);
		if (bytes > 0)
			len += bytes;
	}
	buf[len] = '\0';
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd >= 0)
	{
		write(fd, buf, len);
		close(fd);
	}
	free(buf);
}

void	main_solver(char **result, t_map_info	info, char *str)
{
	result = validate_inputs(str);
	if (result)
	{
		fill_and_start(result, info, str);
		ft_free(result, get_number_in_first_line
			(get_first_line(str)));
		write(1, "\n", 1);
	}
	else
		write(2, "map error\n", 10);
}

int	main(int argc, char **argv)
{
	int			i;
	char		**result;
	t_map_info	info;

	i = 1;
	result = NULL;
	if (argc == 1)
	{
		create_new_file();
		main_solver(result, info, "output.txt");
	}
	else
	{
		while (i < argc)
		{
			main_solver(result, info, argv[i]);
			i++;
		}
	}
	return (0);
}
