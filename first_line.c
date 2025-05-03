#include "c_minded.h"

int	get_number_of_columns(char *path)
{
	int		fd;
	char	buffer;
	int		count;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &buffer, 1) > 0)
		if (buffer == '\n')
			break ;
	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
		count++;
	close(fd);
	return (count);
}

void	skip_first_line(int fd)
{
	char	buffer;

	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
	{
	}
}

char	**ft_fill_result(int fd, char **result, int cols)
{
	int		i;
	int		x;
	char	buffer;

	i = 0;
	x = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
		{
			result[i][x] = '\0';
			i++;
			x = 0;
		}
		else if (x < cols)
			result[i][x++] = buffer;
	}
	result[i][x] = '\0';
	close(fd);
	return (result);
}

char	**ft_get_inputs(char *path, int count_lines)
{
	int		i;
	char	**result;
	int		fd;
	int		cols;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	cols = get_number_of_columns(path);
	result = (char **)malloc((count_lines + 1) * sizeof(char *));
	if (!result)
		return (close(fd), NULL);
	i = 0;
	while (i < count_lines)
	{
		result[i] = (char *)malloc(cols + 1);
		if (!result[i])
			return (ft_free(result, i), close(fd), NULL);
		i++;
	}
	result[i] = NULL;
	skip_first_line(fd);
	return (ft_fill_result(fd, result, cols));
}

int	get_nb_of_rows(int fd)
{
	int		count;
	char	buffer;

	count = 0;
	while (read(fd, &buffer, 1) > 0)
		if (buffer == '\n')
			count++;
	return (count);
}
